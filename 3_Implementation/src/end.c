/**
 * @file end.c
 * @author vishal singh (vishal.singh@ltts.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <unistd.h>
#include "matrix.h"

int	str_put(char *str, int output)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  if (output == 2)
    endwin();
  write(output, str, i);
  if (output == 2)
    exit(0);
  return (0);
}
