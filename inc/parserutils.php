<?php
/**
 * Utilities for accessing the parser
 *
 * @license    GPL 2 (http://www.gnu.org/licenses/gpl.html)
 * @author     Harry Fuecks <hfuecks@gmail.com>
 * @author     Andreas Gohr <andi@splitbrain.org>
 */

if(!defined('DOKU_INC')) die('meh.');

/**
 * How many pages shall be rendered for getting metadata during one request
 * at maximum? Note that this limit isn't respected when METADATA_RENDER_UNLIMITED
 * is passed as render parameter to p_get_metadata.
 */
if (!defined('P_GET_METADATA_RENDER_LIMIT')) define('P_GET_METADATA_RENDER_LIMIT', 5);

/** Don't render metadata even if it is outdated or doesn't exist */
define('METADATA_DONT_RENDER', 0);
/**
 * Render metadata when the page is really newer or the metadata doesn't exist.
 * Uses just a simple check, but should work pretty well for loading simple
 * metadata values like the page title and avoids rendering a lot of pages in
 * one request. The P_GET_METADATA_RENDER_LIMIT is used in this mode.
 * Use this if it is unlikely that the metadata value you are requesting
 * does depend e.g. on pages that are included in the current page using
 * the include plugin (this is very likely the case for the page title, but
 * not for relation references).
 */
define('METADATA_RENDER_USING_SIMPLE_CACHE', 1);
/**
 * Render metadata using the metadata cache logic. The P_GET_METADATA_RENDER_LIMIT
 * is used in this mode. Use this mode when you are requesting more complex
 * metadata. Although this will cause rendering more often it might actually have
 * the effect that less current metadata is returned as it is more likely than in
 * the simple cache mode that metadata needs to be rendered for all pages at once
 * which means that when the metadata for the page is requested that actually needs
 * to be updated the limit might have been reached already.
 */
define('METADATA_RENDER_USING_CACHE', 2);
/**
 * Render metadata without limiting the number of pages for which metadata is
 * rendered. Use this mode with care, normally it should only be used in places
 * like the indexer or in cli scripts where the execution time normally isn't
 * limited. This can be combined with the simple cache using
 * METADATA_RENDER_USING_CACHE | METADATA_RENDER_UNLIMITED.
 */
define('METADATA_RENDER_UNLIMITED', 4);

/**
 * Returns the parsed Wikitext in XHTML for the given id and revision.
 *
 * If $excuse is true an explanation is returned if the file
 * wasn't found
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function p_wiki_xhtml($id, $rev='', $excuse=true){
    $file = wikiFN($id,$rev);
    $ret  = '';

    //ensure $id is in global $ID (needed for parsing)
    global $ID;
    $keep = $ID;
    $ID   = $id;

    if($rev){
        if(@file_exists($file)){
            $ret = p_render('xhtml',p_get_instructions(io_readWikiPage($file,$id,$rev)),$info); //no caching on old revisions
        }elseif($excuse){
            $ret = p_locale_xhtml('norev');
        }
    }else{
        if(@file_exists($file)){
            $ret = p_cached_output($file,'xhtml',$id);
        }elseif($excuse){
            $ret = p_locale_xhtml('newpage');
        }
    }

    //restore ID (just in case)
    $ID = $keep;

    return $ret;
}

/**
 * Returns starting summary for a page (e.g. the first few
 * paragraphs), marked up in XHTML.
 *
 * If $excuse is true an explanation is returned if the file
 * wasn't found
 *
 * @param string wiki page id
 * @param reference populated with page title from heading or page id
 * @deprecated
 * @author Harry Fuecks <hfuecks@gmail.com>
 */
function p_wiki_xhtml_summary($id, &$title, $rev='', $excuse=true){
    $file = wikiFN($id,$rev);
    $ret  = '';

    //ensure $id is in global $ID (needed for parsing)
    global $ID;
    $keep = $ID;
    $ID   = $id;

    if($rev){
        if(@file_exists($file)){
            //no caching on old revisions
            $ins = p_get_instructions(io_readWikiPage($file,$id,$rev));
        }elseif($excuse){
            $ret = p_locale_xhtml('norev');
            //restore ID (just in case)
            $ID = $keep;
            return $ret;
        }

    }else{

        if(@file_exists($file)){
            // The XHTML for a summary is not cached so use the instruction cache
            $ins = p_cached_instructions($file);
        }elseif($excuse){
            $ret = p_locale_xhtml('newpage');
            //restore ID (just in case)
            $ID = $keep;
            return $ret;
        }
    }

    $ret = p_render('xhtmlsummary',$ins,$info);

    if ( $info['sum_pagetitle'] ) {
        $title = $info['sum_pagetitle'];
    } else {
        $title = $id;
    }

    $ID = $keep;
    return $ret;
}

