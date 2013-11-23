<!DOCTYPE html>
<html>
<head>
    <title>Wy0Sly</title>
    <script src="//ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
	<script src="http://openpgpjs.org/openpgpjs/resources/openpgp.min.js"></script>
    <link href="http://netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css" rel="stylesheet">
</head>
<body>
<!--

Mostly my code, but with tutorials and ideas from codecamp too...
	This website is intended to be as hackable as possible...
	Some sources
		icons|http://fontawesome.io/icons/
		code camp|https://c9.io/pepperlk/pitchengine-codecamp/
		JS|https://developers.google.com/speed/libraries/devguide#jquery
-->
<script type="text/javascript">
$(document).ready(function() {
var a=null;//last selected item, that I'll need to hide
$('.nav').click(function(){
	//hide the last item
	$(S(a).attr('data-id')).addClass('hide');
	$($(a).attr('data-id')).removeClass('show');
	//show the next item
	$($(this).attr('data-id')).addClass('show');
	$($(this).attr('data-id')).removeClass('hide');
	//this is now the last item
	a=this;
)};
//bigBadErrorMessage!!
$("#bigBadErrorMessage").mouseenter(function(){
	$(this).click(function(){
		$("*").fadeOut("slow") ;
	});
});
</script>
<style>
*{
    margin:0;
    padding:0;
    transition:left1s, height 1s, width 1s, opacity 1s;
}body{
background-color: #dddddd;
}#nav{
    position:fixed;
    width:100%;
    height:10%;
    background-color:#484E4E;
}.nav{
    position:relative;
    display:inline-block;
}#player{
	position:absolute;
	bottom:0;
	width:60%;
	height:80%;
	border-radius:10px;
	background-color:#484E4E;
	margin: 0 auto;
	display: table;
}.player{
	position:relative;
	display:
}.hide{
    opacity:0;
}.show{
    opacity:1;
}
</style>
<!-- the big one... making the client switch audio streams >.< -->
<audio
src="musicurl1.ogg"
src="musicurl2.ogg"
src="musicurl1.mp3"
src="musicurl2.mp3">
	<!--contain the error message for non-html5 browsers-->
	<div id="bigBadErrorMessage">
		<h1><strong>oops... your browser doesn't like HTML5<strong></h1>
		<h2>try a refresh:</h2><i class="fa fa-refresh"></i>
		<!--someone put in the JS to get rid of the whole page please-->
		<!--if you don't support html5, heaven help you...-->
	</div>
</audio>

<div id="nav"><!-- display differently depending on @media!-->
<!-- only display 'dj' when a logged in user (any kind) -->
	<div class="nav" id="dj" data-id="control">
		<!-- make JS navigate to home (CSS3) -->
	</div>
<!--display 'results' globally, just not including like/dislike or play-->
	<div class="nav" id="search" data-id="results">
		<!-- make JS navigate to results (CSS3) -->
		<form>
			<input type="text" name="wy0slyquery"><!--pitchengine search-->
			<i class="fa fa-search"></i>			
			<input type="submit" value=""><!--use fontawesome as button-->
		</form>
	</div>
<!--display 'jukebox' globally, just not including like/dislike or play-->
	<div class="nav" id="home" data-id="jukebox">
		<!-- make JS navigate to jukebox (CSS3) -->
		<i class="fa fa-home"></i>
	</div>
<!--only display 'messages' when a logged in user (any kind) -->
	<div class="nav" id="inbox" data-id="messages">
		<!-- make JS navigate to inbox (CSS3) -->
		<i class="fa fa-envelope"></i>
	</div>
<!--display 'session' differently depending on user -->
    <div class="nav" id="session" data-id="login">
		<i class="fa fa-gear"></i>
	</div>
</div>




<div id="player"><!-- display differently depending on @media!-->
	<div class="player hide" id="login" data-id="session">
		<!--login changes to register with click of button-->
		<!--toggle switch between login/register-->
		<!--if register, include an email entry-->
<!--if register, include fontawesome like so:<i class="fa fa-user"></i>-->
		<form method="post" action="">
			<input type="text" maxlenth="30" required="" autofocus=""
			name="username" placeholder="username">
			<input type="password" maxlength="30" requied=""
			name="password">
			<input type="submit" name="login" value="Login">
			<input type="email" maxlength="30" name="email" 
			placeholder="register your email">
			<!--without placeholder it becomes:value="First Name" onfocus="if (this.value == 'First Name') {this.value = '';}" onblur="if (this.value == '') {this.value = 'First Name';}"-->
			<input type="button" name="register" value="Register"
			onclick="location.href=&#39;register.php&#39;">
			<!--display text once server has checked email-->
		</form>
		<div id="terms">
			<!--scroll this up with a tap to show terms :D -->
			<h1>terms</h1>
			<i class="fa fa-quote-left"></i>
			We use cookies to provide secure access to these controls.
			use of this service constitutes acceptance of those terms.
			<!-- just toggle the CSS3 class using JS -->
			<i class="fa fa-quote-right"></i>
		</div>
	</div>
