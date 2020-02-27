cmake_minimum_required(VERSION 2.8)

SET (CMAKE_CXX_COMPILER_ENV_VAR "clang++")
SET (CMAKE_CXX_FLAGS "-std=c++17")
SET (CMAKE_CXX_FLAGS_DEBUG   "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL  "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE  "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/sstl/
    DESTINATION include/sstl
    FILES_MATCHING PATTERN "*.h*")

project(sstl)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test/TestVector test/TestVector.cpp)
target_link_libraries(test/TestVector ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test/TestVector ${CMAKE_THREAD_LIBS_INIT})

add_test(Test test/TestVector)
enable_testing()
