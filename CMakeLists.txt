cmake_minimum_required(VERSION 3.10)
project(MyOpenCVTools)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

add_library(ColorPickerLib src/MyColorPicker.cpp)

target_include_directories(ColorPickerLib PUBLIC include)

target_link_libraries(ColorPickerLib ${OpenCV_LIBS})

add_executable(example_picker examples/main.cpp)

target_link_libraries(example_picker ColorPickerLib)
