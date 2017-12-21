using System;
using System.Collections.Generic;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using rhoruntime;

namespace rho {

namespace ChatImpl
{
    public class Chat : ChatBase
    {
        public Chat()
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
