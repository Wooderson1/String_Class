# @file CMakeLists.txt
# 
# CMake files for the StringClass project

# Can be run by any version of CMake >= this
cmake_minimum_required(VERSION 3.10)

# project info
project(String_Class)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Use Release build type if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Source files for the main program StringClass
set(SOURCE myShoeString.cpp testYourString.cpp)

# StringClass application
add_executable(StringClass ${SOURCE})

# Turn on warnings
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # standard warnings
    add_compile_options(-Wall)
endif()

# Demo run command
add_custom_target(run
        COMMENT "Run StringClass demo"
        COMMAND time ./StringClass
        DEPENDS StringClass
        USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
