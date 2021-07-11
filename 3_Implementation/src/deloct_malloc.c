/**
 * @file deloct_malloc.c
 * @author  Jahnavi Jha (jahnavi.jha@ltts.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <matrix.h>
/**
 * @brief Allocating the memory
 * 
 * @param str 
 * @param sizeb 
 * @param size 
 * @return char** 
 */

char	**deloct_malloc(char **str, int sizeb, int size)
{
  int	i;

  i = 0;
  if (sizeb == -1 || size == -1)
    return (NULL);
  if ((str = malloc(sizeb * sizeof(char *) + 9)) == NULL)
    return (NULL);
  while (i != sizeb)
    {
      if ((str[i] = malloc(size + 1)) == NULL)
	{
	  free(str);
	  return (NULL);
	}
      i = i + 1;
    }
  str[i] = NULL;
  return (str);
}
/**
 * @brief increment
 * 
 * @param str 
 * @return int 
 */

int	free_memory(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    free(str[i++]);
  free(str);
  return (0);
}
