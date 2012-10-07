<?php
/**
 * DokuWiki JavaScript creator
 *
 * @license    GPL 2 (http://www.gnu.org/licenses/gpl.html)
 * @author     Andreas Gohr <andi@splitbrain.org>
 */

if(!defined('DOKU_INC')) define('DOKU_INC',dirname(__FILE__).'/../../');
if(!defined('NOSESSION')) define('NOSESSION',true); // we do not use a session or authentication here (better caching)
if(!defined('NL')) define('NL',"\n");
if(!defined('DOKU_DISABLE_GZIP_OUTPUT')) define('DOKU_DISABLE_GZIP_OUTPUT',1); // we gzip ourself here
require_once(DOKU_INC.'inc/init.php');

// Main (don't run when UNIT test)
if(!defined('SIMPLE_TEST')){
    header('Content-Type: text/javascript; charset=utf-8');
    js_out();
}


// ---------------------- functions ------------------------------

/**
 * Output all needed JavaScript
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function js_out(){
    global $conf;
    global $lang;
    global $config_cascade;

    // The generated script depends on some dynamic options
    $cache = new cache('scripts'.$_SERVER['HTTP_HOST'].$_SERVER['SERVER_PORT'],
                       '.js');

    // load minified version for some files
    $min = $conf['compress'] ? '.min' : '';

    // array of core files
    $files = array(
                DOKU_INC."lib/scripts/jquery/jquery$min.js",
                DOKU_INC.'lib/scripts/jquery/jquery.cookie.js',
                DOKU_INC."lib/scripts/jquery/jquery-ui$min.js",
                DOKU_INC."lib/scripts/fileuploader.js",
                DOKU_INC."lib/scripts/fileuploaderextended.js",
                DOKU_INC.'lib/scripts/helpers.js',
                DOKU_INC.'lib/scripts/delay.js',
                DOKU_INC.'lib/scripts/cookie.js',
                DOKU_INC.'lib/scripts/script.js',
                DOKU_INC.'lib/scripts/tw-sack.js',
                DOKU_INC.'lib/scripts/qsearch.js',
                DOKU_INC.'lib/scripts/tree.js',
                DOKU_INC.'lib/scripts/index.js',
                DOKU_INC.'lib/scripts/drag.js',
                DOKU_INC.'lib/scripts/textselection.js',
                DOKU_INC.'lib/scripts/toolbar.js',
                DOKU_INC.'lib/scripts/edit.js',
                DOKU_INC.'lib/scripts/editor.js',
                DOKU_INC.'lib/scripts/locktimer.js',
                DOKU_INC.'lib/scripts/linkwiz.js',
                DOKU_INC.'lib/scripts/media.js',
                DOKU_INC.'lib/scripts/compatibility.js',
# disabled for FS#1958                DOKU_INC.'lib/scripts/hotkeys.js',
                DOKU_INC.'lib/scripts/behaviour.js',
                DOKU_INC.'lib/scripts/page.js',
                DOKU_TPLINC.'script.js',
            );

    // add possible plugin scripts and userscript
    $files   = array_merge($files,js_pluginscripts());
    if(isset($config_cascade['userscript']['default'])){
        $files[] = $config_cascade['userscript']['default'];
    }

    $cache_files = array_merge($files, getConfigFiles('main'));
    $cache_files[] = __FILE__;

    // check cache age & handle conditional request
    // This may exit if a cache can be used
    http_cached($cache->cache,
                $cache->useCache(array('files' => $cache_files)));

    // start output buffering and build the script
    ob_start();

    // add some global variables
    print "var DOKU_BASE   = '".DOKU_BASE."';";
    print "var DOKU_TPL    = '".DOKU_TPL."';";
    // FIXME: Move those to JSINFO
    print "var DOKU_UHN    = ".((int) useHeading('navigation')).";";
    print "var DOKU_UHC    = ".((int) useHeading('content')).";";

    // load JS specific translations
    $json = new JSON();
    $lang['js']['plugins'] = js_pluginstrings();
    echo 'LANG = '.$json->encode($lang['js']).";\n";

    // load toolbar
    toolbar_JSdefines('toolbar');

    // load files
    foreach($files as $file){
        echo "\n\n/* XXXXXXXXXX begin of ".str_replace(DOKU_INC, '', $file) ." XXXXXXXXXX */\n\n";
        js_load($file);
        echo "\n\n/* XXXXXXXXXX end of " . str_replace(DOKU_INC, '', $file) . " XXXXXXXXXX */\n\n";
    }

    // init stuff
    if($conf['locktime'] != 0){
        js_runonstart("dw_locktimer.init(".($conf['locktime'] - 60).",".$conf['usedraft'].")");
    }
    // init hotkeys - must have been done after init of toolbar
