/**
 * @file list_configs.c
 * @author Vishal Singh (vishal.singh@ltts.com)
 * @brief Function for choosing the list size
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include "matrix.h"
/**
 * @brief  This function takes care of size of the list
 * 
 * @param list 
 * @return int 
 */

int		list_size(t_list *list)
{
  t_list	*tmp;
  int		i;

  i = 0;
  tmp = list;
  while (list->next != tmp)
    {
      list = list->next;
      i++;
    }
  return (i);
}
/**
 * @brief Delete the list after use
 * 
 * @param list 
 * @return int 
 */
int		delete_list(t_list **list)
{
  t_list	*temp;

  temp = (*list)->next;
  if ((*list) == (*list)->next)
    {
      free(*list);
      *list = NULL;
    }
  else
    {
      (*list)->next->prev = (*list)->prev;
      (*list)->prev->next = (*list)->next;
      free(*list);
      *list = temp;
    }
  return (0);
}
/**
 * @brief Adds new element to the list
 * 
 * @param list 
 * @param x 
 * @param y 
 * @return int 
 */
int		add_next_elem(t_list **list, int x, int y)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    str_put("Cannt alloc list", 2);
  elem->x = x;
  elem->y = y;
  elem->select = 0;
  elem->pos = 0;
  elem->prev = (*list);
  (*list)->next->prev = elem;
  elem->next = (*list)->next;
  (*list)->next = elem;
  return (0);
}
/**
 * @brief This function Initialize the list
 * 
 * @param list 
 * @param x 
 * @param y 
 * @return int 
 */
int	init_list(t_list **list, int x, int y)
{
  if ((*list = malloc(sizeof(**list))) == NULL)
    str_put("Cannot alloc list.\n", 2);
  (*list)->x = x;
  (*list)->y = y;
  (*list)->select = 0;
  (*list)->pos = 1;
  (*list)->prev = *list;
  (*list)->next = *list;
  return (0);
}
