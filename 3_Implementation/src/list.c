/**
 * @file build_list.c
 * @author Hemanth(hemanth.aradhyula@ltts.com)
 * @brief builds the list in structure in which player chooses
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"

/**
 * @brief Builds the rectangular list
 * 
 */
int		rectangular_matrix_build(t_struct *s, int x, int y, int max)
{
  t_list	*list;
  int		tmp;

  tmp = x + 1;
  init_list(&list, tmp - s->al_per_line, y);
  while (max++ < s->line)
    {
      x = tmp - s->al_per_line;
      if (y == YMIN)
	x += 2;
      while (x < tmp)
	{
	  add_next_elem(&list, x, y);
	  list = list->next;
	  x += 2;
	}
	while (x < tmp + s->al_per_line)
	  {
	    add_next_elem(&list, x, y);
	    list = list->next;
	    x += 2;
	  }
	++y;
    }
  return (load_game(s, list->next));
}

int		build_list(t_struct *s, int x, int y, int max)
{
  t_list	*list;
  int		tmp;
  int		i;

  init_list(&list, x, y++);
  i = x;
  tmp = x;
  while (max != s->line)
    {
      x = tmp - 2;
      while (x <= i + 2)
	{
	  add_next_elem(&list, x, y);
	  list = list->next;
	  x += 2;
	}
      i += 2;
      tmp -= 2;
      ++y;
      ++max;
    }
  list = list->next;
  return (load_game(s, list));
}
