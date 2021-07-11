/**
 * @file print_mode.c
 * @brief funtion definitions of print options
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"

/**
 * @brief printing options
 * 
 * @param s 
 * @param list 
 * @return int 
 */

int		print_opti(t_struct *s, t_list *list)
{
  t_list	*temp;

  temp = list;
  while (list->next != temp)
    {
      if (list->pos == 1 || list->pos == 2 || list->select == 1)
	console_config(s->game, list);
      list = list->next;
    }
  if (list->pos == 1 || list->pos == 2 || list->select == 1)
    console_config(s->game, list);
  wrefresh(s->game);
  return (0);
}
