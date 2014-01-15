INTRODUCTION
-------------

Google’s framework for writing C++ tests on a variety of platforms(Linux Mac OS X, Windows).
It supports automatic test discovery, a rich set of assertions, user-defined assertions, death tests, fatal test and non-fatal failures, value and type – parameterised tests, various options for running the tests, and XML test report generation.
Why GTest framework ?

1. When GTest fails, GTest allows you to run it in isolation for quick debugging.
2. GTest groups related tests into test cases that can share data and subroutines.
3. GTest works on different OSs with different compilers , with or without exceptions.
( Note: explanation of GTest installation ismostly for Unix-like Mac & Linux.)

How GTest Works ?
When using GTest, you start by writing assertions, which are statements that check whether a condition is true. Tests use assertions to verify the tested code’s behavior. If a test crashes or has a failed assertion, then it fails; otherwise it succeeds.

ASSERTIONS
-------------
GTest assertions are macros that resemble function calls. You test a class or function by making assertions about its behavior. When an assertion fails, GTest prints the assertion’s source file and line number location, along with a failure message.
ASSERT_* versions generate fatal failures when they fail, and abort the current function.
EXPECT_* versions generate nonfatal failures, which don’t abort the current function.
Usually, EXPECT_* are preferred, as they allow more than one failures to be reported in a test. However, you should use ASSERT_*  if it doesn’t make sense to continue when the assertion in question fails.

1. Basic Assertions
These assertions do basic true/false condition testing.
FATAL ASSERTION	NON-FATAL ASSERTION	VERIFIES
ASSERT_TRUE(condition);	EXPECT_TRUE(condition);	condition is true
ASSERT_FALSE(condition);	EXPECT_FALSE(condition);	condition is false

2. Binary Comparison
These assertions compare two values.
FATAL ASSERTION	NON-FATAL ASSERTION	VERIFIES
ASSERT_EQ(expected,actual);	EXPECT_EQ(expected,actual);	expected==actual
ASSERT_NE(val1, val2);	EXPECT_NE(val1, val2);	val1!=val2
ASSERT_LT(val1,val2);	EXPECT_LT(val1,val2);	val1<val2
ASSERT_LE(val1,val2);	EXPECT_LE(val1, val2);	val1=<val2
ASSERT_GT(val1,val2);	EXPECT_GT(val1, val2);	val1>val2
ASSERT_GE(val1,val2);	EXPECT_GE(val1, val2);	val1>=val2

3. String Comparison
These assertions compare two C strings. If you want to compare two string objects, use EXPECT_EQ, EXPECT_NE, and etc instead.
FATAL ASSERTION	NON-FATAL ASSERTION	VERIFIES
ASSERT_STREQ(expected_str,actual_str);	EXPECT_STREQ(expected_str,actual_str);	the two C strings havethe same content
ASSERT_STRNE(str1,str2);	EXPECT_STRNE(str1,str2);	the two C strings havedifferent content
ASSERT_STRCASEEQ(expected_str,actual_str);	EXPECT_STRCASEEQ(expected_str,actual_str);	the two C strings havethe same content, ignoring case
ASSERT_STRCASENE(str1,str2);	EXPECT_STRCASENE(str1,str2);	the two C strings havedifferent content, ignoring case
Download GTest


Linux Requirements
-------------
1. GNU  make
```BASH
$ sudo apt-get install make
```
2. POSIX standard shell
```BASH
$ sudo apt-get install bash
```
3. C++ compiler
```BASH
$ sudo apt-get install g++
```
Installation Steps
-------------
1. Decompress
```BASH
$ unzip gtest-1.6.0.zip
```
2. Go to this directory.
```BASH
$ cd gtest-1.6.0/
```
3. Standard GNU configure script
```BASH
$ ./configure
```
4. Standard makefile
```BASH
$ make
```
3. Builds and run all tests
```BASH
$ make check
```
Build Sample Test
-------------
As an example, the make/ directory contains a Makefile that you can use to build Google Test on systems (e.g. Linux, Mac OS X). It just builds the Google Test library and a sample test.
```BASH
$ cd make
$ make
$ ./sample1_unittest
```
If you are getting errors while running make, then open Makefile with sudo power
```BASH
$ sudo gedit Makefile
```
and replace “-lpthread” with “-pthread” at line number 80.

