#include "ruby.h"

static VALUE rb_api_mParent;
static VALUE rb_api_mChat;

VALUE rb_Chat_getSimpleStringProperty(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Chat_def_getSimpleStringProperty(int argc, VALUE *argv);
VALUE rb_Chat_setSimpleStringProperty(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Chat_def_setSimpleStringProperty(int argc, VALUE *argv);
VALUE rb_s_Chat_enumerate(int argc, VALUE *argv);
VALUE rb_Chat_init(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Chat_def_init(int argc, VALUE *argv);
VALUE rb_Chat_sendMessage(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Chat_def_sendMessage(int argc, VALUE *argv);
VALUE rb_Chat_getProperty(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Chat_def_getProperty(int argc, VALUE *argv);
VALUE rb_Chat_getProperties(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Chat_def_getProperties(int argc, VALUE *argv);
VALUE rb_Chat_getAllProperties(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Chat_def_getAllProperties(int argc, VALUE *argv);
VALUE rb_Chat_setProperty(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Chat_def_setProperty(int argc, VALUE *argv);
VALUE rb_Chat_setProperties(int argc, VALUE *argv, VALUE obj);
VALUE rb_s_Chat_def_setProperties(int argc, VALUE *argv);



VALUE rb_Chat_s_default(VALUE klass);
VALUE rb_Chat_s_setDefault(VALUE klass, VALUE obj);


VALUE getRuby_Chat_Module(){ return rb_api_mChat; }



static void _free_class_object(void *p)
{
    ruby_xfree(p);
}

static VALUE _allocate_class_object(VALUE klass)
{
    VALUE valObj = 0;
    char ** ppString = NULL;
    void* pData = ALLOC(void*);
    memset( pData, 0, sizeof(pData) );
    
	valObj = Data_Wrap_Struct(klass, 0, _free_class_object, pData);

    Data_Get_Struct(valObj, char *, ppString);
    *ppString = xmalloc(10);
    sprintf(*ppString, "%X", valObj);

    return valObj;
}

void Init_RubyAPI_Chat(void)
{

    VALUE tmpParent = Qnil;
    rb_api_mParent = rb_define_module("Rho");
    

	rb_api_mChat = rb_define_class_under(rb_api_mParent, "Chat", rb_cObject);

	rb_define_alloc_func(rb_api_mChat, _allocate_class_object);
    //Constructor should be not available in case of static members
    //rb_undef_alloc_func(rb_api_mChat);

    rb_define_method(rb_api_mChat, "simpleStringProperty", rb_Chat_getSimpleStringProperty, -1);
    rb_define_singleton_method(rb_api_mChat, "simpleStringProperty", rb_s_Chat_def_getSimpleStringProperty, -1);
    rb_define_method(rb_api_mChat, "simpleStringProperty=", rb_Chat_setSimpleStringProperty, -1);
    rb_define_singleton_method(rb_api_mChat, "simpleStringProperty=", rb_s_Chat_def_setSimpleStringProperty, -1);
    rb_define_singleton_method(rb_api_mChat, "enumerate", rb_s_Chat_enumerate, -1);
    rb_define_method(rb_api_mChat, "init", rb_Chat_init, -1);
    rb_define_singleton_method(rb_api_mChat, "init", rb_s_Chat_def_init, -1);
    rb_define_method(rb_api_mChat, "sendMessage", rb_Chat_sendMessage, -1);
    rb_define_singleton_method(rb_api_mChat, "sendMessage", rb_s_Chat_def_sendMessage, -1);
    rb_define_method(rb_api_mChat, "getProperty", rb_Chat_getProperty, -1);
    rb_define_singleton_method(rb_api_mChat, "getProperty", rb_s_Chat_def_getProperty, -1);
    rb_define_method(rb_api_mChat, "getProperties", rb_Chat_getProperties, -1);
    rb_define_singleton_method(rb_api_mChat, "getProperties", rb_s_Chat_def_getProperties, -1);
    rb_define_method(rb_api_mChat, "getAllProperties", rb_Chat_getAllProperties, -1);
    rb_define_singleton_method(rb_api_mChat, "getAllProperties", rb_s_Chat_def_getAllProperties, -1);
    rb_define_method(rb_api_mChat, "setProperty", rb_Chat_setProperty, -1);
    rb_define_singleton_method(rb_api_mChat, "setProperty", rb_s_Chat_def_setProperty, -1);
    rb_define_method(rb_api_mChat, "setProperties", rb_Chat_setProperties, -1);
    rb_define_singleton_method(rb_api_mChat, "setProperties", rb_s_Chat_def_setProperties, -1);



    rb_define_singleton_method(rb_api_mChat, "getDefault", rb_Chat_s_default, 0);
    rb_define_singleton_method(rb_api_mChat, "setDefault", rb_Chat_s_setDefault, 1);






}