/**
 * Returns the specified local text in parsed format
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function p_locale_xhtml($id){
    //fetch parsed locale
    $html = p_cached_output(localeFN($id));
    return $html;
}

/**
 *     *** DEPRECATED ***
 *
 * use p_cached_output()
 *
 * Returns the given file parsed to XHTML
 *
 * Uses and creates a cachefile
 *
 * @deprecated
 * @author Andreas Gohr <andi@splitbrain.org>
 * @todo   rewrite to use mode instead of hardcoded XHTML
 */
function p_cached_xhtml($file){
    return p_cached_output($file);
}

/**
 * Returns the given file parsed into the requested output format
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 * @author Chris Smith <chris@jalakai.co.uk>
 */
function p_cached_output($file, $format='xhtml', $id='') {
    global $conf;

    $cache = new cache_renderer($id, $file, $format);
    if ($cache->useCache()) {
        $parsed = $cache->retrieveCache(false);
        if($conf['allowdebug'] && $format=='xhtml') $parsed .= "\n<!-- cachefile {$cache->cache} used -->\n";
    } else {
        $parsed = p_render($format, p_cached_instructions($file,false,$id), $info);

        if ($info['cache']) {
            $cache->storeCache($parsed);               //save cachefile
            if($conf['allowdebug'] && $format=='xhtml') $parsed .= "\n<!-- no cachefile used, but created {$cache->cache} -->\n";
        }else{
            $cache->removeCache();                     //try to delete cachefile
            if($conf['allowdebug'] && $format=='xhtml') $parsed .= "\n<!-- no cachefile used, caching forbidden -->\n";
        }
    }

    return $parsed;
}

/**
 * Returns the render instructions for a file
 *
 * Uses and creates a serialized cache file
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function p_cached_instructions($file,$cacheonly=false,$id='') {
    global $conf;
    static $run = null;
    if(is_null($run)) $run = array();

    $cache = new cache_instructions($id, $file);

    if ($cacheonly || $cache->useCache() || isset($run[$file])) {
        return $cache->retrieveCache();
    } else if (@file_exists($file)) {
        // no cache - do some work
        $ins = p_get_instructions(io_readWikiPage($file,$id));
        if ($cache->storeCache($ins)) {
            $run[$file] = true; // we won't rebuild these instructions in the same run again
        } else {
            msg('Unable to save cache file. Hint: disk full; file permissions; safe_mode setting.',-1);
        }
        return $ins;
    }

    return null;
}

/**
 * turns a page into a list of instructions
 *
 * @author Harry Fuecks <hfuecks@gmail.com>
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function p_get_instructions($text){

    $modes = p_get_parsermodes();

    // Create the parser
    $Parser = new Doku_Parser();

    // Add the Handler
    $Parser->Handler = new Doku_Handler();

    //add modes to parser
    foreach($modes as $mode){
        $Parser->addMode($mode['mode'],$mode['obj']);
    }

    // Do the parsing
    trigger_event('PARSER_WIKITEXT_PREPROCESS', $text);
    $p = $Parser->parse($text);
    //  dbg($p);
    return $p;
}

/**
 * returns the metadata of a page
 *
 * @param string $id The id of the page the metadata should be returned from
 * @param string $key The key of the metdata value that shall be read (by default everything) - separate hierarchies by " " like "date created"
 * @param int $render If the page should be rendererd - possible values:
 *     METADATA_DONT_RENDER, METADATA_RENDER_USING_SIMPLE_CACHE, METADATA_RENDER_USING_CACHE
 *     METADATA_RENDER_UNLIMITED (also combined with the previous two options),
 *     default: METADATA_RENDER_USING_CACHE
 * @return mixed The requested metadata fields
 *
 * @author Esther Brunner <esther@kaffeehaus.ch>
 * @author Michael Hamann <michael@content-space.de>
 */
