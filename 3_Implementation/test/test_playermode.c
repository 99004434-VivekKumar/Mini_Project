/**
 * @file test_playermode.c
 * @author Vivek Kumar Yadav - 99004434(vivek.yadav@ltts.com)
 * @brief unit testing for each player mode options
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"
#include "unity.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Prototypes for all the test functions */
int test_chooseplayermode(t_struct *s, int key);


/* Write all the test functions */ 
int test_chooseplayermode(t_struct *s, int key) {
  
  TEST_ASSERT_EQUAL_INT(0, chooseplayermode(0, KEY_UP));
}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  //RUN_TEST(test_mainmenu);
  RUN_TEST(test_chooseplayermode);
  //RUN_TEST(test_Washclothes);
  //RUN_TEST(test_WashMenu);
  //RUN_TEST(test_Soak);
  //RUN_TEST(test_getTimesoak);
  //RUN_TEST(test_Temperature);
  //RUN_TEST(test_viewlog);
  //RUN_TEST(test_processlog);

  /* Close the Unity Test Framework */
  return UNITY_END();
}
