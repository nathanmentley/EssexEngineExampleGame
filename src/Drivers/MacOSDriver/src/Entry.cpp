/* 
 * Essex Engine
 * 
 * Copyright (C) 2017 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */

#include <EssexEngineMacOSDriver/MacOSDriver.h>

using EssexEngine::Context;
using EssexEngine::WeakPointer;

using EssexEngine::Daemons::System::ISystemDriver;
using EssexEngine::Drivers::MacOS::MacOSDriver;

extern "C" {
    void driver_init(WeakPointer<Context> context) {
        MacOSDriver* macDriver = new MacOSDriver(context);
        
        context->RegisterDriver<ISystemDriver>(
            WeakPointer<ISystemDriver>(macDriver)
        );
    }
}
