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

#include <EssexEngineOpenGlDriver/OpenGlDriver.h>

using EssexEngine::Daemons::FileSystem::IFileBuffer;
using EssexEngine::Daemons::Gfx::Entity;
using EssexEngine::Daemons::Gfx::Model;
using EssexEngine::Daemons::Window::IRenderContext;

using EssexEngine::Drivers::OpenGl::OpenGlDriver;

OpenGlDriver::OpenGlDriver(WeakPointer<Context> _context):BaseDriver(_context) {
}

OpenGlDriver::~OpenGlDriver() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
//IGfxDriver
void OpenGlDriver::Setup(WeakPointer<IRenderContext> target) {
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 
    window = glfwCreateWindow(800, 600, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    //glewExperimental=true; // Needed in core profile
/*
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();*/
    glClearColor( 255.0f, 0.0f, 255.0f, 0.0f );
}

void OpenGlDriver::StartRender(WeakPointer<IRenderContext> target) {
    //glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGlDriver::FinishRender(WeakPointer<IRenderContext> target) {
    glfwSwapBuffers(window);
    //glfwPollEvents();
}

static const GLfloat g_vertex_buffer_data[] = {
       -1.0f, -1.0f, 0.0f,
          1.0f, -1.0f, 0.0f,
             0.0f,  1.0f, 0.0f,
};

void OpenGlDriver::RenderEntity(WeakPointer<IRenderContext> target, WeakPointer<Entity> entity) {
    WeakPointer<OpenGlSprite> sprite = entity->GetSprite().Cast<OpenGlSprite>();
    /*
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    
    glBindTexture(GL_TEXTURE_2D, sprite->GetTextureId());
    
    GLfloat Vertices[] = {
        (float)entity->GetX(), (float)entity->GetY(), 0,
        ((float)entity->GetX() + (float)sprite->GetWidth()) * entity->GetScaleX(), (float)entity->GetY(), 0,
        ((float)entity->GetX() + (float)sprite->GetWidth()) * entity->GetScaleX(), ((float)entity->GetY() + (float)sprite->GetHeight()) * entity->GetScaleY(), 0,
        (float)entity->GetX(), ((float)entity->GetY() + (float)sprite->GetHeight()) * entity->GetScaleY(), 0};
    GLfloat TexCoord[] = {
        (float)((float)sprite->GetX() / (float)sprite->GetTotalWidth()), (float)((float)sprite->GetY() / (float)sprite->GetTotalHeight()),
        (float)(((float)sprite->GetX() + (float)sprite->GetWidth()) / (float)sprite->GetTotalWidth()), (float)((float)sprite->GetY() / (float)sprite->GetTotalHeight()),
        (float)(((float)sprite->GetX() + (float)sprite->GetWidth()) / (float)sprite->GetTotalWidth()), (float)(((float)sprite->GetY() + (float)sprite->GetHeight()) / (float)sprite->GetTotalHeight()),
        (float)((float)sprite->GetX() / (float)sprite->GetTotalWidth()), (float)(((float)sprite->GetY() + (float)sprite->GetHeight()) / (float)sprite->GetTotalHeight()),
    };
    GLubyte indices[] = {0,1,2, // first triangle (bottom left - top left - top right)
        0,2,3}; // second triangle (bottom left - top right - bottom right)
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, Vertices);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, TexCoord);
    
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray( VertexArrayID );

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
    
    glDisable(GL_TEXTURE_2D);
    */
    // This will identify our vertex buffer
GLuint vertexbuffer;
// Generate 1 buffer, put the resulting identifier in vertexbuffer
glGenBuffers(1, &vertexbuffer);
// The following commands will talk about our 'vertexbuffer' buffer
glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
// Give our vertices to OpenGL.
glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
glEnableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
glVertexAttribPointer(
   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
   3,                  // size
   GL_FLOAT,           // type
   GL_FALSE,           // normalized?
   0,                  // stride
   (void*)0            // array buffer offset
);
// Draw the triangle !
glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
glDisableVertexAttribArray(0);
}

void OpenGlDriver::RenderModel(WeakPointer<IRenderContext> target, WeakPointer<Model> model) {
}

void OpenGlDriver::RenderString(WeakPointer<IRenderContext> target, std::string data, int x, int y) {
}

EssexEngine::WeakPointer<EssexEngine::Daemons::Gfx::ISprite> OpenGlDriver::GetSprite(CachedPointer<std::string, IFileBuffer> fileContent, int _x, int _y, int _width, int _height) {
    if (textureCache.find(fileContent->GetFileName()) == textureCache.end() ) {
        int w, h;
        bool hasAlpha;
        GLubyte* textureImage;
        bool success = LoadPngImage(fileContent.ToWeakPointer(), w, h, hasAlpha, &textureImage);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, hasAlpha ? 4 : 3, w, h, 0, hasAlpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, textureImage);
        glDisable(GL_TEXTURE_2D);
        //free(textureImage);
        textureCache[fileContent->GetFileName()] = texture;
    }

    return EssexEngine::WeakPointer<Daemons::Gfx::ISprite>(
        new OpenGlSprite(
            std::move(fileContent),
            textureCache[fileContent->GetFileName()],
            _x,
            _y,
            _width,
            _height
        )
    );
}

//PNG LOADER
void ReadDataFromInputStream(png_structp png_ptr, png_bytep bytes, png_size_t size)
{
    IFileBuffer* file = (IFileBuffer*)png_get_io_ptr(png_ptr);
    if(file == NULL) {
        return;
    }
    
    //load data from our file reader. TODO: Is this leaking data?
    memcpy(bytes, file->GetBuffer(), file->GetSize());
    size = file->GetSize();
}
bool OpenGlDriver::LoadPngImage(WeakPointer<IFileBuffer> file, int &w, int &h, bool &hasAlpha, GLubyte** data) {
    png_structp png_ptr;
    png_infop info_ptr;
    unsigned int sig_read = 0;
    int color_type, interlace_type;

    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png_ptr == NULL) {
        return false;
    }
    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL) {
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        return false;
    }
    if (setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return false;
    }

    //use custom png data reader. and process data
    png_set_read_fn(png_ptr, (file.Get()), ReadDataFromInputStream);
    png_set_sig_bytes(png_ptr, sig_read);
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, NULL);

    png_uint_32 width, height;
    int bit_depth;
    png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_type, NULL, NULL);
    w = width;
    h = height;
    hasAlpha = true;

    unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
    *data = (unsigned char*) malloc(row_bytes * height);
    png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);
    for (int i = 0; i < height; i++) {
        // note that png is ordered top to
        // bottom, but OpenGL expect it bottom to top
        // so the order or swapped
        memcpy(*data+(row_bytes * (height-1-i)), row_pointers[i], row_bytes);
    }
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    //free(row_pointers);

    return true;
}
