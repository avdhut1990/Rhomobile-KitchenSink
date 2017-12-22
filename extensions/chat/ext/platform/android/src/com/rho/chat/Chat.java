package com.rho.chat;

import java.util.Map;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.MethodResult;

import com.rho.chat.Dataflow;
import com.rho.chat.FCMFacade;

public class Chat extends ChatBase implements IChat {
	private static final String TAG = Chat.class.getSimpleName();
	Dataflow aiObject;

	public Chat(String id) {
		super(id);
	}


	@Override
	public void init(String google_api_key, String google_app_id, String gcm_sender_id, String google_project_id, String google_storage_bucket, String dialogflow_client_access_token, String dialogflow_language, IMethodResult result) {
		
		FCMFacade.google_api_key = google_api_key;
		FCMFacade.google_app_id = google_app_id;
		FCMFacade.gcm_sender_id = gcm_sender_id;
		FCMFacade.google_project_id = google_project_id;
		FCMFacade.google_storage_bucket = google_storage_bucket;
		
		FCMFacade.initFireBase();
		Dataflow.initDataflow(dialogflow_client_access_token, dialogflow_language);
		aiObject = new Dataflow();
		result.set(google_api_key+" | "+google_app_id+" | "+gcm_sender_id+" | "+google_project_id+" | "+google_storage_bucket);
	}


	@Override
	public void sendMessage(String query, IMethodResult result) {
		result.set(aiObject.execute(query));
	}
}