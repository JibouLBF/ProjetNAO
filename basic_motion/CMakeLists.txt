cmake_minimum_required(VERSION 2.8)
project(basic_motion)

find_package(qibuild)

set(_srcs
    basicmotion.h
    basicmotion.cpp
    head.h
    head.cpp
    main.cpp
)

qi_create_lib(basic_motion_lib ${_srcs})

# Create a executable named basic_motion
# with the source file: main.cpp
qi_create_bin(basic_motion ${_srcs})

# Tell CMake that movehead depends on ALCOMMON.
# This will set the libraries to link movehead with,
# the include paths, and so on
qi_use_lib(basic_motion ALCOMMON)

# Add a simple test:
enable_testing()
qi_create_test(test_basic_motion "test.cpp")


