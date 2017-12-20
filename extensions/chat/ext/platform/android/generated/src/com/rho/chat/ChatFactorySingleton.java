package com.rho.chat;

public class ChatFactorySingleton {
    private static IChatFactory mFactory;
    public static void setInstance(IChatFactory factory) {
        mFactory = factory;
    }
    public static IChatFactory getInstance() {
        return mFactory;
    }
}
