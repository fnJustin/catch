Simple example of using the catch library and gcov for unit test and coverage stats.
You can use any testing framework, e.g. gtest in the same way.

> mkdir build

> cd build

> cmake ../src

> make

or

> make app

or

> make tests

This spits out 2 executables
app - the application
tests - the appliaction unit tests

To get coverage metric on osx or linux from the build folder

catch/build> ./tests

catch/build> gcov ../src/*.cpp --object-directory CMakeFiles/tests.dir/

To get nicer html format

catch/build>gcovr -r ../src --object-directory ./CMakeFiles/tests.dir/ --html --html-details -o output.html


Sonarqube (output all the test info to files)

catch> cd /build
catch/build> ./tests
catch/build> gcov ../src/*.cpp --object-directory CMakeFiles/tests.dir/
catch/build> cd ..
catch> gcovr -r . -x --object-directory=build >coverage.xml
catch> valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --xml=yes --xml-file=valgrind.xml build/app-debug
catch> cppcheck --xml --xml-version=2 --enable=all 2>cppcheck.xml ./src
catch> sonar-scanner



