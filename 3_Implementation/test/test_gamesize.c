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
# define ENTER 10;
#define XMIN 24;
#define YMIN 5;

#define PROJECT_NAME   "AIMatrix"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Prototypes for all the test functions */
void test_gamesize(void);



/* Write all the test functions */ 
void test_gamesize(void) {
  
  TEST_ASSERT_EQUAL(rectangular_matrix_build(s, XMIN, YMIN, 0), matrix_struct_per_line(0, int key= ENTER, int i=1));
}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  RUN_TEST(test_gamesize);
  
  /* Close the Unity Test Framework */
  return UNITY_END();
}
