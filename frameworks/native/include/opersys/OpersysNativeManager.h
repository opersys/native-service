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
