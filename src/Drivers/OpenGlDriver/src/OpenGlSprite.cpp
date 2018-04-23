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

#include <EssexEngineOpenGlDriver/OpenGlSprite.h>

EssexEngine::Drivers::OpenGl::OpenGlSprite::OpenGlSprite(CachedPointer<std::string, Daemons::FileSystem::IFileBuffer> _fileBuffer, GLuint _textureId, int _x, int _y, int _width, int _height)
    : fileBuffer(std::move(_fileBuffer)) {
    textureId = _textureId;
    x = _x;
    y = _y;
    width = _width;
    height = _height;
}

EssexEngine::Drivers::OpenGl::OpenGlSprite::~OpenGlSprite() {
}

GLuint EssexEngine::Drivers::OpenGl::OpenGlSprite::GetTextureId() {
    return textureId;
}

int EssexEngine::Drivers::OpenGl::OpenGlSprite::GetX() {
    return x;
}

int EssexEngine::Drivers::OpenGl::OpenGlSprite::GetY() {
    return y;
}

int EssexEngine::Drivers::OpenGl::OpenGlSprite::GetWidth() {
    return width;
}

int EssexEngine::Drivers::OpenGl::OpenGlSprite::GetHeight() {
    return height;
}

int EssexEngine::Drivers::OpenGl::OpenGlSprite::GetTotalWidth() {
    int w, h;
    w = 0;
    //SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    return w;
}

int EssexEngine::Drivers::OpenGl::OpenGlSprite::GetTotalHeight() {
    int w, h;
    h = 0;
    //SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    return h;
}
