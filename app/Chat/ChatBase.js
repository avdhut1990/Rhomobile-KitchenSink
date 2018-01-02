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

var name = "";
var password = "";
var emailId = "";


// Global chat functions
$(document).ready(function(){
	if ($("#simulatorFl").val() != "true" && $("#platformName").val() == "ANDROID") {
		// useAndroidAPI = true;
		initChat();
	}
	else {
		initChat();
	}
	$('a[data-toggle="tab"]').on('shown.bs.tab', function (e) {
		chatType = e.target.hash;
		if(firebaseUserLocalId == null && chatType == "#group"){
			name = $("#name").val();
			password = $("#password").val();
			emailId = $("#emailId").val();
			signInUser("underwriters");
		}
		$(".panel-body").stop().animate({ scrollTop: $(".panel-body").prop("scrollHeight") }, 1000);
	});
});


$(document).on('click', '.panel-heading span.icon_minim', function (e) {
	toggleChatBox($(this));
});


$(document).on('click', '#btn-send', function (e) {
	if(chatType == "#ai"){
		sendAIMessage();
	}
	else{
		sendGroupMessage("underwriters");	
	}
});


$(document).on('keypress', '#chat-input', function (event) {
	if (event.which == 13) {
		event.preventDefault();
		if(chatType == "#ai"){
			sendAIMessage();
		}
		else{
			sendGroupMessage("underwriters");	
		}
	}
});


function initChat(){
	firebaseAPIKey = "AIzaSyCX46VXOfHjjVSU-3-8zfeDx7VQAxmku5s";
	dialogflowSessionId = Math.floor(Math.random() * 1000000);
	dialogflowLang = "en";
	dialogflowAccessToken ="2e5449618aeb4756a64a09f413a16f87";
	dialogflowBaseUrl = "https://api.dialogflow.com/v1/";
}


