<?php
/**
 * Load all internal libraries and setup class autoloader
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 */

// setup class autoloader
spl_autoload_register('load_autoload');

// require all the common libraries
// for a few of these order does matter
require_once(DOKU_INC.'inc/blowfish.php');
require_once(DOKU_INC.'inc/actions.php');
require_once(DOKU_INC.'inc/changelog.php');
require_once(DOKU_INC.'inc/common.php');
require_once(DOKU_INC.'inc/confutils.php');
require_once(DOKU_INC.'inc/pluginutils.php');
require_once(DOKU_INC.'inc/plugin.php');
require_once(DOKU_INC.'inc/events.php');
require_once(DOKU_INC.'inc/form.php');
require_once(DOKU_INC.'inc/fulltext.php');
require_once(DOKU_INC.'inc/html.php');
require_once(DOKU_INC.'inc/httputils.php');
require_once(DOKU_INC.'inc/indexer.php');
require_once(DOKU_INC.'inc/infoutils.php');
require_once(DOKU_INC.'inc/io.php');
require_once(DOKU_INC.'inc/mail.php');
require_once(DOKU_INC.'inc/media.php');
require_once(DOKU_INC.'inc/pageutils.php');
require_once(DOKU_INC.'inc/parserutils.php');
require_once(DOKU_INC.'inc/search.php');
require_once(DOKU_INC.'inc/subscription.php');
require_once(DOKU_INC.'inc/template.php');
require_once(DOKU_INC.'inc/toolbar.php');
require_once(DOKU_INC.'inc/utf8.php');
require_once(DOKU_INC.'inc/auth.php');

/**
 * spl_autoload_register callback
 *
 * Contains a static list of DokuWiki's core classes and automatically
 * require()s their associated php files when an object is instantiated.
 *
 * @author Andreas Gohr <andi@splitbrain.org>
 * @todo   add generic loading of renderers and auth backends
 */
function load_autoload($name){
    static $classes = null;
    if(is_null($classes)) $classes = array(
        'DokuHTTPClient'        => DOKU_INC.'inc/HTTPClient.php',
        'JSON'                  => DOKU_INC.'inc/JSON.php',
        'adLDAP'                => DOKU_INC.'inc/adLDAP.php',
        'Diff'                  => DOKU_INC.'inc/DifferenceEngine.php',
        'UnifiedDiffFormatter'  => DOKU_INC.'inc/DifferenceEngine.php',
        'TableDiffFormatter'    => DOKU_INC.'inc/DifferenceEngine.php',
        'cache'                 => DOKU_INC.'inc/cache.php',
        'cache_parser'          => DOKU_INC.'inc/cache.php',
        'cache_instructions'    => DOKU_INC.'inc/cache.php',
        'cache_renderer'        => DOKU_INC.'inc/cache.php',
        'Doku_Event'            => DOKU_INC.'inc/events.php',
        'Doku_Event_Handler'    => DOKU_INC.'inc/events.php',
        'EmailAddressValidator' => DOKU_INC.'inc/EmailAddressValidator.php',
        'JpegMeta'              => DOKU_INC.'inc/JpegMeta.php',
        'SimplePie'             => DOKU_INC.'inc/SimplePie.php',
        'FeedParser'            => DOKU_INC.'inc/FeedParser.php',
        'IXR_Server'            => DOKU_INC.'inc/IXR_Library.php',
        'IXR_Client'            => DOKU_INC.'inc/IXR_Library.php',
        'IXR_IntrospectionServer' => DOKU_INC.'inc/IXR_Library.php',
        'Doku_Plugin_Controller'=> DOKU_INC.'inc/plugincontroller.class.php',
        'GeSHi'                 => DOKU_INC.'inc/geshi.php',
        'TarLib'                => DOKU_INC.'inc/TarLib.class.php',
        'ZipLib'                => DOKU_INC.'inc/ZipLib.class.php',
        'DokuWikiFeedCreator'   => DOKU_INC.'inc/feedcreator.class.php',
        'Doku_Parser_Mode'      => DOKU_INC.'inc/parser/parser.php',
        'SafeFN'                => DOKU_INC.'inc/SafeFN.class.php',
        'Sitemapper'            => DOKU_INC.'inc/Sitemapper.php',
        'PassHash'              => DOKU_INC.'inc/PassHash.class.php',

        'DokuWiki_Action_Plugin' => DOKU_PLUGIN.'action.php',
        'DokuWiki_Admin_Plugin'  => DOKU_PLUGIN.'admin.php',
        'DokuWiki_Syntax_Plugin' => DOKU_PLUGIN.'syntax.php',

    );

    if(isset($classes[$name])){
        require_once($classes[$name]);
        return;
    }

    // Plugin loading
    if(preg_match('/^(helper|syntax|action|admin|renderer)_plugin_([^_]+)(?:_([^_]+))?$/',
                  $name, $m)) {
                //try to load the wanted plugin file
        // include, but be silent. Maybe some other autoloader has an idea
        // how to load this class.
        $c = ((count($m) === 4) ? "/{$m[3]}" : '');
        @include DOKU_PLUGIN . "{$m[2]}/{$m[1]}$c.php";
        return;
    }
}

