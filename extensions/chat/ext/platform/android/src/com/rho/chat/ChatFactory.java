package com.rho.chat;

import com.rhomobile.rhodes.api.RhoApiFactory;

public class ChatFactory
        extends RhoApiFactory< Chat, ChatSingleton>
        implements IChatFactory {

    @Override
    protected ChatSingleton createSingleton() {
        return new ChatSingleton(this);
    }

    @Override
    protected Chat createApiObject(String id) {
        return new Chat(id);
    }
}