<!--redirect to login if you're to this point and you're not a user-->
	<div class="player hide" id="messages" data-id="inbox">
		<textarea rows="20" cols="40"></textarea>
		<input type="submit" value="send">
		<!--use Font Awesome as button >.< -->
	</div>
	<div class="player show" id="jukebox" data-id="home">
		<!-- have all the play controls on the top of the jukebox -->
		<!-- custom build this, don't use audiocontrols=audiocontrols-->
		<i class="fa fa-play"></i>
		<i class="fa fa-stop"></i>
		<i class="fa fa-thumbs-up"></i>
		<i class="fa fa-thumbs-down"></i>
		<!--use Font Awesome for each function >.< -->
		<!--
		<form>
			<input type="button" name="play"||"stop"||"like"||"dislike">
			value=""
		</form>
		-->
	</div>
	<div class="player hide" id="control" data-id="dj">
		<i class="fa fa-lock"></i>
		<!--at the top of the nav bar, include a "mode" select:
		<select name="mode">
			<option value="Guest">Guest</option>
			<option value="User" selected="">User</option>
			<option value="DJ">DJ</option>
		</select>
		-->
		<!-- whenever it does the selected="" is that an error O.O -->
		<div class="control" id="stream">
			<!--from that device-->
			<i class="fa fa-microphone"></i>
			<!--stop: fa-microphone-slash-->
			<!--from the cloud-->
			<i class="fa fa-cloud"></i>
			<!--display pre-existing servers in table-->
			<!--add value-->
			<i class="fa fa-external-link"></i>
			<input type="url" maxlength="50" required="" name="ip"
			placeholder="localhost">
			<input type="number" maxlength="10" required="" name="port"
			placeholder="1234">
			<!--set defaults-->
			<i class="fa fa-square">
			<!--parse the liquidsoap configuration-->
		</div>
		<div class="control" id="upload">
			<!--select files, enter information-->
			<i class="fa fa-folder-open"></i>
			<input type="text" maxlength="30" required="" name="author" 			placeholder="authors name"><br>
			<input type="text" maxlength="30" required="" name="album" 				placeholder="album name"><br>
			<input type="text" maxlength="30" required="" name="song" 				placeholder="song name"><br>
			<input type="email" maxlength="30" required="" name="email" 			placeholder="email of uploader"><br>
		</div>
		<div class="control" id="source">
			<!--select the source of the local audio-->
			Stream:<br>
			<!--use Font Awesome as buttons >.< -->
			<i class="fa fa-circle"></i>
			<i class="fa fa-circle-o"></i>
			<input type="radio" name="CWCRR">CWC Rustler Radio<br>
			<input type="radio" name="LVHST">LVHS Tech Club<br>		
			<input type="radio" name="LOCAL">System Microphone<br>
			<input type="radio" name="TESTR">Test a stream<br>
				<!--on clicking this option, pull up the dialog: -->
				<input type="url" maxlength="50" required="" name="ip"
				placeholder="localhost">
				<input type="number" maxlength="10" required="" name="port"
				placeholder="1234">
		</div>
		<div class="control" id="server">
			<!--perform server functions-->
			<!--power management-->
			<i class="fa fa-power-off"></i>
			<!--restart schedule-->
			<i class="fa fa-calendar"></i>
			<!--restart now-->
			<i class="fa fa-warning"></i>
			<!--kexec-->
			<!--liquidsoap config radio/checkbox settings-->
			<!--apache2 config radio/checkbox settings-->
		</div>
		<div class="control" id="admin">
			<!--allow changing users-->
			<i class="fa fa-shield"></i>

		</div>
		<div class="control" id="debug">
			<!--edit the php, talk to mysql-->
			<select name="debug">
				<option Value="index.php">Index-raw</option>
				<option Value="Apache2.conf">Apache-config</option>
				<option Value="PHP.ini">PHP-config</option>
				<option Value="mySQL.conf">mySQL-config</option>
				<option Value="Liquidsoap.conf">Liquidsoap-config</option>
				<option Value="Icecast.conf">Icecast.conf</option>
				<option Value="Terminal">TERMINAL</option>
				<!--this is intentionally ENTIRELY unsafe ;) -->
			</select>
			<i class="fa fa-edit"></i>
		</div>
	</div>
	<div class="player hide" id="results" data-id="search">
		<!-- the scary cool stuff... making this thing display results-->
		<input type="text" maxlength="30">
		<i class="fa fa-search"></i>
		<!--use Font Awesome as button >.< -->
	</div>
</div>


<!--probably copyrighted by someone by the end of this-->
<!--I CALL DIBS ON IT BEING OPEN SOURCE!!!-->
</body>
</html>
