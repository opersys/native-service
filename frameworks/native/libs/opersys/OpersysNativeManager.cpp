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

#define LOG_TAG "Opersys"

#include <stdint.h>
#include <sys/types.h>

#include <utils/Errors.h>
#include <utils/RefBase.h>
#include <utils/Singleton.h>

#include <binder/IBinder.h>
#include <binder/IServiceManager.h>

#include <opersys/IOpersysNativeService.h>
#include <opersys/OpersysNativeManager.h>

// ----------------------------------------------------------------------------
namespace android {
// ----------------------------------------------------------------------------

ANDROID_SINGLETON_STATIC_INSTANCE(OpersysNativeManager)

OpersysNativeManager::OpersysNativeManager()
{
}

OpersysNativeManager::~OpersysNativeManager()
{
}

void OpersysNativeManager::opersysNativeServiceDied()
{
  mOpersysNativeServer.clear();
}

status_t OpersysNativeManager::assertState() const {
    if (mOpersysNativeServer == NULL) {
        // try for one second
        const String16 name("opersysnativeservice");
        for (int i=0 ; i<4 ; i++) {
            status_t err = getService(name, &mOpersysNativeServer);
            if (err == NAME_NOT_FOUND) {
                usleep(250000);
                continue;
            }
            if (err != NO_ERROR) {
                return err;
            }
            break;
        }

        class DeathObserver : public IBinder::DeathRecipient {
            OpersysNativeManager& mOpersysNativeManager;
            virtual void binderDied(const wp<IBinder>& who) {
                ALOGW("opersysnativeservice died [%p]", who.unsafe_get());
                mOpersysNativeManager.opersysNativeServiceDied();
            }
        public:
            DeathObserver(OpersysNativeManager& mgr) : mOpersysNativeManager(mgr) { }
        };

        mDeathObserver = new DeathObserver(*const_cast<OpersysNativeManager *>(this));
        mOpersysNativeServer->asBinder()->linkToDeath(mDeathObserver);
    }

    return NO_ERROR;
}


int OpersysNativeManager::readValue(int myvalue)
{
    if (assertState() == NO_ERROR) {
      return mOpersysNativeServer->readValue(myvalue);
    }

    return -1;
}

int OpersysNativeManager::writeValue(int myvalue)
{
    if (assertState() == NO_ERROR) {
      return mOpersysNativeServer->writeValue(myvalue);
    }

    return -1;
}


// ----------------------------------------------------------------------------
}; // namespace android