# disabled for FS#1958    js_runonstart('initializeHotkeys()');

    // end output buffering and get contents
    $js = ob_get_contents();
    ob_end_clean();

    // compress whitespace and comments
    if($conf['compress']){
        $js = js_compress($js);
    }

    $js .= "\n"; // https://bugzilla.mozilla.org/show_bug.cgi?id=316033

    http_cached_finish($cache->cache, $js);
}

/**
 * Load the given file, handle include calls and print it
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function js_load($file){
    if(!@file_exists($file)) return;
    static $loaded = array();

    $data = io_readFile($file);
    while(preg_match('#/\*\s*DOKUWIKI:include(_once)?\s+([\w\.\-_/]+)\s*\*/#',$data,$match)){
        $ifile = $match[2];

        // is it a include_once?
        if($match[1]){
            $base = basename($ifile);
            if($loaded[$base]) continue;
            $loaded[$base] = true;
        }

        if($ifile{0} != '/') $ifile = dirname($file).'/'.$ifile;

        if(@file_exists($ifile)){
            $idata = io_readFile($ifile);
        }else{
            $idata = '';
        }
        $data  = str_replace($match[0],$idata,$data);
    }
    echo "$data\n";
}

/**
 * Returns a list of possible Plugin Scripts (no existance check here)
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function js_pluginscripts(){
    $list = array();
    $plugins = plugin_list();
    foreach ($plugins as $p){
        $list[] = DOKU_PLUGIN."$p/script.js";
    }
    return $list;
}

/**
 * Return an two-dimensional array with strings from the language file of each plugin.
 *
 * - $lang['js'] must be an array.
 * - Nothing is returned for plugins without an entry for $lang['js']
 *
 * @author Gabriel Birke <birke@d-scribe.de>
 */
function js_pluginstrings()
{
    global $conf;
    $pluginstrings = array();
    $plugins = plugin_list();
    foreach ($plugins as $p){
        if (isset($lang)) unset($lang);
        if (@file_exists(DOKU_PLUGIN."$p/lang/en/lang.php")) {
            include DOKU_PLUGIN."$p/lang/en/lang.php";
        }
        if (isset($conf['lang']) && $conf['lang']!='en' && @file_exists(DOKU_PLUGIN."$p/lang/".$conf['lang']."/lang.php")) {
            include DOKU_PLUGIN."$p/lang/".$conf['lang']."/lang.php";
        }
        if (isset($lang['js'])) {
            $pluginstrings[$p] = $lang['js'];
        }
    }
    return $pluginstrings;
}

/**
 * Escapes a String to be embedded in a JavaScript call, keeps \n
 * as newline
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function js_escape($string){
    return str_replace('\\\\n','\\n',addslashes($string));
}

/**
 * Adds the given JavaScript code to the window.onload() event
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */
function js_runonstart($func){
    echo "jQuery(function(){ $func; });".NL;
}

/**
 * Strip comments and whitespaces from given JavaScript Code
 *
 * This is a port of Nick Galbreath's python tool jsstrip.py which is
 * released under BSD license. See link for original code.
 *
 * @author Nick Galbreath <nickg@modp.com>
 * @author Andreas Gohr <andi@splitbrain.org>
 * @link   http://code.google.com/p/jsstrip/
 */
