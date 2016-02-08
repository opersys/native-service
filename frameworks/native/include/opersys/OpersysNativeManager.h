#ifndef ANDROID_OPERSYS_OPERSYS_NATIVE_SERVICE_H
#define ANDROID_OPERSYS_OPERSYS_NATIVE_SERVICE_H

#include <stdint.h>
#include <sys/types.h>

#include <binder/IBinder.h>

#include <utils/RefBase.h>
#include <utils/Singleton.h>
#include <utils/threads.h>

namespace android {
// ---------------------------------------------------------------------------

class OpersysNativeManager : public Singleton<OpersysNativeManager>
{
public:
    OpersysNativeManager();
    ~OpersysNativeManager();

    int readValue(int myvalue);
    int writeValue(int myvalue);

private:
    // DeathRecipient interface
    void opersysNativeServiceDied();
    status_t assertState() const;

    mutable sp<IOpersysNativeService> mOpersysNativeServer;
    mutable sp<IBinder::DeathRecipient> mDeathObserver;
};

}; // namespace android

#endif // ANDROID_OPERSYS_OPERSYS_NATIVE_SERVICE_H
