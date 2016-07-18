cmake_minimum_required(VERSION 2.8)
project(succinct-core CXX)

find_package(Threads REQUIRED)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
file(MAKE_DIRECTORY ${LIBRARY_OUTPUT_PATH})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})

include_directories(src/)
add_executable(sertab src/serialize_table.cc)
