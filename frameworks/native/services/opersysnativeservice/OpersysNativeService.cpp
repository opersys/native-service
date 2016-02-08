
#include <stdint.h>
#include <math.h>
#include <sys/types.h>

#include <utils/Errors.h>
#include <utils/RefBase.h>
#include <utils/Singleton.h>
#include <utils/String16.h>

#include <binder/BinderService.h>
#include <binder/IServiceManager.h>

#include <opersys/IOpersysNativeService.h>

#include "OpersysNativeService.h"

namespace android {
// ---------------------------------------------------------------------------

OpersysNativeService::OpersysNativeService()
{
}

int OpersysNativeService::readValue(int myvalue)
{
  ALOGD("*************** readValue() called with value %d *******************", myvalue);

  return 'a';
}

int OpersysNativeService::writeValue(int myvalue)
{
  ALOGD("*************** writeValue() called with value %d *******************", myvalue);

  return '5';
}

status_t OpersysNativeService::dump(int fd, const Vector<String16>& args)
{
  ALOGD("*************** dump() called *******************");

    return NO_ERROR;
}


// ---------------------------------------------------------------------------
}; // namespace android

