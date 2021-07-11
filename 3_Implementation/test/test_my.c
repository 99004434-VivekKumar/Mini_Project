/**
 * @file test_gamesize.c
 * @author vishal singh (vishal.singh@ltts.com)
 * @brief test case to check game size
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"
#include "unity.h"

#define PROJECT_NAME   "AIMatrix"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Prototypes for all the test functions */
void test_my_function(void);



/* Write all the test functions */ 
void test_my_function(void) {
  
  TEST_ASSERT_EQUAL_INT(0,str_put(char str[0], int output=2));
}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  RUN_TEST(test_my_function);
  
  /* Close the Unity Test Framework */
  return UNITY_END();
}