function toggleChatBox(switchButton){
	if(chatType == "#ai"){
		updateMessageTimeStamp();
	}
	if (!switchButton.hasClass('panel-collapsed')) {
		switchButton.parents('.panel').find('.panel-body').slideUp();
		switchButton.parents('.panel').find('.panel-footer').slideUp();
		switchButton.addClass('panel-collapsed');
		switchButton.removeClass('glyphicon-minus').addClass('glyphicon-plus');
	}
	else {
		if(useAndroidAPI && chatType == "#ai") {
			androidAPI("", true);
		}
		switchButton.parents('.panel').find('.panel-body').slideDown();
		switchButton.parents('.panel').find('.panel-footer').slideDown();
		switchButton.removeClass('panel-collapsed');
		switchButton.removeClass('glyphicon-plus').addClass('glyphicon-minus');
	}
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




// AI chat functions
function sendAIMessage(){
	updateMessageTimeStamp();
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
	$(".panel-body").stop().animate({ scrollTop: $(".panel-body").prop("scrollHeight") }, 1000);

	if (useAndroidAPI) {
		androidAPI(sentMessage, false);
	}
	else {
		genericAPI(sentMessage);
	}
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
	$(".panel-body").stop().animate({ scrollTop: $(".panel-body").prop("scrollHeight") }, 1000);
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




// Group chat functions
function signInUser(groupId){
	$.ajax({
		type: "POST",
		url: "https://www.googleapis.com/identitytoolkit/v3/relyingparty/verifyPassword?print=silent&key="+firebaseAPIKey,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		data: JSON.stringify({ email: emailId, password: password, returnSecureToken: true }),
		success: function(data) {
			console.log("User sign-in successful.");
			firebaseUserIdToken = data.idToken;
			firebaseUserLocalId = data.localId;
			firebaseUserRefreshToken = data.refreshToken;
			setTimeout(function(){ signInUser(); }, Number(data.expiresIn)*1000);
			if(groupId != null){
				openGroupChat(groupId);
			}
			updateUserData('{"name": "'+name+'"}');
		},
		error: function(data) {
			var errorCode = data.responseJSON.error.message;
			console.log("User sign-in failed: "+errorCode);
			if (errorCode == "EMAIL_NOT_FOUND"){
				signUpUser(groupId);
			}
		}
	});
}


function signUpUser(groupId){
	$.ajax({
		type: "POST",
		url: "https://www.googleapis.com/identitytoolkit/v3/relyingparty/signupNewUser?print=silent&key="+firebaseAPIKey,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		data: JSON.stringify({ email: emailId, password: password, returnSecureToken: true }),
		success: function(data) {
			console.log("User sign-up successful.");
			firebaseUserIdToken = data.idToken;
			firebaseUserLocalId = data.localId;
			firebaseUserRefreshToken = data.refreshToken;
			setTimeout(function(){ signInUser(); }, Number(data.expiresIn)*1000);
			if(groupId != null){
				openGroupChat(groupId);
			}
			updateUserData('{"name": "'+name+'"}');
		},
		error: function(data) {
			var errorCode = data.responseJSON.error.message;
			console.log("User sign-up failed: "+errorCode);
		}
	});
}


function openGroupChat(groupId){
	$.ajax({
		type: "GET",
		url: "https://kitchensink-1718a.firebaseio.com/chatMembers/"+groupId+"/"+firebaseUserLocalId+".json?print=silent&auth="+firebaseUserIdToken,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		success: function(data) {
			if(data == null){
				console.log("Member not part of chat group: "+groupId);
				jsonString = '{"'+firebaseUserLocalId+'":true}';
				$.ajax({
					type: "PATCH",
					url: "https://kitchensink-1718a.firebaseio.com/chatMembers/"+groupId+".json?print=silent&auth="+firebaseUserIdToken,
					contentType: "application/json; charset=utf-8",
					dataType: "json",
					data: jsonString,
					success: function(data) {
						console.log("Member added to chat group: "+groupId+" successfully.");
						updateUserData('{"chatGroups": {"'+groupId+'":true}}');
						refreshGroupChat(groupId);
					},
					error: function(data) {
						console.log("Member addition to chat group: "+groupId+" failed.");
					}
				});
			}
			else {
				console.log("Member part of chat group: "+groupId);
				refreshGroupChat(groupId);			
			}
		},
		error: function(data) {
			console.log("Membership check for chat group: "+groupId+" failed.");
		}
	});
}


function updateUserData(userJSON){
	$.ajax({
		type: "PATCH",
		url: "https://kitchensink-1718a.firebaseio.com/users/"+firebaseUserLocalId+".json?print=silent&auth="+firebaseUserIdToken,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		data: userJSON,
		success: function(data) {
			console.log("User data update successful.");
		},
		error: function(data) {
			console.log("User data update failed.");
		}
	});
}


function sendGroupMessage(groupId){
	var sentDt = new Date();
	sentMessage = $("#chat-input").val();
	$("#chat-input").val("");

	jsonString = '{"message":"'+sentMessage+'", "name":"'+name+'", "userLocalId":"'+firebaseUserLocalId+'"}';
	$.ajax({
		type: "PATCH",
		url: "https://kitchensink-1718a.firebaseio.com/chatMessages/"+groupId+"/"+sentDt.getTime()+".json?print=silent&auth="+firebaseUserIdToken,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		data: jsonString,
		success: function(data) {
			updateChatGroupMeta(groupId);
			refreshGroupChat(groupId);
			console.log("Message posted to chat group: "+groupId+" successfully.");
		},
		error: function(data) {
			console.log("Message post to chat group: "+groupId+" failed.");
		}
	});
}


function updateChatGroupMeta(groupId){
	$.ajax({
		type: "GET",
		url: "https://kitchensink-1718a.firebaseio.com/chatMessages/"+groupId+".json?orderBy=\"$key\"&limitToLast=1&print=silent&auth="+firebaseUserIdToken,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		success: function(data) {
			if(data != null){
				timestamp = Object.keys(data)[0];
				message = data[timestamp]["name"] + ":" + data[timestamp]["message"].substr(0, 100);
				jsonString = '{"title":"Underwriters Helpdesk", "message":"'+message+'", "timestamp":"'+timestamp+'"}';
				$.ajax({
					type: "PATCH",
					url: "https://kitchensink-1718a.firebaseio.com/chatGroups/"+groupId+".json?print=silent&auth="+firebaseUserIdToken,
					contentType: "application/json; charset=utf-8",
					dataType: "json",
					data: jsonString,
					success: function(data) {
						console.log("Metadata updated for chat group: "+groupId+" successfully.");
					},
					error: function(data) {
						console.log("Metadata updation for chat group: "+groupId+" failed.");
					}
				});
			}
			else {
				console.log("No messages in chat group: "+groupId);				
			}
		},
		error: function(data) {
			console.log("Membership check for chat group: "+groupId+" failed.");
		}
	});
}


function refreshGroupChat(groupId){
	$.ajax({
		type: "GET",
		url: "https://kitchensink-1718a.firebaseio.com/chatMessages/"+groupId+".json?orderBy=\"$key\"&print=pretty&auth="+firebaseUserIdToken,
		contentType: "application/json; charset=utf-8",
		dataType: "json",
		success: function(data) {
			if(data != null){
				var messageHTML = '';
				$.each(data, function(timestamp, messageObject) {
					if(messageObject["userLocalId"] == firebaseUserLocalId){
						messageHTML += '<div class="row msg_container base_sent">';
						messageHTML += '<div class="col-md-10 col-xs-10">';
						messageHTML += '<div class="messages msg_sent">';
						messageHTML += '<p>'+messageObject["message"]+'</p>';
						messageHTML += '<time datetime="'+timestamp+'">'+messageObject["name"]+' • <span>Just Now</span></time>';
						messageHTML += '</div>';
						messageHTML += '</div>';
						messageHTML += '<div class="col-md-2 col-xs-2 avatar">';
						messageHTML += '<img src="/public/images/profile-icon.png" alt="" class=" img-responsive">';
						messageHTML += '</div>';
						messageHTML += '</div>';
					}
					else{
						messageHTML += '<div class="row msg_container base_receive">';
						messageHTML += '<div class="col-md-2 col-xs-2 avatar">';
						messageHTML += '<img src="/public/images/profile-icon.png" alt="" class=" img-responsive ">';
						messageHTML += '</div>';
						messageHTML += '<div class="col-md-10 col-xs-10">';
						messageHTML += '<div class="messages msg_receive">';
						messageHTML += '<p>'+messageObject["message"]+'</p>';
						messageHTML += '<time datetime="'+timestamp+'">'+messageObject["name"]+' • <span>Just Now</span></time>';
						messageHTML += '</div>';
						messageHTML += '</div>';
						messageHTML += '</div>';
					}
				});
				$(".panel-body "+chatType).html(messageHTML);
				$(".panel-body").stop().animate({ scrollTop: $(".panel-body").prop("scrollHeight") }, 1000);
				updateMessageTimeStamp();
				console.log("Chat group: "+groupId+" refreshed successfully.");
			}
			else {
				console.log("No messages in chat group: "+groupId);				
			}
			setTimeout(function(){ refreshGroupChat(groupId); }, 1000);
		},
		error: function(data) {
			console.log("Refresh for chat group: "+groupId+" failed.");
			setTimeout(function(){ refreshGroupChat(groupId); }, 1000);
		}
	});
}




// Single chat functions
function openSingleChat(targetUserId){

}