Build GTest samples
-------------
Jointly with the GTest, it also comes some C++ unit test examples, found in the samples directory. You can build this examples using CMake. It can be installed :
```BASH
$ sudo apt-get install cmake
```
The CMake uses a configuration file named CMakeLists.txt. To build a project with CMake is create a build directory, generate a Makefile using CMake and build it with make.
```BASH
$ mkdir build
$ cd build
$ cmake –Dgtest_build_samples=ON ..
$ make
```

One advantage of using CMake is that you separate the deploy from source code and can make the deploy in multiple places with the same CMake file.

Now, execute all examples.
```BASH
$ ./sample1_unittest
$ ./sample2_unittest
$ ./sample10_unittest
```

Build a simple example
-------------
1. First, build the GTest Library.
```BASH
$ g++ -I. -I./include -c src/gtest-all.cc
$ ar -rv libgtest.a gtest-all.o
```
It will generates the libgtest.a.


Projcet Usage and Output
-------------
```BASH
RocKKs-iMac:gtest-1.7.0 RocKK$ g++ -I. -I./include main.cpp libgtest.a -lpthread -o main
RocKKs-iMac:gtest-1.7.0 RocKK$ ./main
[==========] Running 10 tests from 5 test cases.
[----------] Global test environment set-up.
[----------] 2 tests from SimpleTestSuite
[ RUN      ] SimpleTestSuite.Addition
[       OK ] SimpleTestSuite.Addition (0 ms)
[ RUN      ] SimpleTestSuite.Substraction
[       OK ] SimpleTestSuite.Substraction (0 ms)
[----------] 2 tests from SimpleTestSuite (0 ms total)

[----------] 1 test from FunctionTestSuite
[ RUN      ] FunctionTestSuite.FactorialHandlesZeroInput
[       OK ] FunctionTestSuite.FactorialHandlesZeroInput (0 ms)
[----------] 1 test from FunctionTestSuite (0 ms total)

[----------] 1 test from FunctonTestSuite
[ RUN      ] FunctonTestSuite.FactorialHandlesPositiveInput
[       OK ] FunctonTestSuite.FactorialHandlesPositiveInput (0 ms)
[----------] 1 test from FunctonTestSuite (0 ms total)

[----------] 3 tests from ClassTestSuite
[ RUN      ] ClassTestSuite.testIfElementZeroIsOne
[       OK ] ClassTestSuite.testIfElementZeroIsOne (0 ms)
[ RUN      ] ClassTestSuite.testIfElementOneIsTwo
[       OK ] ClassTestSuite.testIfElementOneIsTwo (0 ms)
[ RUN      ] ClassTestSuite.testIfSizeIsTwo
[       OK ] ClassTestSuite.testIfSizeIsTwo (0 ms)
[----------] 3 tests from ClassTestSuite (0 ms total)

[----------] 3 tests from StringTestSuite/MyStringClassTest
[ RUN      ] StringTestSuite/MyStringClassTest.acceptsEekyWords/0
[       OK ] StringTestSuite/MyStringClassTest.acceptsEekyWords/0 (0 ms)
[ RUN      ] StringTestSuite/MyStringClassTest.acceptsEekyWords/1
[       OK ] StringTestSuite/MyStringClassTest.acceptsEekyWords/1 (0 ms)
[ RUN      ] StringTestSuite/MyStringClassTest.acceptsEekyWords/2
[       OK ] StringTestSuite/MyStringClassTest.acceptsEekyWords/2 (0 ms)
[----------] 3 tests from StringTestSuite/MyStringClassTest (0 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 5 test cases ran. (0 ms total)
[  PASSED  ] 10 tests.
```

