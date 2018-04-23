find_package(OpenGL REQUIRED)
find_package(PNG 1.4.12 REQUIRED)
find_package(glfw3 REQUIRED)

ee_setup_project("EssexEngineOpenGlDriver" "src/Drivers/OpenGlDriver/")

target_link_libraries(EssexEngineOpenGlDriver ${OPENGL_LIBRARIES})
target_link_libraries(EssexEngineOpenGlDriver ${PNG_LIBRARY})
target_link_libraries(EssexEngineOpenGlDriver glfw)
target_link_libraries(EssexEngineOpenGlDriver EssexEngineCore)
target_link_libraries(EssexEngineOpenGlDriver EssexEngineGfxDaemon)
target_link_libraries(EssexEngineOpenGlDriver EssexEngineFileSystemDaemon)

target_include_directories(EssexEngineOpenGlDriver PRIVATE ${OPENGL_INCLUDE_DIRS})
target_include_directories(EssexEngineOpenGlDriver PRIVATE ${PNG_INCLUDE_DIRS})
