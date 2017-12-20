package com.rho.chat;

import android.util.Log;

import com.rhomobile.rhodes.Logger;

import com.google.firebase.iid.FirebaseInstanceIdService;

import com.rho.chat.FCMFacade;

public class FCMTokenRefresherService extends FirebaseInstanceIdService {
    private static final String TAG = FCMTokenRefresherService.class.getSimpleName();
    
    @Override
    public void onTokenRefresh() {
        Logger.W(TAG, "FCM: onTokenRefresh()");
        FCMFacade.refreshToken();
    }
    
}