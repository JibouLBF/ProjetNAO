cmake_minimum_required(VERSION 2.8)
project(basic_motion)

find_package(qibuild)

# Create a executable named basic_motion
# with the source file: main.cpp
qi_create_bin(basic_motion "main.cpp")

# Add a simple test:
enable_testing()
qi_create_test(test_basic_motion "test.cpp")
