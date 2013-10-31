#pieces

### load balancing/slave server master **/index.php**
* also can mirror master server's load balancing onsite, ie "cwc/lvhsradio/index.php"
* goal of code: write the requested load balanced code (upload the correct DOM)

### login page**/tech login.php** code snippet: **login-hover**
* mysql database: user token, email, browser session, secure remote permissions
* goal: nab everyone without a cookie, unless DOM is in guest mode

### liquidsoap server **"not" accessable** DOM element: **none?**
* remote vlc stream for dj? (on same database as liquidsoap server)

#### icecast 1 (tech club) code snippet **antenna1** resource address: **/antenna1.mpeg /antenna1.ogg**
* simply changes the dynamic code for <audio controls>

#### icecast 2 (lvhs) code snippet **antenna2** resource address: **/antenna2.mpeg /antenna2.ogg**
* simply changes the dynamic code for <audio controls>

#### icecast 3 (cwc) code snippet **antenna3** resource address: **/antenna3.mpeg /antenna3.ogg**
* simply changes the dynamic code for <audio controls>

### css3 applet code snippet **css-radio** resource address: **/css-radio-applet.html**
* @media query for smartphone vs desktop
* simple DOM template for each song in the queue
* "now playing" interface for standard & guest users
* "dj headphones" interface for radio staff (remove element of DOM if noneauthenticated)
* "get queue" code to retrieve and build the DOM
* "submit queue" code to send audio controls to liquidsoap
* queue code snippet **get-queue** resource address: **/queue-sync.php**
* edit submit snippet **submit-queue** resource address: (mysql restricted) **/submit-queue**
* backend restart at midnight **php-reset-liquidsoap**
* icecast slave auth? allows master server to control antennas
* liquidsoap secure remote? submit commands to liquidsoap

## structure (could be VMs or on the same machine)

* master
    liquidsoap
    another liquidsoap? (relieves hard resets)
    vlc dj stream?
    slave1 (tech club)
        icecast
        mysql login credentials
        mysql build pages / resources
    slave2 (lvhs)
        icecast
        mysql login credentials
        mysql build pages / resources
    slave3 (cwc)
        icecast
        mysql login credentials
        mysql build pages / resources
        
<audio controls>
<source src="full/link/to/http/mp3/audio/file.mp3" type="audio/mpeg" />
<source src="full/link/to/http/ogg/audio/file.ogg" type="audio/ogg" />
<em>Sorry, your browser doesn't support HTML5 audio.</em>
</audio>

[audio streaming?](http://www.boutell.com/newfaq/creating/audio.html)
[php scaling?](http://www.oracle.com/technetwork/articles/dsl/white-php-part1-355135.html)
[prebuilt liquidsoap controls](http://savonet.sourceforge.net/tools.html)
[php login](http://www.phpeasystep.com/phptu/6.html)