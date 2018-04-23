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

EssexEngine::Drivers::MacOS::MacOSDriver::MacOSDriver(WeakPointer<Context> _context):BaseDriver(_context) {
    StartTimer();
}

EssexEngine::Drivers::MacOS::MacOSDriver::~MacOSDriver() {
}

//IInputDriver
bool EssexEngine::Drivers::MacOS::MacOSDriver::IsKeyPressed(Daemons::Input::KeyboardButton::InputKeys key) {
    return false;
}

bool EssexEngine::Drivers::MacOS::MacOSDriver::IsMousePressed(Daemons::Input::MouseButton::MouseButtons key, Daemons::Input::MouseEventLocation &data) {
    return false;
}


//ISystemDriver
void EssexEngine::Drivers::MacOS::MacOSDriver::StartTimer() {
    startTime = std::chrono::high_resolution_clock::now();
}

int EssexEngine::Drivers::MacOS::MacOSDriver::GetElapsedTime() {
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - startTime);
    return duration.count();
}

void EssexEngine::Drivers::MacOS::MacOSDriver::Sleep(int milliseconds) {
    usleep(milliseconds * 1000);
}


