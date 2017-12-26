var useAndroidAPI = false;
var sessionId = Math.floor(Math.random() * 1000000);
var lang = "en";
var accessToken ="2e5449618aeb4756a64a09f413a16f87";

$(document).ready(function(){
	if ($("#simulatorFl").val() != "true" && $("#platformName").val() == "ANDROID") {
		useAndroidAPI = true;
	}
})

$(document).on('click', '.panel-heading span.icon_minim', function (e) {
	updateMessageTimeStamp();
	toggleChatBox($(this));
});


$(document).on('click', '#btn-send', function (e) {
	updateMessageTimeStamp();
	sendMessage();
});


$(document).on('keypress', '#chat-input', function (event) {
	if (event.which == 13) {
		event.preventDefault();
		updateMessageTimeStamp();
		sendMessage();
	}
});


function toggleChatBox(switchButton){
	if (!switchButton.hasClass('panel-collapsed')) {
		switchButton.parents('.panel').find('.panel-body').slideUp();
		switchButton.parents('.panel').find('.panel-footer').slideUp();
		switchButton.addClass('panel-collapsed');
		switchButton.removeClass('glyphicon-minus').addClass('glyphicon-plus');
	}
	else {
		if (useAndroidAPI) {
			androidAPI("", true);
		}
		switchButton.parents('.panel').find('.panel-body').slideDown();
		switchButton.parents('.panel').find('.panel-footer').slideDown();
		switchButton.removeClass('panel-collapsed');
		switchButton.removeClass('glyphicon-plus').addClass('glyphicon-minus');
	}
}


function sendMessage(){
	var sentDt = new Date();
	sentMessage = $("#chat-input").val();
	$("#chat-input").val("");

	var sentMessageHTML = '<div class="row msg_container base_sent">';
	sentMessageHTML += '<div class="col-md-10 col-xs-10">';
	sentMessageHTML += '<div class="messages msg_sent">';
	sentMessageHTML += '<p>'+sentMessage+'</p>';
	sentMessageHTML += '<time datetime="'+sentDt.getTime()+'">Agent • <span>Just Now</span></time>';
	sentMessageHTML += '</div>';
	sentMessageHTML += '</div>';
	sentMessageHTML += '<div class="col-md-2 col-xs-2 avatar">';
	sentMessageHTML += '<img src="/public/images/profile-icon.png" alt="" class=" img-responsive">';
	sentMessageHTML += '</div>';
	sentMessageHTML += '</div>';

	$(".panel-body").append(sentMessageHTML);
	$(".panel-body").stop().animate({ scrollTop: $(".panel-body").prop("scrollHeight") }, 1000);

	if (useAndroidAPI) {
		androidAPI(sentMessage, false);
	}
	else {
		genericAPI(sentMessage);
	}
}


function androidAPI(sentMessage, init) {
	if(init) {
		$.ajax({
			url: "/app/Chat/init",
			headers: {'Transition-Enabled': false},
			success: function(data){
			}
		});
	}
	else {
		$.ajax({
			url: "/app/Chat/sendMessage",
			data: {"query": sentMessage},
			headers: {'Transition-Enabled': false},
			success: function(receivedMessage){
				setResponse(receivedMessage);
			},
			error: function() {
				setResponse("Internal Server Error");
			}
		});
	}
}


function genericAPI(sentMessage) {
	var baseUrl = "https://api.dialogflow.com/v1/";
	$.ajax({
		type: "POST",
		url: baseUrl + "query?v=20150910",
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		headers: {
			"Authorization": "Bearer " + accessToken
		},
		data: JSON.stringify({ query: sentMessage, lang: lang, sessionId: sessionId }),
		success: function(data) {
			var receivedMessage = data.result.fulfillment.speech;
			setResponse(receivedMessage);
		},
		error: function() {
			setResponse("Internal Server Error");
		}
	});
}


function setResponse(receivedMessage) {
	var receivedDt = new Date();
	var receivedMessageHTML = '<div class="row msg_container base_receive">';
	receivedMessageHTML += '<div class="col-md-2 col-xs-2 avatar">';
	receivedMessageHTML += '<img src="/public/images/profile-icon.png" alt="" class=" img-responsive ">';
	receivedMessageHTML += '</div>';
	receivedMessageHTML += '<div class="col-md-10 col-xs-10">';
	receivedMessageHTML += '<div class="messages msg_receive">';
	receivedMessageHTML += '<p>'+receivedMessage+'</p>';
	receivedMessageHTML += '<time datetime="'+receivedDt.getTime()+'">Admin • <span>Just Now</span></time>';
	receivedMessageHTML += '</div>';
	receivedMessageHTML += '</div>';
	receivedMessageHTML += '</div>';

	$(".panel-body").append(receivedMessageHTML);
	$(".panel-body").stop().animate({ scrollTop: $(".panel-body").prop("scrollHeight") }, 1000);
}


function updateMessageTimeStamp() {
	var currentTime = new Date().getTime();
	$("time").each(function(){
		var secondDiff = Math.round((currentTime - Number($(this).attr("datetime")))/1000);
		var minuteDiff = Math.round(secondDiff/60);
		if(minuteDiff<1){
			$(this).find('span').html("Just Now");
		}
		else{
			$(this).find('span').html(minuteDiff+" mins");	
		}
	});
}