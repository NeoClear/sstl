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

add_executable(test/TestArray test/TestArray.cpp)
target_link_libraries(test/TestArray ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test/TestArray ${CMAKE_THREAD_LIBS_INIT})

add_test(Test test/TestVector)

add_executable(test/TestString test/TestString.cpp)
target_link_libraries(test/TestString ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test/TestString ${CMAKE_THREAD_LIBS_INIT})

add_test(Test test/TestString)

add_executable(test/TestConsole test/TestConsole.cpp)
target_link_libraries(test/TestConsole ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test/TestConsole ${CMAKE_THREAD_LIBS_INIT})

add_test(Test test/TestConsole)

enable_testing()
