// ChatRuntime.cpp
#include "ChatRuntime.h"
#include "ChatFactory.h"
#include "Chat_impl.h"
#include "../../wp8/rhoruntime/common/RhoConvertWP8.h"

using namespace Platform;
using namespace rho::apiGenerator;

using namespace rho;

namespace rhoruntime
{

ChatRuntimeComponent::ChatRuntimeComponent(IChatImpl^ impl):
    _impl(impl), _cppImpl(0)
{
    // TODO: implement runtime component constructor
}

int64 ChatRuntimeComponent::getCppImpl()
{
    if (_cppImpl == 0)
    {
        _cppImpl = _impl->getNativeImpl();
    }
    return _cppImpl;
}

ChatSingletonComponent::ChatSingletonComponent(IChatSingletonImpl^ impl):
    _impl(impl)
{
    // TODO: implement singleton component constructor
}

void ChatSingletonComponent::enumerate(IMethodResult^ oResult)
{
    //((CChatImpl*)getCppImpl())->enumerate(*(CMethodResult*)(oResult->getNative()));
}

void ChatRuntimeComponent::getProperty(Platform::String^ propertyName, IMethodResult^ oResult)
{
    ((CChatImpl*)getCppImpl())->getProperty(rho::common::convertStringAFromWP8(propertyName), *(CMethodResult*)(oResult->getNative()));
}

void ChatRuntimeComponent::getProperties(Windows::Foundation::Collections::IVectorView<Platform::String^>^ arrayofNames, IMethodResult^ oResult)
{
    ((CChatImpl*)getCppImpl())->getProperties(rho::common::convertArrayFromWP8(arrayofNames), *(CMethodResult*)(oResult->getNative()));
}

void ChatRuntimeComponent::getAllProperties(IMethodResult^ oResult)
{
    ((CChatImpl*)getCppImpl())->getAllProperties(*(CMethodResult*)(oResult->getNative()));
}

void ChatRuntimeComponent::setProperty(Platform::String^ propertyName, Platform::String^ propertyValue, IMethodResult^ oResult)
{
    ((CChatImpl*)getCppImpl())->setProperty(rho::common::convertStringAFromWP8(propertyName), rho::common::convertStringAFromWP8(propertyValue), *(CMethodResult*)(oResult->getNative()));
}

void ChatRuntimeComponent::setProperties(Windows::Foundation::Collections::IMapView<Platform::String^, Platform::String^>^ propertyMap, IMethodResult^ oResult)
{
    ((CChatImpl*)getCppImpl())->setProperties(rho::common::convertHashFromWP8(propertyMap), *(CMethodResult*)(oResult->getNative()));
}

void ChatFactoryComponent::setImpl(IChatFactoryImpl^ impl)
{
    CChatFactory::setImpl(impl);
}

}