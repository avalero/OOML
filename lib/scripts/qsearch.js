/**
 * AJAX functions for the pagename quicksearch
 *
 * @license  GPL2 (http://www.gnu.org/licenses/gpl.html)
 * @author   Andreas Gohr <andi@splitbrain.org>
 * @author   Adrian Lang <lang@cosmocode.de>
 * @author   Michal Rezler <m.rezler@centrum.cz>
 */

var dw_qsearch = {

    $inObj: null,
    $outObj: null,
    timer: null,

    /**
     * initialize the quick search
     *
     * Attaches the event handlers
     *
     * @param input element (jQuery selector/DOM obj)
     * @param output element (jQuery selector/DOM obj)
     */
    init: function (input, output) {
        var do_qsearch;

        dw_qsearch.$inObj  = jQuery(input);
        dw_qsearch.$outObj = jQuery(output);

        // objects found?
        if (dw_qsearch.$inObj.length === 0 ||
            dw_qsearch.$outObj.length === 0) {
            return;
        }

        // attach eventhandler to search field
        do_qsearch = function () {
            dw_qsearch.clear_results();
            var value = dw_qsearch.$inObj.val();
            if (value === '') {
                return;
            }
            jQuery.post(
                DOKU_BASE + 'lib/exe/ajax.php',
                {
                    call: 'qsearch',
                    q: encodeURI(value)
                },
                dw_qsearch.onCompletion,
                'html'
            );
        };

        dw_qsearch.$inObj.keyup(
            function() {
                if(dw_qsearch.timer){
                    window.clearTimeout(dw_qsearch.timer);
                    dw_qsearch.timer = null;
                }
                dw_qsearch.clear_results();
                dw_qsearch.timer = window.setTimeout(do_qsearch, 500);
            }
        );

        // attach eventhandler to output field
        dw_qsearch.$outObj.click(dw_qsearch.clear_results);
    },

    /**
     * Empty and hide the output div
     */
    clear_results: function(){
        dw_qsearch.$outObj.hide();
        dw_qsearch.$outObj.text('');
    },

    /**
     * Callback. Reformat and display the results.
     *
     * Namespaces are shortened here to keep the results from overflowing
     * or wrapping
     *
     * @param data The result HTML
     */
    onCompletion: function(data) {
        var max, $links, too_big;

        if (data === '') { return; }

        dw_qsearch.$outObj
            .html(data)
            .show()
            .css('white-space', 'nowrap');

        // shorten namespaces if too long
        max = dw_qsearch.$outObj[0].clientWidth;
        $links = dw_qsearch.$outObj.find('a');
        too_big = (document.documentElement.dir === 'rtl')
                  ? function (l) { return l.offsetLeft < 0; }
                  : function (l) { return l.offsetWidth + l.offsetLeft > max; };

        $links.each(function () {
            var start, length, replace, nsL, nsR, eli, runaway;

            if (!too_big(this)) {
                return;
            }

            nsL = this.innerText.indexOf('(');
            nsR = this.innerText.indexOf(')');
            eli = 0;
            runaway = 0;

            while((nsR - nsL > 3) && too_big(this) && runaway++ < 500) {
                if(eli !== 0){
                    // elipsis already inserted
                    if( (eli - nsL) > (nsR - eli) ){
                        // cut left
                        start = eli - 2;
                        length = 2;
                    }else{
                        // cut right
                        start = eli + 1;
                        length = 1;
                    }
                    replace = '';
                }else{
                    // replace middle with ellipsis
                    start = Math.floor( nsL + ((nsR-nsL)/2) );
                    length = 1;
                    replace = '…';
                }
                this.innerText = substr_replace(this.innerText,
                                                replace, start, length);

                eli = this.innerText.indexOf('…');
                nsL = this.innerText.indexOf('(');
                nsR = this.innerText.indexOf(')');
            }
        });
    }
};

jQuery(function () {
    dw_qsearch.init('#qsearch__in','#qsearch__out');
});
