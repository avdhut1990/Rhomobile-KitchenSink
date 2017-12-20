package com.rho.chat;

import com.rhomobile.rhodes.api.IRhoApiFactory;
import com.rhomobile.rhodes.api.IRhoApiSingletonFactory;

public interface IChatFactory
    extends IRhoApiFactory<IChat>,
            IRhoApiSingletonFactory<IChatSingleton> {

    @Override
    IChatSingleton getApiSingleton();

    @Override
    IChat getApiObject(String id);

}
