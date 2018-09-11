cmake_minimum_required (VERSION 3.10 FATAL_ERROR)
project (app)

set (CMAKE_CXX_STANDARD 11)
set (CXX_STANDARD_REQUIRED)

#get all the files in the project, i know i'm not supposed to used glob but meh.
file (GLOB APP_FILES ./*.cpp)

#ok for our test target we want all the files but not main.cpp.
set (main ${CMAKE_CURRENT_SOURCE_DIR}/./main.cpp)
list(REMOVE_ITEM APP_FILES ${main})

#all tests are in the test folder
file( GLOB TESTFILES ../tests/*.cpp )

#spit out the program - app target
add_executable(app main.cpp ${APP_FILES})

#add in the catch lib for testing to catch, it's header only so nice and easy.
add_library(catch INTERFACE)
target_include_directories(catch INTERFACE "../thirdparty/catch/catch.h")

#spit out the tests target
add_executable(tests ${TESTFILES} ${APP_FILES} )
target_link_libraries(tests catch --coverage)

#for the tests we want to add in the line coverage flags for gcov
target_compile_options(tests PRIVATE -g -O0 --coverage)

#force cmake to create the gcov files with the correct names.
set ( CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)








