/**
 * @file test_vector.cpp
 * @author Swapnil Khandekar (swapnil.khandekar@ltts.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "tracking.h"
#include <gtest/gtest.h>

/**
 * @brief Testing empty constructor
 * 
 */
TEST(Data, Empty_Constructor)
{
  Data a;
  EXPECT_EQ("Ground", a.getProductName());
  EXPECT_EQ(0, a.getProductNum());
  EXPECT_FLOAT_EQ(0, a.getDemand());
  EXPECT_EQ("OFF", a.getState());
  EXPECT_FLOAT_EQ(0.0, a.getQuantity());
}

/**
 * @brief Testing parameterised constructor
 * 
 */
TEST(Data, Param_Constructor)
{
  Data a("Ground", 20, 50, "OFF", 20.1);
  EXPECT_EQ("Ground", a.getProductName());
  EXPECT_EQ(20, a.getProductNum());
  EXPECT_FLOAT_EQ(50, a.getDemand());
  EXPECT_EQ("OFF", a.getState());
  EXPECT_FLOAT_EQ(20.1, a.getQuantity());
}

/**
 * @brief Testing stringToObject function
 * 
 */
TEST(Data, stringToObject)
{
  Data a = stringToObject("First,101,50.1,ON,25.51");
  EXPECT_EQ("First", a.getProductName());
  EXPECT_EQ(101, a.getProductNum());
  EXPECT_FLOAT_EQ(50.1, a.getDemand());
  EXPECT_EQ("ON", a.getState());
  EXPECT_FLOAT_EQ(25.51, a.getQuantity());
}

/**
 * @brief Testing highestPowerConsumer function
 * 
 */
TEST(Data, highestPowerConsumer)
{
  vector<Data> testInventory;
  Data a = stringToObject("First,101,50.1,ON,25.51");
  Data b = stringToObject("Ground,5,90.5,OFF,35.6");
  Data c = stringToObject("Fourth,403,70.4,ON,25.74");
  testInventory.push_back(a);
  testInventory.push_back(b);
  testInventory.push_back(c);
  EXPECT_EQ(5, highestDemandConsumer(testInventory));
}

/**
 * @brief Testing highestRoomTemperature function
 * 
 */
TEST(Data, highestProductQuantity)
{
  vector<Data> testInventory;
  Data a = stringToObject("First,101,50.1,ON,25.51");
  Data b = stringToObject("Ground,5,90.5,OFF,35.6");
  Data c = stringToObject("Fourth,403,70.4,ON,25.74");
  testInventory.push_back(a);
  testInventory.push_back(b);
  testInventory.push_back(c);
  EXPECT_EQ(5, highestProductQuantity(testInventory));
}

/**
 * @brief Testing airConditionerStatusON function
 * 
 */
TEST(Data, productStatusAvailable)
{
  vector<Data> testInventory, resultInventory, expectedResultInventory;
  string testStr = "Ground";
  Data a = stringToObject("First,101,50.1,ON,25.51");
  Data b = stringToObject("Ground,5,90.5,OFF,35.6");
  Data c = stringToObject("Fourth,403,70.4,ON,25.74");
  Data d = stringToObject("Ground,1,50,ON,25.5");
  Data e = stringToObject("Ground,2,60,ON,25.6");
  Data f = stringToObject("Ground,3,70,ON,25.7");
  Data g = stringToObject("Ground,100,80,OFF,65");
  Data h = stringToObject("Ground,5,90.5,OFF,35.6");
  testInventory.push_back(a);
  testInventory.push_back(b);
  testInventory.push_back(c);
  testInventory.push_back(d);
  testInventory.push_back(e);
  testInventory.push_back(f);
  testInventory.push_back(g);
  testInventory.push_back(h);
  
  expectedResultInventory.push_back(d);
  expectedResultInventory.push_back(e);
  expectedResultInventory.push_back(f);

  resultInventory = productStatusAvailable(testInventory, testStr);
  for (int i = 0; i < expectedResultInventory.size(); ++i)
  {
   EXPECT_EQ(expectedResultInventory[i].getProductName(), resultInventory[i].getProductName());
   EXPECT_EQ(expectedResultInventory[i].getProductNum(), resultInventory[i].getProductNum());
   EXPECT_EQ(expectedResultInventory[i].getDemand(), resultInventory[i].getDemand());
   EXPECT_EQ(expectedResultInventory[i].getState(), resultInventory[i].getState());
   EXPECT_EQ(expectedResultInventory[i].getQuantity(), resultInventory[i].getQuantity());
  }
}

/**
 * @brief Testing airConditionerStatusOFF function
 * 
 */
TEST(Data, airConditionerStatusOFF)
{
  vector<Data> testInventory, resultInventory, expectedResultInventory;
  int minimumQuantity = 30;
  Data a = stringToObject("First,101,50.1,ON,25.51");
  Data b = stringToObject("Ground,5,90.5,OFF,35.6");
  Data c = stringToObject("Fourth,403,70.4,ON,25.74");
  Data d = stringToObject("Ground,1,50,ON,25.5");
  Data e = stringToObject("Ground,2,60,ON,25.6");
  Data f = stringToObject("Ground,3,70,ON,25.7");
  Data g = stringToObject("Ground,100,80,OFF,65");
  Data h = stringToObject("Second,204,80.2,OFF,35.52");
  testInventory.push_back(a);
  testInventory.push_back(b);
  testInventory.push_back(c);
  testInventory.push_back(d);
  testInventory.push_back(e);
  testInventory.push_back(f);
  testInventory.push_back(g);
  testInventory.push_back(h);
  
  expectedResultInventory.push_back(b);
  expectedResultInventory.push_back(g);
  expectedResultInventory.push_back(h);

  resultInventory = productStatusUnavailable(testInventory, minimumQuantity);
  for (int i = 0; i < expectedResultInventory.size(); ++i)
  {
   EXPECT_EQ(expectedResultInventory[i].getProductName(), resultInventory[i].getProductName()); 
   EXPECT_EQ(expectedResultInventory[i].getProductNum(), resultInventory[i].getProductNum()); 
   EXPECT_EQ(expectedResultInventory[i].getDemand(), resultInventory[i].getDemand()); 
   EXPECT_EQ(expectedResultInventory[i].getState(), resultInventory[i].getState()); 
   EXPECT_EQ(expectedResultInventory[i].getQuantity(), resultInventory[i].getQuantity());
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
  printResults();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
