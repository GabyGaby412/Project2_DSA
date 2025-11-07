cmake_minimum_required(VERSION 3.30)
project(project2_dsa)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        project2_dsa main.cpp
        node.cpp
        cmake-build-debug/tokenized_dataset.csv
)
