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
