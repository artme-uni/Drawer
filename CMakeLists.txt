cmake_minimum_required(VERSION 3.13)
project(lab_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_3 main.cpp my_shapes/circle.h my_shapes/circle.cpp my_shapes/rectangle.h my_shapes/rectangle.cpp my_shapes/triangle.cpp my_shapes/triangle.h shape/shape.cpp shape/shape.h parsing.cpp parsing.h shape/add.cpp shape/add.h)
add_executable(unittest test.cpp my_shapes/circle.h my_shapes/circle.cpp my_shapes/rectangle.h my_shapes/rectangle.cpp my_shapes/triangle.cpp my_shapes/triangle.h shape/shape.cpp shape/shape.h parsing.cpp parsing.h shape/add.cpp shape/add.h)