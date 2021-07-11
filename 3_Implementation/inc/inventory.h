/**
 * @file vector.h
 * @author Vivek Kumar Yadav (vivek.yadav@ltts.com)
 * @brief Function declarations and class definitions for Inventory management feature
 * @version 0.1
 * @date 2021-07-11
 * @copyright Copyright (c) 2021
 */

#ifndef INVENTORY_H_
# define INVENTORY_H_

/*Include files*/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <string.h>
using namespace std; 

/**
 * @brief class Data definition 
 */


/**
 * @brief Dealloactes the memory
 */
char	**deloct_malloc(char **str, int sizeb, int size);

int	free_memory(char **str);

#endif /* !INVENTORY_H_ */
