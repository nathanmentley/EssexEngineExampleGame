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
#pragma once

#include <string>
#include <chrono>
#include <unistd.h>

#include <EssexEngineCore/WeakPointer.h>
#include <EssexEngineCore/BaseDriver.h>
#include <EssexEngineCore/Context.h>
#include <EssexEngineCore/LogDaemon.h>

#include <EssexEngineSystemDaemon/ISystemDriver.h>
#include <EssexEngineInputDaemon/IInputDriver.h>

namespace EssexEngine{
namespace Drivers{
namespace MacOS{
    class MacOSDriver:public Core::Drivers::Base::BaseDriver, public Daemons::System::ISystemDriver, public Daemons::Input::IInputDriver
    {
        public:
            MacOSDriver(WeakPointer<Context> _context);
            ~MacOSDriver();
            
            //IDriver
            void Init() {
                if(GetContext()->HasDaemon<Core::Logging::LogDaemon>()) {
                    GetContext()->GetDaemon<Core::Logging::LogDaemon>()->LogLine(
                        "Loading Driver [%s] [%s]",
                        GetDriverName().c_str(),
                        GetDriverVersion().c_str()
                    );
                }
            }
            
            //ISystemDriver
            void StartTimer();
            int GetElapsedTime();
            void Sleep(int milliseconds);
            
            //IInputDriver
            bool IsKeyPressed(Daemons::Input::KeyboardButton::InputKeys key);
            bool IsMousePressed(Daemons::Input::MouseButton::MouseButtons key,  Daemons::Input::MouseEventLocation &data);

            //BaseDriver
            std::string GetDriverName() { return "MacOS"; }
            std::string GetDriverVersion() { return ESSEX_ENGINE_VERSION; }
        private:
            std::chrono::high_resolution_clock::time_point startTime;
    };
}}};
