cmake_minimum_required(VERSION 3.12)
project(OK)

set(CMAKE_CXX_STANDARD 17)

add_executable(OK main.cpp Employ.hpp Maitenance.cpp Maitenance.hpp Operation.cpp Operation.hpp Task.cpp Task.hpp Machine.cpp Machine.hpp tuning.hpp Instance.cpp Instance.hpp Employ.cpp Exceptions.hpp Solution.cpp Solution.hpp)