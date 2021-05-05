# Set minimum CMake required version for this project.
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Define a C++ project.
project(MidiEmitter LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# CoreMIDI
if(RTMIDI_API_CORE)
  list(APPEND API_DEFS "-D__MACOSX_CORE__")
  list(APPEND API_LIST "coremidi")
  list(APPEND LINKLIBS "-framework CoreServices")
  list(APPEND LINKLIBS "-framework CoreAudio")
  list(APPEND LINKLIBS "-framework CoreMIDI")
  list(APPEND LINKLIBS "-framework CoreFoundation")
  list(APPEND LINKFLAGS "-Wl,-F/Library/Frameworks")
endif()

add_executable(main src/main.cpp)