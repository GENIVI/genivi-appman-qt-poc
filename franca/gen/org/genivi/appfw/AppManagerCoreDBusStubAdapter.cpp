/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.1.5.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <org/genivi/appfw/AppManagerCore.hpp>
#include <org/genivi/appfw/AppManagerCoreDBusStubAdapter.hpp>

namespace org {
namespace genivi {
namespace appfw {

std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> createAppManagerCoreDBusStubAdapter(
                   const CommonAPI::DBus::DBusAddress &_address,
                   const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
                   const std::shared_ptr<CommonAPI::StubBase> &_stub) {
    return std::make_shared<AppManagerCoreDBusStubAdapter>(_address, _connection, _stub);
}

INITIALIZER(registerAppManagerCoreDBusStubAdapter) {
    CommonAPI::DBus::Factory::get()->registerStubAdapterCreateMethod(
    	AppManagerCore::getInterface(), &createAppManagerCoreDBusStubAdapter);
}

AppManagerCoreDBusStubAdapterInternal::~AppManagerCoreDBusStubAdapterInternal() {
    deactivateManagedInstances();
    AppManagerCoreDBusStubAdapterHelper::deinit();
}

void AppManagerCoreDBusStubAdapterInternal::deactivateManagedInstances() {

}

const char* AppManagerCoreDBusStubAdapterInternal::getMethodsDBusIntrospectionXmlData() const {
    static const std::string introspectionData =
        "<method name=\"getInterfaceVersion\">\n"
            "<arg name=\"value\" type=\"uu\" direction=\"out\" />"
        "</method>\n"
        /**
         * description: This broadcast is emitted whenever there is addition or deletion of apps,
         *   change in capability of 
        		apps to handle mimes or similar changes.It is
         *   recommended to call getInstalledApps and getAppInfo (on interested apps)
        		as
         *   needed when this broadcast is received.
         */
        "<signal name=\"appsInfoUpdated\">\n"
        "</signal>\n"
        /**
         * description: This method returns an array of app IDs which are reverse DNS style names
         *   stored by app manager 
        		during app installation
         */
        "<method name=\"getInstalledApps\">\n"
            "<arg name=\"_AppIds\" type=\"as\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * description: This method provides the information of the app from manifest data encapsulated
         *   in the AppInfo struct.
        		AppId is a reverse DNS style name of the app which
         *   should be a part of manifest information.
         */
        "<method name=\"getAppInfo\">\n"
            "<arg name=\"_AppId\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"_Info\" type=\"(a{ss})\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * description: This method launches an app using the AppId. App manager resolves the AppId to
         *   an entry point 
        		and launches it.
         */
        "<method name=\"launchApp\">\n"
            "<arg name=\"_AppId\" type=\"s\" direction=\"in\" />\n"
        "</method>\n"

    ;
    return introspectionData.c_str();
}

CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        ::org::genivi::appfw::AppManagerCoreStub,
        CommonAPI::Version
        > AppManagerCoreDBusStubAdapterInternal::getAppManagerCoreInterfaceVersionStubDispatcher(&AppManagerCoreStub::getInterfaceVersion, "uu");




/**
 * description: This method returns an array of app IDs which are reverse DNS style names
 *   stored by app manager 
		during app installation
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::org::genivi::appfw::AppManagerCoreStub,
    std::tuple<>,
    std::tuple<std::vector<std::string>>,
    std::tuple<>,
    std::tuple<CommonAPI::DBus::ArrayDeployment<CommonAPI::DBus::StringDeployment>>
    
    > AppManagerCoreDBusStubAdapterInternal::getInstalledAppsStubDispatcher(
    &AppManagerCoreStub::getInstalledApps, "as",
					std::make_tuple(),
                	std::make_tuple(static_cast<CommonAPI::DBus::ArrayDeployment<CommonAPI::DBus::StringDeployment>*>(nullptr)));

/**
 * description: This method provides the information of the app from manifest data encapsulated
 *   in the AppInfo struct.
		AppId is a reverse DNS style name of the app which
 *   should be a part of manifest information.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::org::genivi::appfw::AppManagerCoreStub,
    std::tuple<std::string>,
    std::tuple<AppManagerCore::AppInfo>,
    std::tuple<CommonAPI::DBus::StringDeployment>,
    std::tuple<AppManagerCore_::AppInfoDeployment_t>
    
    > AppManagerCoreDBusStubAdapterInternal::getAppInfoStubDispatcher(
    &AppManagerCoreStub::getAppInfo, "(a{ss})",
					std::make_tuple(static_cast<CommonAPI::DBus::StringDeployment*>(nullptr)),
                	std::make_tuple(static_cast<AppManagerCore_::AppInfoDeployment_t*>(nullptr)));

/**
 * description: This method launches an app using the AppId. App manager resolves the AppId to
 *   an entry point 
		and launches it.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::org::genivi::appfw::AppManagerCoreStub,
    std::tuple<std::string>,
    std::tuple<>,
    std::tuple<CommonAPI::DBus::StringDeployment>,
    std::tuple<>
    
    > AppManagerCoreDBusStubAdapterInternal::launchAppStubDispatcher(
    &AppManagerCoreStub::launchApp, "",
					std::make_tuple(static_cast<CommonAPI::DBus::StringDeployment*>(nullptr)),
                	std::make_tuple());



/**
 * description: This broadcast is emitted whenever there is addition or deletion of apps,
 *   change in capability of 
		apps to handle mimes or similar changes.It is
 *   recommended to call getInstalledApps and getAppInfo (on interested apps)
		as
 *   needed when this broadcast is received.
 */
void AppManagerCoreDBusStubAdapterInternal::fireAppsInfoUpdatedEvent() {
    CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<
    >>::sendSignal(
            *this,
            "appsInfoUpdated",
            ""
    );
}


const AppManagerCoreDBusStubAdapterHelper::StubDispatcherTable& AppManagerCoreDBusStubAdapterInternal::getStubDispatcherTable() {
    return stubDispatcherTable_;
}

const CommonAPI::DBus::StubAttributeTable& AppManagerCoreDBusStubAdapterInternal::getStubAttributeTable() {
    return stubAttributeTable_;
}

AppManagerCoreDBusStubAdapterInternal::AppManagerCoreDBusStubAdapterInternal(
        const CommonAPI::DBus::DBusAddress &_address,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub)
	: CommonAPI::DBus::DBusStubAdapter(_address, _connection,false),
      AppManagerCoreDBusStubAdapterHelper(_address, _connection, std::dynamic_pointer_cast<AppManagerCoreStub>(_stub), false),
      stubDispatcherTable_({
            /**
             * description: This method returns an array of app IDs which are reverse DNS style names
             *   stored by app manager 
            		during app installation
             */
            { { "getInstalledApps", "" }, &org::genivi::appfw::AppManagerCoreDBusStubAdapterInternal::getInstalledAppsStubDispatcher },
            /**
             * description: This method provides the information of the app from manifest data encapsulated
             *   in the AppInfo struct.
            		AppId is a reverse DNS style name of the app which
             *   should be a part of manifest information.
             */
            { { "getAppInfo", "s" }, &org::genivi::appfw::AppManagerCoreDBusStubAdapterInternal::getAppInfoStubDispatcher },
            /**
             * description: This method launches an app using the AppId. App manager resolves the AppId to
             *   an entry point 
            		and launches it.
             */
            { { "launchApp", "s" }, &org::genivi::appfw::AppManagerCoreDBusStubAdapterInternal::launchAppStubDispatcher }
            }),
        stubAttributeTable_() {

    stubDispatcherTable_.insert({ { "getInterfaceVersion", "" }, &org::genivi::appfw::AppManagerCoreDBusStubAdapterInternal::getAppManagerCoreInterfaceVersionStubDispatcher });
}

bool AppManagerCoreDBusStubAdapterInternal::hasFreedesktopProperties() {
    return false;
}

} // namespace appfw
} // namespace genivi
} // namespace org
