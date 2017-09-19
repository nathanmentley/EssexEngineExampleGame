# base config

cmake_minimum_required(VERSION 3.0.0)
project (essexengine)

include_directories(${CMAKE_BINARY_DIR}/lib/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(ESSEXENGINE_MAJOR_VERSION 0)
set(ESSEXENGINE_MINOR_VERSION 1)
set(ESSEXENGINE_PATCH_VERSION 0)
set(ESSEXENGINE_VERSION ${ESSEXENGINE_MAJOR_VERSION}.${ESSEXENGINE_MINOR_VERSION}.${ESSEXENGINE_PATCH_VERSION})

set (CMAKE_CXX_STANDARD 11)

include(src/System/BuildInfrastructure/CMakeLists.txt)
include(CMakeConfig.txt)

enable_testing()

# projects

include(src/System/Core/CMakeLists.txt)
include(src/System/Kernel/CMakeLists.txt)
include(src/System/Bootloader/CMakeLists.txt)

FOREACH(daemon ${ESSEXENGINE_DAEMONS})
    include(src/Daemons/${daemon}/CMakeLists.txt)
ENDFOREACH(daemon)

FOREACH(lib ${ESSEXENGINE_LIBS})
    include(src/Libs/${lib}/CMakeLists.txt)
ENDFOREACH(lib)

FOREACH(app ${ESSEXENGINE_APPS})
    include(src/Apps/${app}/CMakeLists.txt)
ENDFOREACH(app)

FOREACH(driver ${ESSEXENGINE_DRIVERS})
    include(src/Drivers/${driver}/CMakeLists.txt)
ENDFOREACH(driver)