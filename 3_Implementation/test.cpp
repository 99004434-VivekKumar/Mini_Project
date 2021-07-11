/**
 * @file test.cpp
 * @author Vivek Kumar Yadav (vivek.yadav@ltts.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "inventory.h"
#include <gtest/gtest.h>

/**
 * @brief Testing empty constructor
 * 
 */
TEST(Data, Empty_Constructor)
{
  
}

/**
 * @brief Testing parameterised constructor
 * 
 */
TEST(Data, Param_Constructor)
{

}

/**
 * @brief Testing stringToObject function
 * 
 */
TEST(Data, stringToObject)
{
  
}

/**
 * @brief Testing highestPoductavailable function
 * 
 */
TEST(Data, highestPoductavailable)
{
  inventory<Data> testInventory;
  Data a = stringToObject("First,101,50.1,Available,25.51");
  testInventory.push_back(a);
  EXPECT_EQ(5, highestPoductavailable(testVector));
}

/**
 * @brief Testing productStatusavailable function
 * 
 */
TEST(Data, productStatusavailable)
{
  inventory<Data> test, result, expectedResult;
  string testStr = "Second";
  Data a = stringToObject("First,101,50.1,Available,25.51");
  Data b = stringToObject("Second,5,90.5,Unavailable,35.6");
  testInventory.push_back(a);
  expectedResultVector.push_back(b);
  
  resultInventory = productStatusavailable(testInventory,testStr);
  for (int i = 0; i < expectedResult.size(); ++i)
  {
   EXPECT_EQ(expectedResult[i].getFlName(), result[i].getFlName());
  }
}

/**
 * @brief Testing productStatusunavailable function
 * 
 */
TEST(Data, productStatusunavailable)
{
  inventory<Data> test, result, expectedResult;
  int minimumT = 30;
  Data a = stringToObject("First,101,50.1,ON,25.51");
  testInventory.push_back(a);

  expectedResultInventory.push_back(b);
  
  result = productStatusunavailable(testInventory,minimumT);
  for (int i = 0; i < expectedResult.size(); ++i)
  {
   EXPECT_EQ(expectedResult[i].getFlName(), result[i].getFlName()); 

  }
}

/**
 * @brief main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{
  readCSV();
  //printResults();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
