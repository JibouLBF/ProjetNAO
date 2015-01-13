cmake_minimum_required(VERSION 2.8)
project(basic_motion)
find_package(qibuild)

option(BUMPER_IS_REMOTE
  "module is compiled as a remote module (ON or OFF)"
  ON)

set(_srcs
    basicmotion.h
    basicmotion.cpp
    head.h
    head.cpp
    arm.h
    arm.cpp
    leg.h
    leg.cpp
    motion.h
    motion.cpp
    crouch.h
    crouch.cpp
    lyingback.h
    lyingback.cpp
    lyingbelly.h
    lyingbelly.cpp
    posture.h
    posture.cpp
    sit.h
    sit.cpp
    sitrelax.h
    sitrelax.cpp
    stand.h
    stand.cpp
    standinit.h
    standinit.cpp
    standzero.h
    standzero.cpp
    sensorlistener.h
    sensorlistener.cpp
    sensorlistenertest.h
    sensorlistenertest.cpp
    main.cpp
)

if(BUMPER_IS_REMOTE)
  add_definitions(" -DBUMPER_IS_REMOTE ")
  qi_create_bin(basic_motion ${_srcs})
else()
  qi_create_lib(basic_motion SHARED ${_srcs} SUBFOLDER naoqi)
endif()

#qi_create_lib(basic_motion_lib ${_srcs})

# Create a executable named basic_motion
# with the source file: main.cpp
#qi_create_bin(basic_motion ${_srcs})

# Tell CMake that movehead depends on ALCOMMON.
# This will set the libraries to link movehead with,
# the include paths, and so on
qi_use_lib(basic_motion ALCOMMON)



# Add a simple test:
#enable_testing()
#qi_create_test(test_basic_motion "main.cpp" ${_srcs})
#qi_use_lib(test_basic_motion ALCOMMON)
