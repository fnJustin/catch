cmake_minimum_required (VERSION 3.10 FATAL_ERROR)
project (app)

set (CMAKE_CXX_STANDARD 11)
set (CXX_STANDARD_REQUIRED)

#get all the filesin the project
file (GLOB APP_FILES ./*.cpp)

#ok we need to swap out the main in the test build.
set (main ${CMAKE_CURRENT_SOURCE_DIR}/./main.cpp)
list(REMOVE_ITEM APP_FILES ${main})

message(STATUS ${main})
message(STATUS ${APP_FILES})
#dirty just assume *test.cpp
file( GLOB TESTFILES ../tests/*tests.cpp )

#spit out the program
add_executable(app main.cpp ${APP_FILES})

add_library(catch INTERFACE)
target_include_directories(catch INTERFACE "../thirdparty/catch/catch.h")

#i want to make this a target need to learn more cmake.
#spit out the tests
add_executable(tests ../tests/main.cpp ${APP_FILES} ${TESTFILES} )
target_link_libraries(tests catch)

add_custom_target(UnitTests)
add_dependencies(UnitTests tests)