function p_get_metadata($id, $key='', $render=METADATA_RENDER_USING_CACHE){
    global $ID;
    static $render_count = 0;
    // track pages that have already been rendered in order to avoid rendering the same page
    // again
    static $rendered_pages = array();

    // cache the current page
    // Benchmarking shows the current page's metadata is generally the only page metadata
    // accessed several times. This may catch a few other pages, but that shouldn't be an issue.
    $cache = ($ID == $id);
    $meta = p_read_metadata($id, $cache);

    if (!is_numeric($render)) {
        if ($render) {
            $render = METADATA_RENDER_USING_SIMPLE_CACHE;
        } else {
            $render = METADATA_DONT_RENDER;
        }
    }

    // prevent recursive calls in the cache
    static $recursion = false;
    if (!$recursion && $render != METADATA_DONT_RENDER && !isset($rendered_pages[$id])&& page_exists($id)){
        $recursion = true;

        $cachefile = new cache_renderer($id, wikiFN($id), 'metadata');

        $do_render = false;
        if ($render & METADATA_RENDER_UNLIMITED || $render_count < P_GET_METADATA_RENDER_LIMIT) {
            if ($render & METADATA_RENDER_USING_SIMPLE_CACHE) {
                $pagefn = wikiFN($id);
                $metafn = metaFN($id, '.meta');
                if (!@file_exists($metafn) || @filemtime($pagefn) > @filemtime($cachefile->cache)) {
                    $do_render = true;
                }
            } elseif (!$cachefile->useCache()){
                $do_render = true;
            }
        }
        if ($do_render) {
            ++$render_count;
            $rendered_pages[$id] = true;
            $old_meta = $meta;
            $meta = p_render_metadata($id, $meta);
            // only update the file when the metadata has been changed
            if ($meta == $old_meta || p_save_metadata($id, $meta)) {
                // store a timestamp in order to make sure that the cachefile is touched
                $cachefile->storeCache(time());
            } elseif ($meta != $old_meta) {
                msg('Unable to save metadata file. Hint: disk full; file permissions; safe_mode setting.',-1);
            }
        }

        $recursion = false;
    }

    $val = $meta['current'];

    // filter by $key
    foreach(preg_split('/\s+/', $key, 2, PREG_SPLIT_NO_EMPTY) as $cur_key) {
        if (!isset($val[$cur_key])) {
            return null;
        }
        $val = $val[$cur_key];
    }
    return $val;
}

/**
 * sets metadata elements of a page
 *
 * @see http://www.dokuwiki.org/devel:metadata#functions_to_get_and_set_metadata
 *
 * @param String  $id         is the ID of a wiki page
 * @param Array   $data       is an array with key ⇒ value pairs to be set in the metadata
 * @param Boolean $render     whether or not the page metadata should be generated with the renderer
 * @param Boolean $persistent indicates whether or not the particular metadata value will persist through
 *                            the next metadata rendering.
 * @return boolean true on success
 *
 * @author Esther Brunner <esther@kaffeehaus.ch>
 * @author Michael Hamann <michael@content-space.de>
 */
