
if(UNIX)
# Set minimum CMake required version for this project.
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Define a C++ project.
project(main)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# CoreMIDI
list(APPEND API_DEFS "-D__MACOSX_CORE__")
list(APPEND API_LIST "coremidi")
list(APPEND LINKLIBS "-framework CoreServices")
list(APPEND LINKLIBS "-framework CoreAudio")
list(APPEND LINKLIBS "-framework CoreMIDI")
list(APPEND LINKLIBS "-framework CoreFoundation")
list(APPEND LINKFLAGS "-Wl,-F/Library/Frameworks")

# include_directories(${PROJECT_SOURCE_DIR}/include)

find_library(RTMIDI rtmidi REQUIRED)

find_package(nlohmann_json 3.2.0 REQUIRED)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(main ${all_SRCS})

target_link_libraries (main ${RTMIDI})
target_link_libraries(main ${LINKLIBS})
target_link_libraries(main nlohmann_json::nlohmann_json)

else()

# Set minimum CMake required version for this project.
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Define a C++ project.
project(main-win)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# CoreMIDI
list(APPEND API_DEFS "-D__WINDOWS_MM__")
list(APPEND API_LIST "winmm")
list(APPEND LINKLIBS winmm) 

# include_directories(${PROJECT_SOURCE_DIR}/include)

find_library(RTMIDI rtmidi REQUIRED)

find_package(nlohmann_json 3.2.0 REQUIRED)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(main ${all_SRCS})

target_link_libraries (main ${RTMIDI})
target_link_libraries(main ${LINKLIBS})
target_link_libraries(main nlohmann_json::nlohmann_json)


endif()