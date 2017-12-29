var useAndroidAPI = false;

var firebaseAPIKey = null;
var dialogflowSessionId = null;
var dialogflowLang = null;
var dialogflowAccessToken = null;
var dialogflowBaseUrl = null;

var firebaseUserIdToken = null;
var firebaseUserLocalId = null;
var firebaseUserRefreshToken = null;
var chatType = "#ai";


$(document).ready(function(){
	if ($("#simulatorFl").val() != "true" && $("#platformName").val() == "ANDROID") {
		useAndroidAPI = true;
	}
	else {
		initChat();
	}
	$('a[data-toggle="tab"]').on('shown.bs.tab', function (e) {
		chatType = e.target.hash;
	})
});


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


function initChat(){
	firebaseAPIKey = "AIzaSyCX46VXOfHjjVSU-3-8zfeDx7VQAxmku5s";
	dialogflowSessionId = Math.floor(Math.random() * 1000000);
	dialogflowLang = "en";
	dialogflowAccessToken ="2e5449618aeb4756a64a09f413a16f87";
	dialogflowBaseUrl = "https://api.dialogflow.com/v1/";
}


function signInUser(email, password){
	$.ajax({
		type: "POST",
		url: "https://www.googleapis.com/identitytoolkit/v3/relyingparty/verifyPassword?key="+firebaseAPIKey,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		data: JSON.stringify({ email: email, password: password, returnSecureToken: true }),
		success: function(data) {
			firebaseUserIdToken = data.idToken;
			firebaseUserLocalId = data.localId;
			firebaseUserRefreshToken = data.refreshToken;
			setTimeout(function(){ signInUser(email, password); }, Number(data.expiresIn)*1000);
			setupUser(email);
			refreshGroupChat("underwriters");
		},
		error: function(data) {
			var errorCode = data.responseJSON.error.message;
			console.log(errorCode);
			if (errorCode == "EMAIL_NOT_FOUND"){
				signUpUser(email, password);
			}
		}
	});
}


function signUpUser(email, password){
	$.ajax({
		type: "POST",
		url: "https://www.googleapis.com/identitytoolkit/v3/relyingparty/signupNewUser?key="+firebaseAPIKey,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		data: JSON.stringify({ email: email, password: password, returnSecureToken: true }),
		success: function(data) {
			firebaseUserIdToken = data.idToken;
			firebaseUserLocalId = data.localId;
			firebaseUserRefreshToken = data.refreshToken;
			setTimeout(function(){ signInUser(email, password); }, Number(data.expiresIn)*1000);
			setupUser(email);
			refreshGroupChat("underwriters");
		},
		error: function(data) {
			var errorCode = data.responseJSON.error.message;
			console.log(errorCode);
		}
	});
}


function refreshGroupChat(groupId){
	$.ajax({
		type: "GET",
		url: "https://kitchensink-1718a.firebaseio.com/members.json?print=pretty&auth="+firebaseUserIdToken,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		success: function(data) {
			if(data == null){
				jsonString = '{"'+groupId+'":{"'+firebaseUserLocalId+'":true}}';
				$.ajax({
					type: "PUT",
					url: "https://kitchensink-1718a.firebaseio.com/members.json?auth="+firebaseUserIdToken,
					contentType: "application/json; charset=utf-8",
					dataType: "json",
					data: jsonString,
					success: function(data) {
						console.log(data);
					},
					error: function(data) {
						console.log(data);
					}
				});
			}
			else {
				jsonString = '{"'+groupId+'":{"'+firebaseUserLocalId+'":true}}';
				$.ajax({
					type: "PATCH",
					url: "https://kitchensink-1718a.firebaseio.com/members.json?auth="+firebaseUserIdToken,
					contentType: "application/json; charset=utf-8",
					dataType: "json",
					data: jsonString,
					success: function(data) {
						console.log(data);
					},
					error: function(data) {
						console.log(data);
					}
				});
			}
		},
		error: function(data) {
			console.log(data);
		}
	});	
}


function openSingleChat(targetUserId){

}


function setupUser(email){
	$.ajax({
		type: "PUT",
		url: "https://kitchensink-1718a.firebaseio.com/users/"+firebaseUserLocalId+".json?auth="+firebaseUserIdToken,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		data: JSON.stringify({
			"email": email
		}),
		success: function(data) {
			// firebaseUserIdToken = data.idToken;
			// firebaseUserLocalId = data.localId;
			// firebaseUserRefreshToken = data.refreshToken;
			// setTimeout(function(){ signInUser(email, password); }, Number(data.expiresIn)*1000);
		},
		error: function(data) {
			// var errorCode = data.responseJSON.error.message;
			// console.log(errorCode);
			// if (errorCode == "EMAIL_NOT_FOUND"){
			// 	signUpUser(email, password);
			// }
		}
	});
}


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
		else {
			signInUser("avdhut.vaidya@c2lbiz.com", "password");
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

	$(".panel-body "+chatType).append(sentMessageHTML);
	$(".panel-body "+chatType).stop().animate({ scrollTop: $(".panel-body "+chatType).prop("scrollHeight") }, 1000);

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
	$.ajax({
		type: "POST",
		url: dialogflowBaseUrl + "query?v=20150910",
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		headers: {
			"Authorization": "Bearer " + dialogflowAccessToken
		},
		data: JSON.stringify({ query: sentMessage, lang: dialogflowLang, sessionId: dialogflowSessionId }),
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

	$(".panel-body "+chatType).append(receivedMessageHTML);
	$(".panel-body "+chatType).stop().animate({ scrollTop: $(".panel-body "+chatType).prop("scrollHeight") }, 1000);
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