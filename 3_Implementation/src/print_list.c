/**
 * @file print_list.c
 * @author Jahnavi Jha (jahnavi.jha@ltts.com)
 * @brief Printing the list
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"
/**
 * @brief player changing turns
 * 
 * @param s 
 * @return int 
 */

int	change_turn(t_struct *s)
{
  if (s->turn == 1)
    {
      if (s->mode == 0)
	cursor_position(s->game, 3, 15, "Player 1");
      if (s->mode == 1)
	cursor_position(s->game, 3, 15, "Your Turn");
      if (s->mode == 2)
	cursor_position(s->game, 3, 15, "Bot1 is playing");
      s->turn = 2;
    }
  else
    {
      if (s->mode == 0)
        cursor_position(s->game, 3, 15, "Player 2");
      if (s->mode == 1)
	cursor_position(s->game, 3, 15, "Bot's Turn");
      if (s->mode == 2)
	cursor_position(s->game, 3, 15, "Bot2 is playing");
      s->turn= 1;
    }
  return (0);
}
/**
 * @brief printing the configuration
 * 
 * @param w 
 * @param list 
 * @return int 
 */

int	console_config(WINDOW *w, t_list *list)
{
  if (list->pos == 2)
    list->pos = 0;
  if (list->pos == 0 && list->select == 0)
    mvwprintw(w, list->y, list->x, "|");
  else if (list->pos == 0)
    print_videorev(w, list->y, list->x, "|");
  if (list->pos == 1)
    {
      if (list->select == 0)
	cursor_position_notselectt(w, list->y, list->x, "|");
      else
	cursor_position(w, list->y, list->x, "|");
      list->pos = 2;
    }
  return (0);
}
/**
 * @brief Printing the list
 * 
 * @param s 
 * @param list 
 * @param i 
 * @return int 
 */

int		print_list(t_struct *s, t_list *list, int i)
{
  t_list	*temp;

  wclear(s->game);
  mvwprintw(s->game, 3, 3, "AIMatrix :");
  if (s->mode != 2)
    {
      mvwprintw(s->game, 19, 4, "Use Arrow keys to move");
      mvwprintw(s->game, 20, 4, "Press SPACE to selectt matches on a line");
      mvwprintw(s->game, 21, 4, "Press ENTER to delete selected matches");
    }
  else
    mvwprintw(s->game, 19, 4, "Bots are playing. Enjoy the Match");
  temp = list;
  while (list->next != temp)
    {
      console_config(s->game, list);
      list = list->next;
    }
  console_config(s->game, list);
  if (i != 1)
    change_turn(s);
  wrefresh(s->game);
  return (0);
}
