cmake_minimum_required(VERSION 3.0.0)

project(operator-implies)

add_executable(tests tests/test_main.cpp)
target_include_directories(tests PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set_property(TARGET tests PROPERTY CXX_STANDARD 17)
set_property(TARGET tests PROPERTY CXX_STANDARD_REQUIRED ON)
