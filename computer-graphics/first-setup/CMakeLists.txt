cmake_minimum_required(VERSION 3.10)
project(OpenGLExample)

## Specify the compiler and C++ standard
#set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated -g")

# Define the source files
set(SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/main.cpp
        ${CMAKE_SOURCE_DIR}/glad.c
        ${CMAKE_SOURCE_DIR}/common/shader.cpp
)

# Add the executable
add_executable(app ${SOURCE_FILES})

# Include directories for dependencies
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/include)

# Link directories for libraries
target_link_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/lib)

find_package(OpenGL REQUIRED)

target_link_libraries(app
        ${CMAKE_SOURCE_DIR}/dependencies/lib/libglfw.3.4.dylib
        OpenGL::GL
        "-framework OpenGL"    # Use OpenGL framework
        "-framework Cocoa"      # Required for macOS GUI
        "-framework IOKit"
        "-framework CoreVideo"
)

# Link libraries and macOS frameworks
#target_link_libraries(app
#        ${CMAKE_SOURCE_DIR}/dependencies/lib/libglfw.3.4.dylib
#        "-framework OpenGL"
#        "-framework Cocoa"
#        "-framework IOKit"
#        "-framework CoreVideo"
#        "-framework CoreFoundation"
#)
