
/**
 * @file key_left_right.c
 * @author Praveen Kumar G - 99004437(praveen.kumar5@ltts.com)
 * @brief funtion definitions for left and right movement of pointer in screen
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "matrix.h"

int	key_right(t_list *list)
{
  if (list->next->y == list->y)
    list->next->pos = 1;
  else
    {
      while (list->y == list->prev->y)
	list = list->prev;
      list->pos = 1;
    }
  return (0);
}

int	key_left(t_list *list)
{
  if (list->prev->y == list->y)
    list->prev->pos = 1;
  else
    {
      while (list->y == list->next->y)
	list = list->next;
      list->pos = 1;
    }
  return (0);
}

int	move_left_right(t_struct *s, t_list *list, int key)
{
  while (list->pos != 2)
    list = list->next;
  if (key == KEY_RIGHT)
    key_right(list);
  else
    key_left(list);
  return (print_opti(s, list));
}
