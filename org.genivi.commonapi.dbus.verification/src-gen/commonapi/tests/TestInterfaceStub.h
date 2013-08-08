/*
* This file was generated by the CommonAPI Generators.
*
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifndef COMMONAPI_TESTS_Test_Interface_STUB_H_
#define COMMONAPI_TESTS_Test_Interface_STUB_H_



#include <commonapi/tests/DerivedTypeCollection.h>

#include "TestInterface.h"

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/InputStream.h>
#include <CommonAPI/OutputStream.h>
#include <cstdint>
#include <unordered_map>
#include <vector>

#include <CommonAPI/Stub.h>
#include <CommonAPI/types.h>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace commonapi {
namespace tests {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service TestInterface. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class TestInterfaceStubAdapter: virtual public CommonAPI::StubAdapter, public TestInterface {
 public:
    ///Notifies all remote listeners about a change of value of the attribute TestPredefinedTypeAttribute.
    virtual void fireTestPredefinedTypeAttributeAttributeChanged(const uint32_t& TestPredefinedTypeAttribute) = 0;
    ///Notifies all remote listeners about a change of value of the attribute TestDerivedStructAttribute.
    virtual void fireTestDerivedStructAttributeAttributeChanged(const DerivedTypeCollection::TestStructExtended& TestDerivedStructAttribute) = 0;
    ///Notifies all remote listeners about a change of value of the attribute TestDerivedArrayAttribute.
    virtual void fireTestDerivedArrayAttributeAttributeChanged(const DerivedTypeCollection::TestArrayUInt64& TestDerivedArrayAttribute) = 0;

    /**
     * Sends a broadcast event for TestPredefinedTypeBroadcast. Should not be called directly.
     * Instead, the "fire<broadcastName>Event" methods of the stub should be used.
     */
    virtual void fireTestPredefinedTypeBroadcastEvent(const uint32_t& uint32Value, const std::string& stringValue) = 0;
};


/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for TestInterface.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class TestInterfaceStubRemoteEvent {
 public:
    virtual ~TestInterfaceStubRemoteEvent() { }

    /// Verification callback for remote set requests on the attribute TestPredefinedTypeAttribute.
    virtual bool onRemoteSetTestPredefinedTypeAttributeAttribute(const CommonAPI::ClientId& clientId, uint32_t TestPredefinedTypeAttribute) = 0;
    /// Action callback for remote set requests on the attribute TestPredefinedTypeAttribute.
    virtual void onRemoteTestPredefinedTypeAttributeAttributeChanged() = 0;

    /// Verification callback for remote set requests on the attribute TestDerivedStructAttribute.
    virtual bool onRemoteSetTestDerivedStructAttributeAttribute(const CommonAPI::ClientId& clientId, DerivedTypeCollection::TestStructExtended TestDerivedStructAttribute) = 0;
    /// Action callback for remote set requests on the attribute TestDerivedStructAttribute.
    virtual void onRemoteTestDerivedStructAttributeAttributeChanged() = 0;

    /// Verification callback for remote set requests on the attribute TestDerivedArrayAttribute.
    virtual bool onRemoteSetTestDerivedArrayAttributeAttribute(const CommonAPI::ClientId& clientId, DerivedTypeCollection::TestArrayUInt64 TestDerivedArrayAttribute) = 0;
    /// Action callback for remote set requests on the attribute TestDerivedArrayAttribute.
    virtual void onRemoteTestDerivedArrayAttributeAttributeChanged() = 0;

};


/**
 * Defines the interface that must be implemented by any class that should provide
 * the service TestInterface to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class TestInterfaceStub : public CommonAPI::Stub<TestInterfaceStubAdapter , TestInterfaceStubRemoteEvent> {
 public:
    virtual ~TestInterfaceStub() { }

    /// Provides getter access to the attribute TestPredefinedTypeAttribute.
    virtual const uint32_t& getTestPredefinedTypeAttributeAttribute(const CommonAPI::ClientId& clientId) = 0;
    /// Provides getter access to the attribute TestDerivedStructAttribute.
    virtual const DerivedTypeCollection::TestStructExtended& getTestDerivedStructAttributeAttribute(const CommonAPI::ClientId& clientId) = 0;
    /// Provides getter access to the attribute TestDerivedArrayAttribute.
    virtual const DerivedTypeCollection::TestArrayUInt64& getTestDerivedArrayAttributeAttribute(const CommonAPI::ClientId& clientId) = 0;

    /// This is the method that will be called on remote calls on the method testEmptyMethod.
    virtual void testEmptyMethod(const CommonAPI::ClientId& clientId) = 0;
    /// This is the method that will be called on remote calls on the method testVoidPredefinedTypeMethod.
    virtual void testVoidPredefinedTypeMethod(const CommonAPI::ClientId& clientId, uint32_t uint32Value, std::string stringValue) = 0;
    /// This is the method that will be called on remote calls on the method testPredefinedTypeMethod.
    virtual void testPredefinedTypeMethod(const CommonAPI::ClientId& clientId, uint32_t uint32InValue, std::string stringInValue, uint32_t& uint32OutValue, std::string& stringOutValue) = 0;
    /// This is the method that will be called on remote calls on the method testVoidDerivedTypeMethod.
    virtual void testVoidDerivedTypeMethod(const CommonAPI::ClientId& clientId, DerivedTypeCollection::TestEnumExtended2 testEnumExtended2Value, DerivedTypeCollection::TestMap testMapValue) = 0;
    /// This is the method that will be called on remote calls on the method testDerivedTypeMethod.
    virtual void testDerivedTypeMethod(const CommonAPI::ClientId& clientId, DerivedTypeCollection::TestEnumExtended2 testEnumExtended2InValue, DerivedTypeCollection::TestMap testMapInValue, DerivedTypeCollection::TestEnumExtended2& testEnumExtended2OutValue, DerivedTypeCollection::TestMap& testMapOutValue) = 0;
    
    /// Sends a broadcast event for TestPredefinedTypeBroadcast.
    virtual void fireTestPredefinedTypeBroadcastEvent(const uint32_t& uint32Value, const std::string& stringValue) = 0;
};

} // namespace tests
} // namespace commonapi

#endif // COMMONAPI_TESTS_Test_Interface_STUB_H_