package com.rho.chat;

import java.util.List;

import android.text.TextUtils;
import android.util.Log;

import com.google.gson.Gson;

import com.rhomobile.rhodes.util.ContextFactory;

import org.json.JSONObject;

import ai.api.AIConfiguration;
import ai.api.AIService;
import ai.api.RequestExtras;
import ai.api.GsonFactory;
import ai.api.model.AIResponse;
import ai.api.services.GoogleRecognitionServiceImpl;

public class Dataflow {
	private static final String TAG = Dataflow.class.getName();

	// public static final String RECORD_AUDIO = Manifest.permission.RECORD_AUDIO;
    public static final int AUDIO_REQ_CODE = 17;

    private static AIService aiService;
	private static Gson gson;	

	public static void initDataflow(String clientAccessToken, String language) {
		try{
			final AIConfiguration.SupportedLanguages lang = AIConfiguration.SupportedLanguages.fromLanguageTag(language);
			final AIConfiguration config = new AIConfiguration(clientAccessToken, lang, AIConfiguration.RecognitionEngine.System);

			aiService = AIService.getService(ContextFactory.getContext(), config);
		}
		catch(Exception ex){
			Log.e(TAG, "Init", ex);
		}
	}


	public String execute(String query){
		gson = GsonFactory.getGson();
		RequestExtras requestExtras = new RequestExtras();
		return textRequest(query, requestExtras);
	}


	public String textRequest(final String query, final RequestExtras requestExtras){
		String jsonResponse = "";
		try{
			AIResponse response = aiService.textRequest(query, requestExtras);
			jsonResponse = gson.toJson(response);
			JSONObject jsonObject = new JSONObject(jsonResponse);
			Log.d(TAG, "jsonResponse:"+jsonResponse);
		}
		catch(Exception ex){
			Log.e(TAG, "textRequest", ex);
		}
		return jsonResponse;
	}
}