
/**
 * @file matrix_line_opt.c
 * @author Praveen Kumar G - 99004437(praveen.kumar5@ltts.com)
 * @brief function definition for to choose no. of rows
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "matrix.h"

int	consol_color(WINDOW *w, int y, int x, int key)
{
  wattron(w, COLOR_PAIR(2));
  mvwprintw(w, y, x, "%c", key);
  wattroff(w, COLOR_PAIR(2));
  return (0);
}

static int	save_nb(t_struct *s, int key, int *i)
{
  if (*i == 0)
    {
      consol_color(s->game, 7, 20, key);
      s->line = key - 48;
      if(s->line <2){
        mvwprintw(s->game, 15, 6, "Warning: Out of range.");
      }
    }
  else if (*i == 1)
    {
      consol_color(s->game, 7, 21, key);
      s->line = s->line * 10 + key - 48;
      if(s->line >12){
        mvwprintw(s->game, 15, 6, "Warning: Out of range.");
      }

    }
  *i = *i + 1;
  return (0);
}

static int	pack_nb(t_struct *s, int key, int *i)
{
  if (key == KEY_BACKSPACE)
    {
      if (*i == 2)
	{
	  *i = *i - 1;
	  mvwprintw(s->game, 7, 21, " ");
	  s->line = s->line / 10;
	}
      else if (*i == 1)
	{
	  *i = *i - 1;
	  mvwprintw(s->game, 7, 20, " ");
	  s->line = 0;
	}
      return (0);
    }
  if (*i == 0 || *i == 1)
    save_nb(s, key, i);
  return (0);
}
/**
 * @brief Instructions
 * 
 */
int	matrix_line_opt(t_struct *s, int key, int i, int choice)
{
  s->line = 0;
  wclear(s->game);
  mvwprintw(s->game, 4, 6, "Enter the number of lines in the matrix");
  mvwprintw(s->game, 7, 6, "Integer value: ");
  mvwprintw(s->game, 9, 6, " | between 2-12 | ");
  mvwprintw(s->game, 15, 6, "Press ENTER to confirm.");
  mvwprintw(s->game, 16, 6, "Press b to go back");
  wrefresh(s->game);
  while ((key = getch()) != ENTER ||  i == 0 || s->line < 2 || s->line > 12)
    {
      if ((key >= '0' && key <= '9') || key == KEY_BACKSPACE)
        {
	  pack_nb(s, key, &i);
	  wrefresh(s->game);
        }
      if (key == 'b')
	return (matrix_struct_opt(s, 0, 1));
    }
  if (choice == 0)
    return (build_list(s, XMIN, YMIN, 1));
  return (matrix_struct_per_line(s, 0, 0));
}
