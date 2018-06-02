cmake_minimum_required(VERSION 3.9)
project(cstlmp C)

set(CMAKE_C_STANDARD 11)

############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(cstlmp STATIC
        src/library.c src/library.h)

target_include_directories(cstlmp
        PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        )

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(cstlmp_tests
        tests/simple_test.c
        )

# link the new hello_library target with the hello_binary target
target_link_libraries( cstlmp_tests
        PRIVATE
        cstlmp
        )

include(CTest)
enable_testing()

add_test(NAME "cstlmp_tests"
        COMMAND cstlmp_tests)