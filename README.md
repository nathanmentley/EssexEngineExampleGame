# EssexEngine

This is an example Game Repo using the essex engine.

Each component of the EssexEngine is pulled in as a git submodule under the src directory.
For now the build system needs to be informed of those modules here... That's done in CMakeConfig.txt.

There is also some base config in CMakeLists.txt. As of today that shouldn't need to be modified, but ultimately I'm planning on moving it to the BuildInfrastructure submodule.

WIP macOs Build Steps:

> brew install cmake
> brew install doxygen
> mkdir build
> cd build
> cmake ..
> make
> make runGame

Right now this will only run on macOs, but it shouldn't be much work to port this to linux and windows.
