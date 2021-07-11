/**
 * @file case_matrixgame.c
 * @author Jahnavi Jha (jahnavi.jha@ltts.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"
/**
 * @brief calculate the no. of lines
 * 
 * @param tmp 
 * @param list 
 * @param i 
 * @return int 
 */

int	matrix_line_count(t_list *tmp, t_list *list, int i)
{
  while (list->next != tmp)
    {
      if (list->y != list->next->y)
	++i;
      list = list->next;
    }
  if (list->y != list->next->y)
    ++i;
  if (i == 0)
    ++i;
  return (i);
}
/**
 * @brief Moving through the list
 * 
 * @param tmp 
 * @param list 
 * @return int 
 */

int	find_biggest_al_y(t_list *tmp, t_list *list)
{
  while (list->next != tmp)
    {
      if (list->y == list->next->y)
	return (list->y);
      list = list->next;
    }
  if (list->y == list->next->y)
    return (list->y);
  return (0);
}
/**
 * @brief game case
 * 
 * @param s 
 * @param list 
 * @return int 
 */

int	case_matrix(t_struct *s, t_list *list)
{
  int	y;

  if (matrix_line_count(list, list, 0) % 2 == 0)
    {
      if ((y = find_biggest_al_y(list, list)) != 0)
	return (matrix_del(s, list, matrix_size(list, y), y));
      else
	return (matrix_del(s, list, 1, list->y));
    }
  else
    {
      if ((y = find_biggest_al_y(list, list)) != 0)
	return (matrix_del(s, list, matrix_size(list, y) - 1, y));
      else
	return (matrix_del(s, list, 1, list->y));
    }
  return (0);
}
