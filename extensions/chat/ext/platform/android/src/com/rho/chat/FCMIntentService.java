package com.rho.chat;

import java.util.HashMap;
import java.util.Map;

import com.rhomobile.rhodes.Logger;
import com.rhomobile.rhodes.PushContract;
import com.rhomobile.rhodes.util.ContextFactory;

import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

import org.json.JSONException;
import org.json.JSONObject;

import com.rho.chat.FCMFacade;

public class FCMIntentService extends FirebaseMessagingService {
	private static final String TAG = FCMIntentService.class.getSimpleName();

	@Override
	public void onMessageReceived(RemoteMessage remoteMessage) {
		Map<String, String> params = new HashMap<String, String>(); 
		params.put("id", remoteMessage.getMessageId());
		params.put("from", remoteMessage.getFrom());
		params.put("to", remoteMessage.getTo());
		params.put("body", remoteMessage.getNotification().getBody());
		params.put("title", remoteMessage.getNotification().getTitle());
		params.put("tag", remoteMessage.getNotification().getTag());
		JSONObject jsonObject = new JSONObject(params);
		try {
			jsonObject.put("data", new JSONObject(remoteMessage.getData()));
		} catch (JSONException e) {
			e.printStackTrace();
		}

		Logger.W(TAG, "FCM: push message: " + remoteMessage.getNotification().getBody());
		Logger.W(TAG, "FCM: push message in JSON: " + jsonObject.toString());
		PushContract.handleMessage(ContextFactory.getContext(), jsonObject.toString(), FCMFacade.FCM_PUSH_CLIENT);
	}
}