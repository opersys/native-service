#ifndef ANDROID_OPERSYS_NATIVE_SERVICE_H
#define ANDROID_OPERSYS_NATIVE_SERVICE_H

#include <stdint.h>
#include <sys/types.h>

#include <cutils/compiler.h>

#include <utils/Atomic.h>
#include <utils/Errors.h>
#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <utils/SortedVector.h>
#include <utils/threads.h>

#include <binder/BinderService.h>

#include <opersys/IOpersysNativeService.h>

namespace android {

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
class OpersysNativeService : public BinderService<OpersysNativeService>,
                       public BnOpersysNativeService
{
public:
    static char const* getServiceName() {
        return "opersysnativeservice";
    }

    OpersysNativeService();

private:
    virtual int readValue(int myvalue);
    virtual int writeValue(int myvalue);
    virtual status_t dump(int fd, const Vector<String16>& args);
};

// ---------------------------------------------------------------------------
}; // namespace android

#endif // ANDROID_OPERSYS_NATIVE_SERVICE_H
