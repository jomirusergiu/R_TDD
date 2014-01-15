#include <gtest/gtest.h>
#include <vector>
#include <cstring>

using namespace std;

//##############PROGRAM CODE###############//

// Run all the tests that were declared with TEST()
int runtests(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//Simple factorial function
int Factorial(int n)
{
    if (n<=1)
        return(1);
    else
        n=n*Factorial(n-1);
    return(n);
}

//Simple class. A new one of these is created for each test
class ClassTestSuite : public testing::Test
{
public:
 vector<int> m_vector;

 virtual void SetUp()
 {
   m_vector.push_back(1);
   m_vector.push_back(2);
 }
 virtual void TearDown(){}
};

//String class A new class is created for each test
class MyStringClassTest : public testing::TestWithParam<const char*>
{
public:
  virtual void SetUp(){}
  virtual void TearDown(){}
};
 
// String function under test...
bool acceptName(const char* name)
{
  char *result = strstr(name, "eek");
  if(result == NULL){
    return false;
  }
  return true;
}

//Main
int main(int argc, char **argv)
{
   runtests(argc, argv);
}

//##############UNIT TESTS###############//

//===========Simple Tests=========//
// Declare a test
 TEST(SimpleTestSuite, Addition)
 {
    EXPECT_EQ(2 + 2, 4);
 }

 // Declare another test
 TEST(SimpleTestSuite, Substraction)
 {
    EXPECT_EQ(3 - 2, 1);
 }

//===========Function Testing==========//
// Tests factorial of 0.
TEST(FunctionTestSuite, FactorialHandlesZeroInput) {
  EXPECT_EQ(1, Factorial(0));
}

// Tests factorial of positive numbers.
TEST(FunctonTestSuite, FactorialHandlesPositiveInput) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(120, Factorial(5));
  EXPECT_EQ(40320, Factorial(8));
}

//===========Class Testing==========//
//Tests if element zero is equal to 1
TEST_F(ClassTestSuite, testIfElementZeroIsOne)
{
  EXPECT_EQ(m_vector[0], 1);
}

//Tests if element one is equal to 2
TEST_F(ClassTestSuite, testIfElementOneIsTwo)
{
  EXPECT_EQ(m_vector[1], 2);
}

//Tests if  vector size is equal to 2
TEST_F(ClassTestSuite, testIfSizeIsTwo)
{
  EXPECT_EQ(m_vector.size(), (unsigned int)2);
}

//===========String Testing==========//
//Tests if if string contains "eek"
INSTANTIATE_TEST_CASE_P(StringTestSuite,
                        MyStringClassTest,
                        ::testing::Values("meek", "geek", "freek"));
 
TEST_P(MyStringClassTest, acceptsEekyWords)
{
  ASSERT_TRUE(acceptName(GetParam()));
}
