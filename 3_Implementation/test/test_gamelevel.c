/**
 * @file test_gamelevel.c
 * @author Hemanth (hemanth.aradhyula@ltts.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
 
#include "matrix.h"
#include "unity.h"

/**
 * @brief According to the project 
 * 
 */

#define PROJECT_NAME   "AIMatrix"

/**
 * @brief Prototypes for all test functions 
 * 
 */
int test_levelofgame(t_struct *s,int key);

/* Required by the unity test framework */
void setUp(){}

/* Required by the unity test framework */
void tearDown(){}

/* all the test functions */ 
int test_levelofgame(t_struct *s,int key)
{

  TEST_ASSERT_EQUAL(4, print_diff_lvl_opt(4));
  
  TEST_ASSERT_EQUAL(16, print_diff_lvl_opt(16));
  
  TEST_ASSERT_EQUAL(0, diff_lvl_opt(0, KEY_UP));

}

/* Start of the application test */
int main()
{
/* Initializes the Unity Test Framework */
  UNITY_BEGIN();

/* Runs the  test functions */
  RUN_TEST(test_levelofgame);
 

  /* Closes the Unity Test Framework */
  return UNITY_END();
}
