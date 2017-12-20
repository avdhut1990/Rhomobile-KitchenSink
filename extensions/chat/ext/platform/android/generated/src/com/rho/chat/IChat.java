package com.rho.chat;



import java.util.Map;
import java.util.List;

import com.rhomobile.rhodes.api.IMethodResult;
import com.rhomobile.rhodes.api.IRhoApiObject;

import com.rhomobile.rhodes.api.IRhoApiPropertyBag;

public interface IChat extends IRhoApiObject, IRhoApiPropertyBag {

    void getSimpleStringProperty(IMethodResult result);
    void setSimpleStringProperty(String simpleStringProperty, IMethodResult result);
    void init(String google_api_key, String google_app_id, String gcm_sender_id, String google_project_id, String google_storage_bucket, IMethodResult result);
};
