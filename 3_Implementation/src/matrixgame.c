/**
 * @file matrixgame.c
 * @author Hemanth  (hemanth.aradhyula@ltts.com)
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <unistd.h>
#include "matrix.h"

int		matrix_size(t_list *list, int y)
{
  t_list	*tmp;
  int		i;

  i = 0;
  if (list == list->next && list->y != y)
    return (0);
  else if (list == list->next)
    return (1);
  tmp = list;
  while (list->y == list->prev->y && list->next != tmp)
    list = list->next;
  tmp = list;
  while (list->y != y && list->next != tmp)
    list = list->next;
  tmp = list;
  while (list->y == y && list->next != tmp)
    {
      ++i;
      list = list->next;
    }
  if (list->next == tmp && list->y == y)
    ++i;
  return (i);
}

int	matrix_del(t_struct *s, t_list *list, int i, int y)
{
  usleep(500000);
  while (i > 0)
    {
      if (list->y == y)
	{
	  list->select = 1;
	  --i;
	}
      list = list->next;
    }
  print_opti(s, list);
  usleep(250000);
  return (0);
}

int	check_if_one_per_line(t_list *list, t_list *tmp, int i)
{
  int	j;

  j = 0;
  while (list->next != tmp)
    {
      if (list->y == list->prev->y)
	{
	  if (list->y != j)
	    ++i;
	  j = list->y;
	}
      list = list->next;
    }
  if (list->y == list->prev->y && list->y != j)
    ++i;
  return (i);
}

int	matrix(t_struct *s, t_list *list, int i, int y)
{
  while (y < YMAX)
    i ^= matrix_size(list, y++);
  y = YMIN;
  if (list == list->next)
    return (matrix_del(s, list, 1, list->y));
  if (check_if_one_per_line(list, list, 0) <= 1)
    return (case_matrix(s, list));
  if (i > 0)
    while (y < YMAX)
      {
	if (matrix_size(list, y) > 0 && (matrix_size(list, y) ^ i) < matrix_size(list, y))
	  return (matrix_del(s, list, matrix_size(list, y) -
				(i ^ matrix_size(list, y)), y));
	++y;
      }
  y = YMIN;
  return (matrix_del(s, list, 1, list->y));
}
