package com.rho.chat;

import java.lang.Throwable;

import android.util.Log;

import com.rhomobile.rhodes.Logger;
import com.rhomobile.rhodes.PushContract;
import com.rhomobile.rhodes.util.ContextFactory;

import com.google.firebase.FirebaseApp;
import com.google.firebase.FirebaseOptions;
import com.google.firebase.iid.FirebaseInstanceId;


public class FCMFacade {
    private static final String TAG = FCMFacade.class.getSimpleName();

    static final String FCM_PUSH_CLIENT = "fcm";
    static String clientToken = "";
    static String google_api_key = "";
    static String google_app_id = "";
    static String gcm_sender_id = "";
    static String google_project_id = "";
    static String google_storage_bucket = "";


    public static void initFireBase() {
        Log.d(TAG, "FCM: Send FCM push register req");

        try{
            FirebaseApp.getInstance();
            Logger.T(TAG, "FCM: Firebase inited");
        }catch(Exception exc){
            FirebaseOptions options = null;
            try {
                options = new FirebaseOptions.Builder()
                .setApiKey(google_api_key)
                .setApplicationId(google_app_id)
                //.setDatabaseUrl(gStr(R.string.firebase_database_url))
                .setGcmSenderId(gcm_sender_id)
                .setProjectId(google_project_id)
                .setStorageBucket(google_storage_bucket)
                .build();
            } catch( Throwable e ) {
                Logger.E(TAG, "FCM: poblems on building options: " + e);
                e.printStackTrace();
            }

            try{
                FirebaseApp.initializeApp(ContextFactory.getContext(), options);
                Logger.T(TAG, "FCM: initialization of application");
            }catch(Exception e){
                Logger.E(TAG, "FCM: poblems on initialization app: " + e);
                e.printStackTrace();
            }
            try{
                FirebaseApp.getInstance();
                Logger.T(TAG, "FCM: Firebase Inited");                
            }catch(Exception e){
                Logger.E(TAG, "FCM: poblems on getting instance: " + e);
                e.printStackTrace();
            }
        }
        refreshToken();       
    }


    public static void refreshToken(){
        try{
            Log.d(TAG, "FCM: registation of application");
            clientToken = "";
            clientToken = FirebaseInstanceId.getInstance().getToken();
            if ((clientToken != "")&&(clientToken != null)){
                PushContract.handleRegistration(ContextFactory.getContext(), clientToken, FCMFacade.FCM_PUSH_CLIENT);
                Log.d(TAG, "FCM: registation successfully");
            }else{
                clientToken = "";
                Log.d(TAG, "FCM: can't get token, try to refresh later");
            }
        }catch(Exception exc){
            Log.d(TAG, "FCM: can't handle registation");
        }
        Log.d(TAG, "FCM: token = " + clientToken);
    }
}