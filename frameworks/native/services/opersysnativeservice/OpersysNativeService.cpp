/*
 * Copyright 2013-2016, Opersys inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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

