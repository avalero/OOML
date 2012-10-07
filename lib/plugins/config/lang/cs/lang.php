<?php
/**
 * Czech language file
 *
 * @license    GPL 2 (http://www.gnu.org/licenses/gpl.html)
 * @author Bohumir Zamecnik <bohumir@zamecnik.org>
 * @author Zbynek Krivka <zbynek.krivka@seznam.cz>
 * @author tomas@valenta.cz
 * @author Marek Sacha <sachamar@fel.cvut.cz>
 * @author Lefty <lefty@multihost.cz>
 * @author Vojta Beran <xmamut@email.cz>
 * @author zbynek.krivka@seznam.cz
 */
$lang['menu']                  = 'Správa nastavení';
$lang['error']                 = 'Nastavení nebyla změněna kvůli alespoň jedné neplatné položce,
zkontrolujte prosím své úpravy a odešlete je znovu.<br />
Neplatné hodnoty se zobrazí v červeném rámečku.';
$lang['updated']               = 'Nastavení byla úspěšně upravena.';
$lang['nochoice']              = '(nejsou k dispozici žádné další volby)';
$lang['locked']                = 'Nelze upravovat soubor s nastavením. Pokud to není záměrné,
ujistěte se, <br /> že název a přístupová práva souboru s lokálním
nastavením jsou v pořádku.';
$lang['danger']                = 'Pozor: Změna tohoto nastavení může způsobit nedostupnost wiki a konfiguračních menu.';
$lang['warning']               = 'Varování: Změna nastavení může mít za následek chybné chování.';
$lang['security']              = 'Bezpečnostní varování: Změna tohoto nastavení může způsobit bezpečnostní riziko.';
$lang['_configuration_manager'] = 'Správa nastavení';
$lang['_header_dokuwiki']      = 'Nastavení DokuWiki';
$lang['_header_plugin']        = 'Nastavení pluginů';
$lang['_header_template']      = 'Nastavení šablon';
$lang['_header_undefined']     = 'Další nastavení';
$lang['_basic']                = 'Základní nastavení';
$lang['_display']              = 'Nastavení zobrazení';
$lang['_authentication']       = 'Nastavení autentizace';
$lang['_anti_spam']            = 'Protispamová nastavení';
$lang['_editing']              = 'Nastavení editace';
$lang['_links']                = 'Nastavení odkazů';
$lang['_media']                = 'Nastavení médií';
$lang['_advanced']             = 'Pokročilá nastavení';
$lang['_network']              = 'Nastavení sítě';
$lang['_plugin_sufix']         = 'Nastavení pluginů ';
$lang['_template_sufix']       = 'Nastavení šablon';
$lang['_msg_setting_undefined'] = 'Chybí metadata položky.';
$lang['_msg_setting_no_class'] = 'Chybí třída položky.';
$lang['_msg_setting_no_default'] = 'Chybí výchozí hodnota položky.';
$lang['fmode']                 = 'Přístupová práva pro vytváření souborů';
$lang['dmode']                 = 'Přístupová práva pro vytváření adresářů';
$lang['lang']                  = 'Jazyk';
$lang['basedir']               = 'Kořenový adresář (např. <code>/dokuwiki/</code>). Pro autodetekci nechte prázdné.';
$lang['baseurl']               = 'Kořenové URL (např. <code>http://www.yourserver.com</code>). Pro autodetekci nechte prázdné.';
$lang['savedir']               = 'Adresář pro ukládání dat';
$lang['cookiedir']             = 'Cesta pro cookie. Není-li vyplněno, použije se kořenové URL.';
$lang['start']                 = 'Název úvodní stránky';
$lang['title']                 = 'Název celé wiki';
$lang['template']              = 'Šablona';
$lang['license']               = 'Pod jakou licencí má být tento obsah publikován?';
$lang['fullpath']              = 'Ukazovat plnou cestu ke stránkám v patičce';
$lang['recent']                = 'Nedávné změny';
$lang['breadcrumbs']           = 'Počet odkazů na navštívené stránky';
$lang['youarehere']            = 'Hierarchická "drobečková" navigace';
$lang['typography']            = 'Provádět typografické nahrazování';
$lang['htmlok']                = 'Povolit vložené HTML';
$lang['phpok']                 = 'Povolit vložené PHP';
$lang['dformat']               = 'Formát data (viz PHP funkci <a href="http://www.php.net/strftime">strftime</a>)';
$lang['signature']             = 'Podpis';
$lang['toptoclevel']           = 'Nejvyšší úroveň, kterou začít automaticky generovaný obsah';
$lang['tocminheads']           = 'Nejnižší počet hlavních nadpisů, aby se vygeneroval obsah';
$lang['maxtoclevel']           = 'Maximální počet úrovní v automaticky generovaném obsahu';
$lang['maxseclevel']           = 'Nejnižší úroveň pro editaci i po sekcích';
$lang['camelcase']             = 'Používat CamelCase v odkazech';
$lang['deaccent']              = 'Čistit názvy stránek';
$lang['useheading']            = 'Používat první nadpis jako název stránky';
$lang['refcheck']              = 'Kontrolovat odkazy na média (před vymazáním)';
$lang['refshow']               = 'Počet zobrazených odkazů na média';
$lang['allowdebug']            = 'Povolit debugování. <b>Vypněte, pokud to nepotřebujete!</b>';
$lang['usewordblock']          = 'Blokovat spam za použití seznamu známých spamových slov';
$lang['indexdelay']            = 'Časová prodleva před indexací (v sekundách)';
$lang['relnofollow']           = 'Používat rel="nofollow" na externí odkazy';
$lang['mailguard']             = 'Metoda "zamaskování" emailových adres';
$lang['iexssprotect']          = 'Zkontrolovat nahrané soubory vůči možnému škodlivému JavaScriptu či HTML';
$lang['showuseras']            = 'Co se má přesně zobrazit, když se ukazuje uživatel, který naposledy editoval stránku';
$lang['useacl']                = 'Používat přístupová práva (ACL)';
$lang['autopasswd']            = 'Generovat hesla automaticky';
$lang['authtype']              = 'Metoda autentizace';
$lang['passcrypt']             = 'Metoda šifrování hesel';
$lang['defaultgroup']          = 'Výchozí skupina';
$lang['superuser']             = 'Superuživatel - skupina nebo uživatel s plnými právy pro přístup ke všem stránkách bez ohledu na nastavení ACL';
$lang['manager']               = 'Manažer - skupina nebo uživatel s přístupem k některým správcovským funkcím';
$lang['profileconfirm']        = 'Potvrdit změny v profilu zadáním hesla';
$lang['disableactions']        = 'Vypnout DokuWiki akce';
$lang['disableactions_check']  = 'Zkontrolovat';
$lang['disableactions_subscription'] = 'Přihlásit se/Odhlásit se ze seznamu pro odběr změn';
$lang['disableactions_wikicode'] = 'Prohlížet zdrojové kódy/Export wiki textu';
$lang['disableactions_other']  = 'Další akce (oddělené čárkou)';
$lang['sneaky_index']          = 'Ve výchozím nastavení DokuWiki zobrazuje v indexu všechny
jmenné prostory. Zapnutím této volby se skryjí ty jmenné prostory,
k nimž uživatel nemá právo pro čtení, což může ale způsobit, že
vnořené jmenné prostory, k nimž právo má, budou přesto skryty.
To může mít za následek, že index bude při některých
nastaveních ACL nepoužitelný.';
$lang['auth_security_timeout'] = 'Časový limit pro autentikaci (v sekundách)';
$lang['securecookie']          = 'Má prohlížeč posílat cookies nastavené přes HTTPS opět jen přes HTTPS? Vypněte tuto volbu, pokud chcete, aby bylo pomocí SSL zabezpečeno pouze přihlašování do wiki, ale obsah budete prohlížet nezabezpečeně.';
$lang['xmlrpc']                = 'Povolit/Zakázat rozhraní XML-RPC.';
$lang['xmlrpcuser']            = 'Omezit přístup pomocí XML-RPC pouze na zde zadané skupiny či uživatele (oddělené čárkami). Necháte-li pole prázdné, dáte přístup komukoliv.';
$lang['updatecheck']           = 'Kontrolovat aktualizace a bezpečnostní varování? DokuWiki potřebuje pro tuto funkci přístup k update.dokuwiki.org';
$lang['userewrite']            = 'Používat "pěkná" URL';
$lang['useslash']              = 'Používat lomítko jako oddělovač jmenných prostorů v URL';
$lang['usedraft']              = 'Během editace ukládat koncept automaticky';
$lang['sepchar']               = 'Znak pro oddělování slov v názvech stránek';
$lang['canonical']             = 'Používat plně kanonická URL';
$lang['fnencode']              = 'Metoda pro kódování ne-ASCII názvů souborů';
$lang['autoplural']            = 'Kontrolovat plurálové tvary v odkazech';
$lang['compression']           = 'Metoda komprese pro staré verze';
$lang['cachetime']             = 'Maximální životnost cache (v sekundách)';
$lang['locktime']              = 'Maximální životnost zámkových souborů (v sekundách)';
$lang['fetchsize']             = 'Maximální velikost souboru (v bajtech), co ještě fetch.php bude stahovat z externích zdrojů';
$lang['notify']                = 'Posílat oznámení o změnách na následující emailovou adresu';
$lang['registernotify']        = 'Posílat informace o nově registrovaných uživatelích na tuto mailovou adresu';
$lang['mailfrom']              = 'E-mailová adresa, která se bude používat pro automatické maily';
$lang['mailprefix']            = 'Předpona předmětu e-mailu, která se bude používat pro automatické maily';
$lang['gzip_output']           = 'Používat pro xhtml Content-Encoding gzip';
$lang['gdlib']                 = 'Verze GD knihovny';
$lang['im_convert']            = 'Cesta k nástroji convert z balíku ImageMagick';
$lang['jpg_quality']           = 'Kvalita komprese JPEG (0-100)';
$lang['subscribers']           = 'Možnost přihlásit se k odběru novinek stránky';
$lang['subscribe_time']        = 'Časový interval v sekundách, ve kterém jsou posílány změny a souhrny změn. Interval by neměl být kratší než čas uvedený v recent_days.';
$lang['compress']              = 'Zahustit CSS a JavaScript výstup';
$lang['cssdatauri']            = 'Velikost [v bajtech] obrázků odkazovaných v CSS souborech, které budou pro ušetření HTTP požadavku vestavěny do stylu. Tato technika nefunguje v IE 7 a starším. Doporučená hodnota je mezi <code>400</code> a <code>600</code> bajty. Pro vypnutí nastavte na <code>0</code>.';
$lang['hidepages']             = 'Skrýt stránky odpovídající vzoru (regulární výrazy)';
$lang['send404']               = 'Posílat "HTTP 404/Page Not Found" pro neexistují stránky';
$lang['sitemap']               = 'Generovat Google sitemap (interval ve dnech)';
$lang['broken_iua']            = 'Je na vašem systému funkce ignore_user_abort porouchaná? To může způsobovat nefunkčnost vyhledávacího indexu. O kombinaci IIS+PHP/CGI je známo, že nefunguje správně. Viz <a href="http://bugs.splitbrain.org/?do=details&amp;task_id=852">Bug 852</a> pro více informací.';
$lang['xsendfile']             = 'Používat X-Sendfile hlavničky pro download statických souborů z webserveru? Je však požadována podpora této funkce na straně Vašeho webserveru.';
$lang['renderer_xhtml']        = 'Vykreslovací jádro pro hlavní (xhtml) výstup wiki';
$lang['renderer__core']        = '%s (jádro DokuWiki)';
$lang['renderer__plugin']      = '%s (plugin)';
$lang['rememberme']            = 'Povolit trvaté přihlašovací cookies (zapamatuj si mě)';
$lang['rss_type']              = 'Typ XML kanálu';
$lang['rss_linkto']            = 'XML kanál odkazuje na';
$lang['rss_content']           = 'Co zobrazovat v položkách XML kanálu?';
$lang['rss_update']            = 'Interval aktualizace XML kanálu (v sekundách)';
$lang['recent_days']           = 'Jak staré nedávných změny uchovávat (ve dnech)';
$lang['rss_show_summary']      = 'XML kanál ukazuje souhrn v titulku';
$lang['target____wiki']        = 'Cílové okno pro interní odkazy';
$lang['target____interwiki']   = 'Cílové okno pro interwiki odkazy';
$lang['target____extern']      = 'Cílové okno pro externí odkazy';
$lang['target____media']       = 'Cílové okno pro odkazy na média';
$lang['target____windows']     = 'Cílové okno pro odkazy na windows sdílení';
$lang['proxy____host']         = 'Název proxy serveru';
$lang['proxy____port']         = 'Proxy port';
$lang['proxy____user']         = 'Proxy uživatelské jméno';
$lang['proxy____pass']         = 'Proxy heslo';
$lang['proxy____ssl']          = 'Použít SSL při připojení k proxy';
$lang['proxy____except']       = 'Regulární výrazy pro URL, pro které bude přeskočena proxy.';
$lang['safemodehack']          = 'Zapnout safemode hack';
$lang['ftp____host']           = 'FTP server pro safemode hack';
$lang['ftp____port']           = 'FTP port pro safemode hack';
$lang['ftp____user']           = 'FTP uživatelské jméno pro safemode hack';
$lang['ftp____pass']           = 'FTP heslo pro safemode hack';
$lang['ftp____root']           = 'FTP kořenový adresář pro safemode hack';
$lang['license_o_']            = 'Nic nevybráno';
$lang['typography_o_0']        = 'vypnuto';
$lang['typography_o_1']        = 'Pouze uvozovky';
$lang['typography_o_2']        = 'Všechny typy uvozovek a apostrofů (nemusí vždy fungovat)';
$lang['userewrite_o_0']        = 'vypnuto';
$lang['userewrite_o_1']        = '.htaccess';
$lang['userewrite_o_2']        = 'interní metoda DokuWiki';
$lang['deaccent_o_0']          = 'vypnuto';
$lang['deaccent_o_1']          = 'odstranit diakritiku';
$lang['deaccent_o_2']          = 'převést na latinku';
$lang['gdlib_o_0']             = 'GD knihovna není k dispozici';
$lang['gdlib_o_1']             = 'Verze 1.x';
$lang['gdlib_o_2']             = 'Autodetekce';
$lang['rss_type_o_rss']        = 'RSS 0.91';
$lang['rss_type_o_rss1']       = 'RSS 1.0';
$lang['rss_type_o_rss2']       = 'RSS 2.0';
$lang['rss_type_o_atom']       = 'Atom 0.3';
$lang['rss_type_o_atom1']      = 'Atom 1.0';
$lang['rss_content_o_abstract'] = 'Abstraktní';
$lang['rss_content_o_diff']    = 'Sjednocený Diff';
$lang['rss_content_o_htmldiff'] = 'diff tabulka v HTML formátu';
$lang['rss_content_o_html']    = 'Úplný HTML obsah stránky';
$lang['rss_linkto_o_diff']     = 'přehled změn';
$lang['rss_linkto_o_page']     = 'stránku samotnou';
$lang['rss_linkto_o_rev']      = 'seznam revizí';
$lang['rss_linkto_o_current']  = 'nejnovější revize';
$lang['compression_o_0']       = 'vypnuto';
$lang['compression_o_gz']      = 'gzip';
$lang['compression_o_bz2']     = 'bz2';
$lang['xsendfile_o_0']         = 'nepoužívat';
$lang['xsendfile_o_1']         = 'Proprietární hlavička lighttpd (před releasem 1.5)';
$lang['xsendfile_o_2']         = 'Standardní hlavička X-Sendfile';
$lang['xsendfile_o_3']         = 'Proprietární hlavička Nginx X-Accel-Redirect';
$lang['showuseras_o_loginname'] = 'Přihlašovací jméno';
$lang['showuseras_o_username'] = 'Celé jméno uživatele';
$lang['showuseras_o_email']    = 'E-mailová adresa uživatele ("zamaskována" aktuálně nastavenou metodou)';
$lang['showuseras_o_email_link'] = 'E-mailová adresa uživatele jako mailto: odkaz';
$lang['useheading_o_0']        = 'Nikdy';
$lang['useheading_o_navigation'] = 'Pouze pro navigaci';
$lang['useheading_o_content']  = 'Pouze pro wiki obsah';
$lang['useheading_o_1']        = 'Vždy';
$lang['readdircache']          = 'Maximální stáří readdir cache (sec)';
