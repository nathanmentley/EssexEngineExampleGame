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

#include <OpenGL/gl.h>

#include <EssexEngineCore/CachedPointer.h>
#include <EssexEngineGfxDaemon/IGfxDriver.h>
#include <EssexEngineFileSystemDaemon/IFileBuffer.h>

namespace EssexEngine{
namespace Drivers{
namespace OpenGl{
    class OpenGlSprite:public Daemons::Gfx::ISprite {
    public:
        OpenGlSprite(CachedPointer<std::string, Daemons::FileSystem::IFileBuffer> _fileBuffer, GLuint _textureId, int _x, int _y, int _width, int _height);
        ~OpenGlSprite();
        
        GLuint GetTextureId();

        int GetX();
        int GetY();
        int GetWidth();
        int GetHeight();
        int GetTotalWidth();
        int GetTotalHeight();
    private:
        CachedPointer<std::string, Daemons::FileSystem::IFileBuffer> fileBuffer;
        GLuint textureId;

        int x;
        int y;
        int width;
        int height;
    };
}}};
