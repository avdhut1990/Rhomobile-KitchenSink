using System;
using System.Collections.Generic;
using System.Net;
using Windows.UI.Core;
using System.Threading.Tasks;
using rhoruntime;

namespace rho {

namespace ChatImpl
{
    public class Chat : ChatBase
    {
        public Chat(string id) : base(id)
        {
            // initialize class instance in C# here
        }

        public override void getSimpleStringProperty(IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public override void setSimpleStringProperty(string simpleStringProperty, IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public override void init(string google_api_key, string google_app_id, string gcm_sender_id, string google_project_id, string google_storage_bucket, string dialogflow_client_access_token, string dialogflow_language, IMethodResult oResult)
        {
            // implement this method in C# here
        }

        public override void sendMessage(string query, IMethodResult oResult)
        {
            // implement this method in C# here
        }
    }

    public class ChatSingleton : ChatSingletonBase
    {
        public ChatSingleton()
        {
            // initialize singleton instance in C# here
        }

        public override void enumerate(IMethodResult oResult)
        {
            // implement this method in C# here
        }
    }

    public class ChatFactory : ChatFactoryBase
    {
    }
}

}