function p_set_metadata($id, $data, $render=false, $persistent=true){
    if (!is_array($data)) return false;

    global $ID, $METADATA_RENDERERS;

    // if there is currently a renderer change the data in the renderer instead
    if (isset($METADATA_RENDERERS[$id])) {
        $orig =& $METADATA_RENDERERS[$id];
        $meta = $orig;
    } else {
        // cache the current page
        $cache = ($ID == $id);
        $orig = p_read_metadata($id, $cache);

        // render metadata first?
        $meta = $render ? p_render_metadata($id, $orig) : $orig;
    }

    // now add the passed metadata
    $protected = array('description', 'date', 'contributor');
    foreach ($data as $key => $value){

        // be careful with sub-arrays of $meta['relation']
        if ($key == 'relation'){

            foreach ($value as $subkey => $subvalue){
                $meta['current'][$key][$subkey] = !empty($meta['current'][$key][$subkey]) ? array_merge($meta['current'][$key][$subkey], $subvalue) : $subvalue;
                if ($persistent)
                    $meta['persistent'][$key][$subkey] = !empty($meta['persistent'][$key][$subkey]) ? array_merge($meta['persistent'][$key][$subkey], $subvalue) : $subvalue;
            }

            // be careful with some senisitive arrays of $meta
        } elseif (in_array($key, $protected)){

            // these keys, must have subkeys - a legitimate value must be an array
            if (is_array($value)) {
                $meta['current'][$key] = !empty($meta['current'][$key]) ? array_merge($meta['current'][$key],$value) : $value;

                if ($persistent) {
                    $meta['persistent'][$key] = !empty($meta['persistent'][$key]) ? array_merge($meta['persistent'][$key],$value) : $value;
                }
            }

            // no special treatment for the rest
        } else {
            $meta['current'][$key] = $value;
            if ($persistent) $meta['persistent'][$key] = $value;
        }
    }

    // save only if metadata changed
    if ($meta == $orig) return true;

    if (isset($METADATA_RENDERERS[$id])) {
        // set both keys individually as the renderer has references to the individual keys
        $METADATA_RENDERERS[$id]['current']    = $meta['current'];
        $METADATA_RENDERERS[$id]['persistent'] = $meta['persistent'];
        return true;
    } else {
        return p_save_metadata($id, $meta);
    }
}

/**
 * Purges the non-persistant part of the meta data
 * used on page deletion
 *
 * @author Michael Klier <chi@chimeric.de>
 */
function p_purge_metadata($id) {
    $meta = p_read_metadata($id);
    foreach($meta['current'] as $key => $value) {
        if(is_array($meta[$key])) {
            $meta['current'][$key] = array();
        } else {
            $meta['current'][$key] = '';
        }

    }
    return p_save_metadata($id, $meta);
}

/**
 * read the metadata from source/cache for $id
 * (internal use only - called by p_get_metadata & p_set_metadata)
 *
 * @author   Christopher Smith <chris@jalakai.co.uk>
 *
 * @param    string   $id      absolute wiki page id
 * @param    bool     $cache   whether or not to cache metadata in memory
 *                             (only use for metadata likely to be accessed several times)
 *
 * @return   array             metadata
 */
function p_read_metadata($id,$cache=false) {
    global $cache_metadata;

    if (isset($cache_metadata[(string)$id])) return $cache_metadata[(string)$id];

    $file = metaFN($id, '.meta');
    $meta = @file_exists($file) ? unserialize(io_readFile($file, false)) : array('current'=>array(),'persistent'=>array());

    if ($cache) {
        $cache_metadata[(string)$id] = $meta;
    }

    return $meta;
}

/**
 * This is the backend function to save a metadata array to a file
 *
 * @param    string   $id      absolute wiki page id
 * @param    array    $meta    metadata
 *
 * @return   bool              success / fail
 */
function p_save_metadata($id, $meta) {
    // sync cached copies, including $INFO metadata
    global $cache_metadata, $INFO;

    if (isset($cache_metadata[$id])) $cache_metadata[$id] = $meta;
    if (!empty($INFO) && ($id == $INFO['id'])) { $INFO['meta'] = $meta['current']; }

    return io_saveFile(metaFN($id, '.meta'), serialize($meta));
}

/**
 * renders the metadata of a page
 *
 * @author Esther Brunner <esther@kaffeehaus.ch>
 */
function p_render_metadata($id, $orig){
    // make sure the correct ID is in global ID
    global $ID, $METADATA_RENDERERS;

    // avoid recursive rendering processes for the same id
    if (isset($METADATA_RENDERERS[$id]))
        return $orig;

    // store the original metadata in the global $METADATA_RENDERERS so p_set_metadata can use it
    $METADATA_RENDERERS[$id] =& $orig;

    $keep = $ID;
    $ID   = $id;

    // add an extra key for the event - to tell event handlers the page whose metadata this is
    $orig['page'] = $id;
    $evt = new Doku_Event('PARSER_METADATA_RENDER', $orig);
    if ($evt->advise_before()) {

        require_once DOKU_INC."inc/parser/metadata.php";

        // get instructions
        $instructions = p_cached_instructions(wikiFN($id),false,$id);
        if(is_null($instructions)){
            $ID = $keep;
            unset($METADATA_RENDERERS[$id]);
            return null; // something went wrong with the instructions
        }

        // set up the renderer
        $renderer = new Doku_Renderer_metadata();
        $renderer->meta =& $orig['current'];
        $renderer->persistent =& $orig['persistent'];

        // loop through the instructions
        foreach ($instructions as $instruction){
            // execute the callback against the renderer
            call_user_func_array(array(&$renderer, $instruction[0]), (array) $instruction[1]);
        }

        $evt->result = array('current'=>&$renderer->meta,'persistent'=>&$renderer->persistent);
    }
    $evt->advise_after();

    // clean up
    $ID = $keep;
    unset($METADATA_RENDERERS[$id]);
    return $evt->result;
}

