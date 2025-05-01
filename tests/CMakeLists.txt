# Add the test executable
add_executable(tests test_main.cpp test_config.h ${SOURCE_FILES})

# Link Catch2 (with main function)
target_link_libraries(tests Catch2::Catch2WithMain)

# Ensure Catch2's include directory is correctly set
target_include_directories(tests PRIVATE ${Catch2_SOURCE_DIR}/single_include)

# Optionally, include your source directory to get access to your code if needed
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR})

# Enable testing with CTest
add_test(NAME unit_tests COMMAND tests)

enable_testing()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(tests PRIVATE -Wno-unqualified-std-cast-call)
endif()
