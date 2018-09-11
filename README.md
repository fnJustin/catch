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

To get coverage metricc on osx or linux from the build folder
> ./tests
> gcov ../src/*.cpp --object-directory CMakeFiles/tests.dir/

To get nicer html format

>gcovr -r ../src --object-directory ./CMakeFiles/tests.dir/ --html --html-details -o output.html
