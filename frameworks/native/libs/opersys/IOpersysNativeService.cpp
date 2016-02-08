#define LOG_TAG "OpersysNativeService"

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>

#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#include <opersys/IOpersysNativeService.h>

namespace android {

enum {
    READ_VALUE = IBinder::FIRST_CALL_TRANSACTION,
    WRITE_VALUE
};

class BpOpersysNativeService : public BpInterface<IOpersysNativeService>
{
public:
    BpOpersysNativeService(const sp<IBinder>& impl)
        : BpInterface<IOpersysNativeService>(impl)
    {
    }

    virtual int readValue(int myValue)
    {
      Parcel data, reply;

      data.writeInterfaceToken(IOpersysNativeService::getInterfaceDescriptor());
      data.writeInt32(myValue);
      remote()->transact(READ_VALUE, data, &reply);
      return (int) reply.readInt32();
    }


    virtual int writeValue(int myValue)
    {
      Parcel data, reply;

      data.writeInterfaceToken(IOpersysNativeService::getInterfaceDescriptor());
      data.writeInt32(myValue);
      remote()->transact(WRITE_VALUE, data, &reply);
      return (int) reply.readInt32();
    }
};

IMPLEMENT_META_INTERFACE(OpersysNativeService, "android.opersys.OpersysNativeService");

status_t BnOpersysNativeService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
  switch(code) {
    case READ_VALUE: {
      CHECK_INTERFACE(IOpersysNativeService, data, reply);
      uint32_t myvalue = data.readInt32();      
      int retval = readValue((int)myvalue);
      reply->writeInt32(retval);
      return NO_ERROR;
    } break;
    case WRITE_VALUE: {
      CHECK_INTERFACE(IOpersysNativeService, data, reply);
      uint32_t myvalue = data.readInt32();      
      int retval = writeValue((int)myvalue);
      reply->writeInt32(retval);
      return NO_ERROR;
    } break;
    default:
      return BBinder::onTransact(code, data, reply, flags);
    }
}

}; // namespace android
