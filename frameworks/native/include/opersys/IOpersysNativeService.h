/*
 * (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_OPERSYS_IOPERSYS_COMPOSER_CLIENT_H
#define ANDROID_OPERSYS_IOPERSYS_COMPOSER_CLIENT_H

#include <stdint.h>
#include <sys/types.h>

#include <utils/Errors.h>
#include <utils/RefBase.h>

#include <binder/IInterface.h>

namespace android {
// ----------------------------------------------------------------------------

class IOpersysNativeService : public IInterface
{
public:
    DECLARE_META_INTERFACE(OpersysNativeService);

    virtual int readValue(int myValue) = 0;
    virtual int writeValue(int myValue) = 0;
};

// ----------------------------------------------------------------------------

class BnOpersysNativeService: public BnInterface<IOpersysNativeService> {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data,
            Parcel* reply, uint32_t flags = 0);
};

// ----------------------------------------------------------------------------

}; // namespace android

#endif // ANDROID_OPERSYS_IOPERSYS_COMPOSER_CLIENT_H
