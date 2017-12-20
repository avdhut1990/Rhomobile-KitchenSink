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
import ai.api.services.GoogleRecognitionServiceImpl;

public class ApiAi {
	private static final String TAG = ApiAi.class.getName();

	public static final String RECORD_AUDIO = Manifest.permission.RECORD_AUDIO;
    public static final int AUDIO_REQ_CODE = 17;

    private AIService aiService;
	private Gson gson;	

	public void init(final JSONObject argObject) {
		try{
			gson = GsonFactory.getGson();
			final String baseURL = argObject.optString("baseURL", "https://api.api.ai/v1/"); 
			final String clientAccessToken = argObject.getString("clientAccessToken"); 
			final String language = argObject.optString("lang", "en");
			final boolean debugMode = argObject.optBoolean("debug", false);
			final String version = argObject.optString("version", "20150910");

			final AIConfiguration.SupportedLanguages lang = AIConfiguration.SupportedLanguages.fromLanguageTag(language);
			final AIConfiguration config = new AIConfiguration(clientAccessToken, lang, AIConfiguration.RecognitionEngine.System);

			if (!TextUtils.isEmpty(version)) {
				config.setProtocolVersion(version);
			}

			aiService = AIService.getService(ContextFactory.getContext(), config);
			aiService.setListener(this);

			if (aiService instanceof GoogleRecognitionServiceImpl) {
				((GoogleRecognitionServiceImpl) aiService).setPartialResultsListener(new PartialResultsListener() {
					@Override
					public void onPartialResults(final List<String> partialResults) {
						ApiAiPlugin.this.onPartialResults(partialResults);
					}
				});
			}
		}
		catch(Exception ex){
			Log.e(TAG, "Init", ex);
		}
	}


	public void textRequest(final String query, final RequestExtras requestExtras){
		try{
			final AIResponse response = aiService.textRequest(query, requestExtras);
			final String jsonResponse = gson.toJson(response);
			final JSONObject jsonObject = new JSONObject(jsonResponse);
		}
		catch(Exception ex){
			Log.e(TAG, "textRequest", ex);
		}
	}
}