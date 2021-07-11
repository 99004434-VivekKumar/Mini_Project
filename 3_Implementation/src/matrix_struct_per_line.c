/**
 * @file matrix_struct_per_line.c
 * @author Vishal singh (vishal.singh@ltts.com)
 * @brief Function to take the game size as an input from the player
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"
/**
 * @brief Saves the input given by the 
 * 
 * @param s 
 * @param key 
 * @param i 
 * @return int 
 */

static int	save_nb(t_struct *s, int key, int *i)
{
  if (*i == 0)
    {
      consol_color(s->game, 7, 20, key);
      s->al_per_line = key - 48;
    }
  else if (*i == 1)
    {
      consol_color(s->game, 7, 21, key);
      s->al_per_line = s->al_per_line * 10 + key - 48;
    }
  *i = *i + 1;
  return (0);
}
/**
 * @brief 
 * 
 * @param s 
 * @param key 
 * @param i 
 * @return int 
 */

static int	pack_nb(t_struct *s, int key, int *i)
{
  if (key == KEY_BACKSPACE)
    {
      if (*i == 2)
        {
          *i = *i - 1;
          mvwprintw(s->game, 7, 21, " ");
          s->al_per_line = s->line / 10;
        }
      else if (*i == 1)
        {
          *i = *i - 1;
          mvwprintw(s->game, 7, 20, " ");
          s->al_per_line = 0;
        }
      return (0);
    }
  if (*i == 0 || *i == 1)
    save_nb(s, key, i);
  return (0);
}
/**
 * @brief Takes the matix size as an input
 * 
 * @param s 
 * @param key 
 * @param i 
 * @return int 
 */

int	matrix_struct_per_line(t_struct *s, int key, int i)
{
  s->al_per_line = 0;
  wclear(s->game);
  mvwprintw(s->game, 4, 6, "Enter the number of lines in the matrix");
  mvwprintw(s->game, 7, 6, "Integer value: ");
  mvwprintw(s->game, 9, 6, " | between 2-12 | ");
  mvwprintw(s->game, 15, 6, "Press ENTER to confirm");
  mvwprintw(s->game, 16, 6, "Press b to go back");
  wrefresh(s->game);
  while ((key = getch()) != ENTER ||  i == 0
	 || s->al_per_line < 2 || s->al_per_line > 23)
    {
      if ((key >= '0' && key <= '9') || key == KEY_BACKSPACE)
        {
          pack_nb(s, key, &i);
          wrefresh(s->game);
        }
      if (key == 'b')
        return (matrix_line_opt(s, 0, 0, 1));
    }
  return (rectangular_matrix_build(s, XMIN, YMIN, 0));
}
