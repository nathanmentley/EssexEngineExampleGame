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

extern "C" {
    void driver_init(EssexEngine::Context* context) {
        EssexEngine::Drivers::MacOS::MacOSDriver* macOSDriver = new EssexEngine::Drivers::MacOS::MacOSDriver(context);
        
        context->RegisterDriver<EssexEngine::Daemons::System::ISystemDriver>(macOSDriver);
        context->RegisterDriver<EssexEngine::Daemons::Input::IInputDriver>(macOSDriver);
    }
}
