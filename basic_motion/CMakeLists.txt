cmake_minimum_required(VERSION 2.8)
project(basic_motion)
find_package(qibuild)

option(BUMPER_IS_REMOTE
  "module is compiled as a remote module (ON or OFF)"
  ON)

set(_srcs
    ./motion/basicmotion/arm.h
    ./motion/basicmotion/arm.cpp
    ./motion/basicmotion/basicmotion.h
    ./motion/basicmotion/basicmotion.cpp
    ./common/common.h
    ./common/common.cpp
    ./motion/posture/crouch.h
    ./motion/posture/crouch.cpp
    ./listener/facedetectionlistener.h
    ./listener/facedetectionlistener.cpp
    ./listener/facedetectionlistenertest.h
    ./listener/facedetectionlistenertest.cpp
    ./motion/basicmotion/head.h
    ./motion/basicmotion/head.cpp
    ./motion/others/leds.h
    ./motion/others/leds.cpp
    ./motion/basicmotion/leg.h
    ./motion/basicmotion/leg.cpp
    ./motion/posture/lyingback.h
    ./motion/posture/lyingback.cpp
    ./motion/posture/lyingbelly.h
    ./motion/posture/lyingbelly.cpp
    ./motion/motion.h
    ./motion/motion.cpp
    ./motion/posture/posture.h
    ./motion/posture/posture.cpp
    ./motion/others/say.h
    ./motion/others/say.cpp
    ./common/scheduler.h
    ./common/scheduler.cpp
    ./listener/sensorlistener.h
    ./listener/sensorlistener.cpp
    ./listener/sensorlistenertest.h
    ./listener/sensorlistenertest.cpp
    ./motion/posture/sit.h
    ./motion/posture/sit.cpp
    ./motion/posture/sitrelax.h
    ./motion/posture/sitrelax.cpp
    ./listener/sounddetectionlistener.h
    ./listener/sounddetectionlistener.cpp
    ./listener/sounddetectionlistenertest.h
    ./listener/sounddetectionlistenertest.cpp
    ./listener/soundlocalizationlistener.h
    ./listener/soundlocalizationlistener.cpp
    ./listener/soundlocalizationlistenertest.h
    ./listener/soundlocalizationlistenertest.cpp
    ./motion/posture/stand.h
    ./motion/posture/stand.cpp
    ./motion/posture/standinit.h
    ./motion/posture/standinit.cpp
    ./motion/posture/standzero.h
    ./motion/posture/standzero.cpp
    ./motion/others/waitforevent.h
    ./motion/others/waitforevent.cpp
    ./motion/basicmotion/walk.h
    ./motion/basicmotion/walk.cpp
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
qi_use_lib(basic_motion ALCOMMON ALAUDIO)



# Add a simple test:
#enable_testing()
#qi_create_test(test_basic_motion "main.cpp" ${_srcs})
#qi_use_lib(test_basic_motion ALCOMMON)
