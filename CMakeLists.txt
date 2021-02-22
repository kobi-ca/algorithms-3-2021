cmake_minimum_required(VERSION 3.19)
project(algorithms_3_2021)

set(CMAKE_CXX_STANDARD 20)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(algorithms-3-2021 main.cpp)
target_link_libraries(algorithms-3-2021 PRIVATE ${CONAN_LIBS_FMT} ${CONAN_LIBS_RANGES-V3})
