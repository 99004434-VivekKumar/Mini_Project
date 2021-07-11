/**
 * @file matrix_struct_opt.c
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
 * @brief To move the cursor 
 * 
 */
static int	move_chose_form(t_struct *s, char **str, int *c)
{
  int		i;

  i = 0;
  if (*c == 0)
    *c = 1;
  else
    *c = 0;
  while (++i != 3)
    {
      if (i - 1 == *c)
        cursor_position(s->game, i + 6, 6, str[i - 1]);
      else
        mvwprintw(s->game, i + 6, 6, str[i - 1]);
    }
  return (0);
}
/**
 * @brief Instructions to the player
 * 
 */
static int	print_chose_form(t_struct *s)
{
  mvwprintw(s->game, 4, 6, "Select Matrix structure :");
  mvwprintw(s->game, 14, 6, "Use arrow keys to move.");
  mvwprintw(s->game, 15, 6, "Press ENTER to chose.");
  mvwprintw(s->game, 16, 6, "Press b to go back.");
  return (0);
}

/**
 * @brief selectts the structure of game by the player
 * 
 */
int	matrix_struct_opt(t_struct *s, int key, int choice)
{
  char  *str[2];

  wclear(s->game);
  str[0] = "Pyramid Matrix";
  str[1] = "Rectangular Matrix";
  print_chose_form(s);
  move_chose_form(s, str, &choice);
  wrefresh(s->game);
  while ((key = getch()) != ENTER)
    if (key == KEY_UP || key == KEY_DOWN || key == 'b')
      {
        if (key == 'b' && s->mode != 0)
	  return (diff_lvl_opt(s, 0));
	else if (key == 'b')
	  {
	    wclear(s->game);
	    return (player_mode_opt(s, 0));
	  }
        move_chose_form(s, str, &choice);
        wrefresh(s->game);
      }
  return (matrix_line_opt(s, 0, 0, choice));
}
