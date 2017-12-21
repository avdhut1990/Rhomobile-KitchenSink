package com.rho.chat;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.RhoApiObject;

import com.rhomobile.rhodes.api.RhoApiPropertyBag; 

public class ChatBase extends RhoApiObject {

    private RhoApiPropertyBag mPropertyBag;
    public Map<String, String> getPropertiesMap() {
        return mPropertyBag.getPropertiesMap();
    }
    public ChatBase(String id) {
        super(id);

        mPropertyBag = new RhoApiPropertyBag(id);
    }

    public void getSimpleStringProperty(IMethodResult result) {
                     
        getProperty("simpleStringProperty", result);
    }

    public static class getSimpleStringPropertyTask implements Runnable {
        private IChat mApiObject; 
        private IMethodResult mResult;

        public getSimpleStringPropertyTask(IChat obj, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.getSimpleStringProperty(mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

    public void setSimpleStringProperty(String simpleStringProperty, IMethodResult result) {
                    
        setProperty("simpleStringProperty", String.valueOf(simpleStringProperty), result);
    }

    public static class setSimpleStringPropertyTask implements Runnable {
        private IChat mApiObject; 
        private String simpleStringProperty;
        private IMethodResult mResult;

        public setSimpleStringPropertyTask(IChat obj, 
                String simpleStringProperty, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.simpleStringProperty = simpleStringProperty;
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.setSimpleStringProperty(
                    simpleStringProperty, mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }


    public static class initTask implements Runnable {
        private IChat mApiObject; 
        private String google_api_key;
        private String google_app_id;
        private String gcm_sender_id;
        private String google_project_id;
        private String google_storage_bucket;
        private String dialogflow_client_access_token;
        private String dialogflow_language;
        private IMethodResult mResult;

        public initTask(IChat obj, 
                String google_api_key, 
                String google_app_id, 
                String gcm_sender_id, 
                String google_project_id, 
                String google_storage_bucket, 
                String dialogflow_client_access_token, 
                String dialogflow_language, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.google_api_key = google_api_key;
            this.google_app_id = google_app_id;
            this.gcm_sender_id = gcm_sender_id;
            this.google_project_id = google_project_id;
            this.google_storage_bucket = google_storage_bucket;
            this.dialogflow_client_access_token = dialogflow_client_access_token;
            this.dialogflow_language = dialogflow_language;
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.init(
                    google_api_key, 
                    google_app_id, 
                    gcm_sender_id, 
                    google_project_id, 
                    google_storage_bucket, 
                    dialogflow_client_access_token, 
                    dialogflow_language, mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

    public void getProperty(String propertyName, IMethodResult result) { 
        mPropertyBag.getProperty(propertyName, result);
    }

    public static class getPropertyTask implements Runnable {
        private IChat mApiObject; 
        private String propertyName;
        private IMethodResult mResult;

        public getPropertyTask(IChat obj, 
                String propertyName, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.propertyName = propertyName;
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.getProperty(
                    propertyName, mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

    public void getProperties(List<String> arrayofNames, IMethodResult result) { 
        mPropertyBag.getProperties(arrayofNames, result);
    }

    public static class getPropertiesTask implements Runnable {
        private IChat mApiObject; 
        private List<String> arrayofNames;
        private IMethodResult mResult;

        public getPropertiesTask(IChat obj, 
                List<String> arrayofNames, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.arrayofNames = arrayofNames;
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.getProperties(
                    arrayofNames, mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

    public void getAllProperties(IMethodResult result) { 
        mPropertyBag.getAllProperties(result);
    }

    public static class getAllPropertiesTask implements Runnable {
        private IChat mApiObject; 
        private IMethodResult mResult;

        public getAllPropertiesTask(IChat obj, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.getAllProperties(mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

    public void setProperty(String propertyName, String propertyValue, IMethodResult result) { 
        mPropertyBag.setProperty(propertyName, propertyValue, result);
    }

    public static class setPropertyTask implements Runnable {
        private IChat mApiObject; 
        private String propertyName;
        private String propertyValue;
        private IMethodResult mResult;

        public setPropertyTask(IChat obj, 
                String propertyName, 
                String propertyValue, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.propertyName = propertyName;
            this.propertyValue = propertyValue;
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.setProperty(
                    propertyName, 
                    propertyValue, mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

    public void setProperties(Map<String, String> propertyMap, IMethodResult result) { 
        mPropertyBag.setProperties(propertyMap, result);
    }

    public static class setPropertiesTask implements Runnable {
        private IChat mApiObject; 
        private Map<String, String> propertyMap;
        private IMethodResult mResult;

        public setPropertiesTask(IChat obj, 
                Map<String, String> propertyMap, 
                IMethodResult result) {
            this.mApiObject = obj; 
            this.propertyMap = propertyMap;
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiObject.setProperties(
                    propertyMap, mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

}