function js_compress($s){
    $s = ltrim($s);     // strip all initial whitespace
    $s .= "\n";
    $i = 0;             // char index for input string
    $j = 0;             // char forward index for input string
    $line = 0;          // line number of file (close to it anyways)
    $slen = strlen($s); // size of input string
    $lch  = '';         // last char added
    $result = '';       // we store the final result here

    // items that don't need spaces next to them
    $chars = "^&|!+\-*\/%=\?:;,{}()<>% \t\n\r'\"[]";

    $regex_starters = array("(", "=", "[", "," , ":", "!");

    $whitespaces_chars = array(" ", "\t", "\n", "\r", "\0", "\x0B");

    while($i < $slen){
        // skip all "boring" characters.  This is either
        // reserved word (e.g. "for", "else", "if") or a
        // variable/object/method (e.g. "foo.color")
        while ($i < $slen && (strpos($chars,$s[$i]) === false) ){
            $result .= $s{$i};
            $i = $i + 1;
        }

        $ch = $s{$i};
        // multiline comments (keeping IE conditionals)
        if($ch == '/' && $s{$i+1} == '*' && $s{$i+2} != '@'){
            $endC = strpos($s,'*/',$i+2);
            if($endC === false) trigger_error('Found invalid /*..*/ comment', E_USER_ERROR);
            $i = $endC + 2;
            continue;
        }

        // singleline
        if($ch == '/' && $s{$i+1} == '/'){
            $endC = strpos($s,"\n",$i+2);
            if($endC === false) trigger_error('Invalid comment', E_USER_ERROR);
            $i = $endC;
            continue;
        }

        // tricky.  might be an RE
        if($ch == '/'){
            // rewind, skip white space
            $j = 1;
            while(in_array($s{$i-$j}, $whitespaces_chars)){
                $j = $j + 1;
            }
            if( in_array($s{$i-$j}, $regex_starters) ){
                // yes, this is an re
                // now move forward and find the end of it
                $j = 1;
                while($s{$i+$j} != '/'){
                    while( ($s{$i+$j} != '\\') && ($s{$i+$j} != '/')){
                        $j = $j + 1;
                    }
                    if($s{$i+$j} == '\\') $j = $j + 2;
                }
                $result .= substr($s,$i,$j+1);
                $i = $i + $j + 1;
                continue;
            }
        }

        // double quote strings
        if($ch == '"'){
            $j = 1;
            while( $s{$i+$j} != '"' && ($i+$j < $slen)){
                if( $s{$i+$j} == '\\' && ($s{$i+$j+1} == '"' || $s{$i+$j+1} == '\\') ){
                    $j += 2;
                }else{
                    $j += 1;
                }
            }
            $result .= substr($s,$i,$j+1);
            $i = $i + $j + 1;
            continue;
        }

        // single quote strings
        if($ch == "'"){
            $j = 1;
            while( $s{$i+$j} != "'" && ($i+$j < $slen)){
                if( $s{$i+$j} == '\\' && ($s{$i+$j+1} == "'" || $s{$i+$j+1} == '\\') ){
                    $j += 2;
                }else{
                    $j += 1;
                }
            }
            $result .= substr($s,$i,$j+1);
            $i = $i + $j + 1;
            continue;
        }

        // whitespaces
        if( $ch == ' ' || $ch == "\r" || $ch == "\n" || $ch == "\t" ){
            // leading spaces
            if($i+1 < $slen && (strpos($chars,$s[$i+1]) !== false)){
                $i = $i + 1;
                continue;
            }
            // trailing spaces
            //  if this ch is space AND the last char processed
            //  is special, then skip the space
            $lch = substr($result,-1);
            if($lch && (strpos($chars,$lch) !== false)){
                $i = $i + 1;
                continue;
            }
            // else after all of this convert the "whitespace" to
            // a single space.  It will get appended below
            $ch = ' ';
        }

        // other chars
        $result .= $ch;
        $i = $i + 1;
    }

    return trim($result);
}

//Setup VIM: ex: et ts=4 :
