using System;
using System.Collections.Generic;
using System.Net;
using Windows.UI.Core;
using System.Threading.Tasks;
using rhoruntime;

namespace rho {

namespace ChatImpl
{
    abstract public class ChatBase : IChatImpl
    {
        protected string _strID = "1";
        protected long _nativeImpl = 0;
        protected CoreDispatcher dispatcher = null;
        protected ChatRuntimeComponent _runtime;

        public ChatBase(string id)
        {
            _strID = id;
            _runtime = new ChatRuntimeComponent(this);
            dispatcher = Windows.UI.Core.CoreWindow.GetForCurrentThread().Dispatcher;
        }

        public long getNativeImpl()
        {
            return _nativeImpl;
        }

        public virtual void setNativeImpl(string strID, long native)
        {
            _strID = strID;
            _nativeImpl = native;
        }

        public void DispatchInvoke(Action a)
        {
            if (dispatcher != null) {
              var ignore = dispatcher.RunAsync(CoreDispatcherPriority.Normal, () =>
              {try{a();} catch (Exception ex) {System.Diagnostics.Debug.WriteLine("Invoke in UI Thread exception");} });
            }else{a();}
        }

        public void getProperty(string propertyName, IMethodResult oResult)
        {
            _runtime.getProperty(propertyName, oResult);
        }

        public void getProperties(IReadOnlyList<string> arrayofNames, IMethodResult oResult)
        {
            _runtime.getProperties(arrayofNames, oResult);
        }

        public void getAllProperties(IMethodResult oResult)
        {
            _runtime.getAllProperties(oResult);
        }

        public void setProperty(string propertyName, string propertyValue, IMethodResult oResult)
        {
            _runtime.setProperty(propertyName, propertyValue, oResult);
        }

        public void setProperties(IReadOnlyDictionary<string, string> propertyMap, IMethodResult oResult)
        {
            _runtime.setProperties(propertyMap, oResult);
        }

        abstract public void getSimpleStringProperty(IMethodResult oResult);
        abstract public void setSimpleStringProperty(string simpleStringProperty, IMethodResult oResult);
        abstract public void init(string google_api_key, string google_app_id, string gcm_sender_id, string google_project_id, string google_storage_bucket, string dialogflow_client_access_token, string dialogflow_language, IMethodResult oResult);
        abstract public void sendMessage(string query, IMethodResult oResult);
    }

    abstract public class ChatSingletonBase : IChatSingletonImpl
    {

        protected SortedDictionary<string, ChatBase> keeper = new SortedDictionary<string, ChatBase>();

        public IChatImpl getChatByID(string id)
        {
            if (keeper.ContainsKey(id))
            {
                return keeper[id];
            }
            else
            {
                ChatBase impl = new Chat(id);
                keeper.Add(id, impl);
                return impl;
            }
        }

        protected ChatSingletonComponent _runtime;

        public ChatSingletonBase()
        {
            _runtime = new ChatSingletonComponent(this);
        }

        abstract public void enumerate(IMethodResult oResult);
    }

    public class ChatFactoryBase : IChatFactoryImpl
    {
        protected static ChatSingleton instance = null;
        public virtual IChatImpl getImpl(string id) {
            getSingletonImpl();
            return instance.getChatByID(id);
        }
        public IChatSingletonImpl getSingletonImpl() {
            if (instance == null){instance = new ChatSingleton();}
            return instance;
          
        }
    }
}

}
