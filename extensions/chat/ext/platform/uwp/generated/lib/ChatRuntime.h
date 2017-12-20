#pragma once

#include "../../../../shared/generated/cpp/IChat.h"
#include "api_generator/uwp/IMethodResult.h"

namespace rhoruntime
{
    public interface class IChatImpl
    {
    public:
        int64 getNativeImpl();
        void setNativeImpl(Platform::String^ strID, int64 native);


        void getSimpleStringProperty(IMethodResult^ oResult);
        void setSimpleStringProperty(Platform::String^ simpleStringProperty, IMethodResult^ oResult);
        void getPlatformName(IMethodResult^ oResult);
        void calcSumm(int a, int b, IMethodResult^ oResult);
        void joinStrings(Platform::String^ a, Platform::String^ b, IMethodResult^ oResult);
        void getProperty(Platform::String^ propertyName, IMethodResult^ oResult);
        void getProperties(Windows::Foundation::Collections::IVectorView<Platform::String^>^ arrayofNames, IMethodResult^ oResult);
        void getAllProperties(IMethodResult^ oResult);
        void setProperty(Platform::String^ propertyName, Platform::String^ propertyValue, IMethodResult^ oResult);
        void setProperties(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult);
    };

    public interface class IChatSingletonImpl
    {
    public:
        void enumerate(IMethodResult^ oResult);
    };
    public interface class IChatFactoryImpl
    {
    public:
        IChatImpl^ getImpl(Platform::String^ id);
        IChatSingletonImpl^ getSingletonImpl();
    };

    public ref class ChatRuntimeComponent sealed
    {
    public:
        ChatRuntimeComponent(IChatImpl^ impl);
        void getProperty(Platform::String^ propertyName, IMethodResult^ oResult);
        void getProperties(Windows::Foundation::Collections::IVectorView<Platform::String^>^ arrayofNames, IMethodResult^ oResult);
        void getAllProperties(IMethodResult^ oResult);
        void setProperty(Platform::String^ propertyName, Platform::String^ propertyValue, IMethodResult^ oResult);
        void setProperties(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult);
    private:
        IChatImpl^ _impl;
        int64 _cppImpl;
        int64 getCppImpl();
    };

    public ref class ChatSingletonComponent sealed: public IChatSingletonImpl
    {
    public:
        ChatSingletonComponent(IChatSingletonImpl^ impl);
        virtual void enumerate(IMethodResult^ oResult);
    private:
        IChatSingletonImpl^ _impl;
    };

    public ref class ChatFactoryComponent sealed
    {
    public:
        static void setImpl(IChatFactoryImpl^ impl);
    };
}
