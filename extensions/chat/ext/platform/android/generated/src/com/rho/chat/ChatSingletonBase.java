package com.rho.chat;

import java.util.List;
import java.util.Map;

import com.rhomobile.rhodes.api.IMethodResult;

import com.rhomobile.rhodes.api.RhoApiDefaultId;

public abstract class ChatSingletonBase 
    extends RhoApiDefaultId<IChat, IChatFactory>  {

    public ChatSingletonBase(IChatFactory factory) {
        super(factory);
    } 

    public static class enumerateTask implements Runnable {
        private IChatSingleton mApiSingleton; 
        private IMethodResult mResult;

        public enumerateTask(IChatSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            try {
                mApiSingleton.enumerate( mResult);
            } catch (Throwable ex) {
                mResult.set(ex);
            }
        }
    }

    
}