/**
 * returns all available parser syntax modes in correct order
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function p_get_parsermodes(){
    global $conf;

    //reuse old data
    static $modes = null;
    if($modes != null){
        return $modes;
    }

    //import parser classes and mode definitions
    require_once DOKU_INC . 'inc/parser/parser.php';

    // we now collect all syntax modes and their objects, then they will
    // be sorted and added to the parser in correct order
    $modes = array();

    // add syntax plugins
    $pluginlist = plugin_list('syntax');
    if(count($pluginlist)){
        global $PARSER_MODES;
        $obj = null;
        foreach($pluginlist as $p){
            if(!$obj =& plugin_load('syntax',$p)) continue; //attempt to load plugin into $obj
            $PARSER_MODES[$obj->getType()][] = "plugin_$p"; //register mode type
            //add to modes
            $modes[] = array(
                    'sort' => $obj->getSort(),
                    'mode' => "plugin_$p",
                    'obj'  => $obj,
                    );
            unset($obj); //remove the reference
        }
    }

    // add default modes
    $std_modes = array('listblock','preformatted','notoc','nocache',
            'header','table','linebreak','footnote','hr',
            'unformatted','php','html','code','file','quote',
            'internallink','rss','media','externallink',
            'emaillink','windowssharelink','eol');
    if($conf['typography']){
        $std_modes[] = 'quotes';
        $std_modes[] = 'multiplyentity';
    }
    foreach($std_modes as $m){
        $class = "Doku_Parser_Mode_$m";
        $obj   = new $class();
        $modes[] = array(
                'sort' => $obj->getSort(),
                'mode' => $m,
                'obj'  => $obj
                );
    }

    // add formatting modes
    $fmt_modes = array('strong','emphasis','underline','monospace',
            'subscript','superscript','deleted');
    foreach($fmt_modes as $m){
        $obj   = new Doku_Parser_Mode_formatting($m);
        $modes[] = array(
                'sort' => $obj->getSort(),
                'mode' => $m,
                'obj'  => $obj
                );
    }

    // add modes which need files
    $obj     = new Doku_Parser_Mode_smiley(array_keys(getSmileys()));
    $modes[] = array('sort' => $obj->getSort(), 'mode' => 'smiley','obj'  => $obj );
    $obj     = new Doku_Parser_Mode_acronym(array_keys(getAcronyms()));
    $modes[] = array('sort' => $obj->getSort(), 'mode' => 'acronym','obj'  => $obj );
    $obj     = new Doku_Parser_Mode_entity(array_keys(getEntities()));
    $modes[] = array('sort' => $obj->getSort(), 'mode' => 'entity','obj'  => $obj );

    // add optional camelcase mode
    if($conf['camelcase']){
        $obj     = new Doku_Parser_Mode_camelcaselink();
        $modes[] = array('sort' => $obj->getSort(), 'mode' => 'camelcaselink','obj'  => $obj );
    }

    //sort modes
    usort($modes,'p_sort_modes');

    return $modes;
}

/**
 * Callback function for usort
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function p_sort_modes($a, $b){
    if($a['sort'] == $b['sort']) return 0;
    return ($a['sort'] < $b['sort']) ? -1 : 1;
}

/**
 * Renders a list of instruction to the specified output mode
 *
 * In the $info array is information from the renderer returned
 *
 * @author Harry Fuecks <hfuecks@gmail.com>
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function p_render($mode,$instructions,&$info){
    if(is_null($instructions)) return '';

    $Renderer =& p_get_renderer($mode);
    if (is_null($Renderer)) return null;

    $Renderer->reset();

    $Renderer->smileys = getSmileys();
    $Renderer->entities = getEntities();
    $Renderer->acronyms = getAcronyms();
    $Renderer->interwiki = getInterwiki();

    // Loop through the instructions
    foreach ( $instructions as $instruction ) {
        // Execute the callback against the Renderer
        call_user_func_array(array(&$Renderer, $instruction[0]),$instruction[1]);
    }

    //set info array
    $info = $Renderer->info;

    // Post process and return the output
    $data = array($mode,& $Renderer->doc);
    trigger_event('RENDERER_CONTENT_POSTPROCESS',$data);
    return $Renderer->doc;
}

function & p_get_renderer($mode) {
    global $conf, $plugin_controller;

    $rname = !empty($conf['renderer_'.$mode]) ? $conf['renderer_'.$mode] : $mode;
    $rclass = "Doku_Renderer_$rname";

    if( class_exists($rclass) ) {
        return new $rclass();
    }

    // try default renderer first:
    $file = DOKU_INC."inc/parser/$rname.php";
    if(@file_exists($file)){
        require_once $file;

        if ( !class_exists($rclass) ) {
            trigger_error("Unable to resolve render class $rclass",E_USER_WARNING);
            msg("Renderer '$rname' for $mode not valid",-1);
            return null;
        }
        $Renderer = new $rclass();
    }else{
        // Maybe a plugin/component is available?
        list($plugin, $component) = $plugin_controller->_splitName($rname);
        if (!$plugin_controller->isdisabled($plugin)){
            $Renderer =& $plugin_controller->load('renderer',$rname);
        }

        if(is_null($Renderer)){
            msg("No renderer '$rname' found for mode '$mode'",-1);
            return null;
        }
    }

    return $Renderer;
}

/**
 * Gets the first heading from a file
 *
 * @param   string   $id       dokuwiki page id
 * @param   int      $render   rerender if first heading not known
 *                             default: METADATA_RENDER_USING_SIMPLE_CACHE
 *                             Possible values: METADATA_DONT_RENDER,
 *                                              METADATA_RENDER_USING_SIMPLE_CACHE,
 *                                              METADATA_RENDER_USING_CACHE,
 *                                              METADATA_RENDER_UNLIMITED
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 * @author Michael Hamann <michael@content-space.de>
 */
