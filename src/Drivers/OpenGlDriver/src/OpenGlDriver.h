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
#include <map>
#include <utility>

#include <GLFW/glfw3.h>
#include <png.h>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#endif

#include <EssexEngineCore/WeakPointer.h>
#include <EssexEngineCore/CachedPointer.h>
#include <EssexEngineCore/BaseDriver.h>
#include <EssexEngineCore/Context.h>
#include <EssexEngineCore/LogDaemon.h>

#include <EssexEngineGfxDaemon/IGfxDriver.h>

#include <EssexEngineOpenGlDriver/OpenGlSprite.h>

namespace EssexEngine{
namespace Drivers{
namespace OpenGl{
    class OpenGlDriver:public Core::Drivers::Base::BaseDriver, public Daemons::Gfx::IGfxDriver
    {
    public:
        OpenGlDriver(WeakPointer<Context> _context);
        ~OpenGlDriver();
        
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
        
        //IGfxDriver
        void Setup(WeakPointer<Daemons::Window::IRenderContext> target);
        
        void StartRender(WeakPointer<Daemons::Window::IRenderContext> target);
        void FinishRender(WeakPointer<Daemons::Window::IRenderContext> target);
        
        void RenderEntity(WeakPointer<Daemons::Window::IRenderContext> target, WeakPointer<Daemons::Gfx::Entity> entity);
        void RenderModel(WeakPointer<Daemons::Window::IRenderContext> target, WeakPointer<Daemons::Gfx::Model> model);
        void RenderString(WeakPointer<Daemons::Window::IRenderContext> target, std::string data, int x, int y);
        
        WeakPointer<Daemons::Gfx::ISprite> GetSprite(CachedPointer<std::string, Daemons::FileSystem::IFileBuffer> fileContent, int _x, int _y, int _width, int _height);
        
        //BaseDriver
        std::string GetDriverName() { return "OpenGl"; }
        std::string GetDriverVersion() { return ESSEX_ENGINE_VERSION; }
    private:
        bool LoadPngImage(WeakPointer<Daemons::FileSystem::IFileBuffer> file, int &w, int &h, bool &hasAlpha, GLubyte** data);
        std::map<std::string, GLuint> textureCache;

        //glfw window context (this isn't our actual window. Because OpenGL is pretty hard tied to windows we're using a hidden window)
        //  This will be our GFX's rendering buffer in the backgroud, but we'll generically pass the output to the abstract
        //  window daemon.
        GLFWwindow* window;
    };
}}};
