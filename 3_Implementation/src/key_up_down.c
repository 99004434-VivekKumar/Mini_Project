
/**
 * @file key_up_down.c
 * @author Praveen Kumar G - 99004437(praveen.kumar5@ltts.com)
 * @brief funtion definitions for up and down movement of pointer in screen
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "matrix.h"

int	key_up(t_list *tmp, t_list *list, int y)
{
  list = list->prev;
  while (list->y == y && list != tmp)
    list = list->prev;
  while (list->prev->y == list->y && list != tmp)
    list = list->prev;
  if (list == tmp)
    list = list->next;
  list->pos = 1;
  return (0);
}

int	key_down(t_list *tmp, t_list *list, int y)
{
  list = list->next;
  while (list->y == y && list != tmp)
    list = list->next;
  if (list == tmp)
    list = list->next;
  list->pos = 1;
  return (0);
}

int	move_up_down(t_struct *s, t_list *list, int key)
{
  int	y;

  while (list->pos != 2)
    list = list->next;
  y = list->y;
  if (key == KEY_UP)
    key_up(list, list, y);
  else
    key_down(list, list, y);
  return (print_opti(s, list));
}