function p_get_first_heading($id, $render=METADATA_RENDER_USING_SIMPLE_CACHE){
    return p_get_metadata(cleanID($id),'title',$render);
}

/**
 * Wrapper for GeSHi Code Highlighter, provides caching of its output
 *
 * @param  string   $code       source code to be highlighted
 * @param  string   $language   language to provide highlighting
 * @param  string   $wrapper    html element to wrap the returned highlighted text
 *
 * @author Christopher Smith <chris@jalakai.co.uk>
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function p_xhtml_cached_geshi($code, $language, $wrapper='pre') {
    global $conf, $config_cascade;
    $language = strtolower($language);

    // remove any leading or trailing blank lines
    $code = preg_replace('/^\s*?\n|\s*?\n$/','',$code);

    $cache = getCacheName($language.$code,".code");
    $ctime = @filemtime($cache);
    if($ctime && !$_REQUEST['purge'] &&
            $ctime > filemtime(DOKU_INC.'inc/geshi.php') &&                 // geshi changed
            $ctime > @filemtime(DOKU_INC.'inc/geshi/'.$language.'.php') &&  // language syntax definition changed
            $ctime > filemtime(reset($config_cascade['main']['default']))){ // dokuwiki changed
        $highlighted_code = io_readFile($cache, false);

    } else {

        $geshi = new GeSHi($code, $language, DOKU_INC . 'inc/geshi');
        $geshi->set_encoding('utf-8');
        $geshi->enable_classes();
        $geshi->set_header_type(GESHI_HEADER_PRE);
        $geshi->set_link_target($conf['target']['extern']);

        // remove GeSHi's wrapper element (we'll replace it with our own later)
        // we need to use a GeSHi wrapper to avoid <BR> throughout the highlighted text
        $highlighted_code = trim(preg_replace('!^<pre[^>]*>|</pre>$!','',$geshi->parse_code()),"\n\r");
        io_saveFile($cache,$highlighted_code);
    }

    // add a wrapper element if required
    if ($wrapper) {
        return "<$wrapper class=\"code $language\">$highlighted_code</$wrapper>";
    } else {
        return $highlighted_code;
    }
}

