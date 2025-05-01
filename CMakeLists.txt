cmake_minimum_required(VERSION 3.31.0)

project(
    ccwc
    VERSION 0.1.0
    DESCRIPTION "Copia de word count para coding challenges"
    LANGUAGES CXX C
)

set(CMAKE_COLOR_MAKEFILE OFF)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


add_subdirectory(src)
add_subdirectory(tests)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.4 # o la versión estable más reciente
)
FetchContent_MakeAvailable(Catch2)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(ccwc PRIVATE -Wno-unqualified-std-cast-call)
endif()
