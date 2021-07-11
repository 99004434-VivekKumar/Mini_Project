/**
 * @file print_mode.c
 * @brief funtion definitions of each player mode options
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"

/**
 * @brief player mode selection through the arrow keys
 * 
 * @param w 
 * @param str 
 * @return int 
 */

int	cursor_position_notselectt(WINDOW *w, int y, int x, char *str)
{
  wattron(w, A_UNDERLINE);
  wattron(w, COLOR_PAIR(2));
  mvwprintw(w, y, x, str);
  wattroff(w, A_UNDERLINE);
  wattroff(w, COLOR_PAIR(2));
  return (0);
}

int	cursor_position(WINDOW *w, int y, int x, char *str)
{
  wattron(w, COLOR_PAIR(2));
  wattron(w, A_REVERSE);
  mvwprintw(w, y, x, str);
  wattroff(w, COLOR_PAIR(2));
  wattroff(w, A_REVERSE);
  return (0);
}

int	print_videorev(WINDOW *w, int y, int x, char *str)
{
  wattron(w, A_REVERSE);
  mvwprintw(w, y, x, str);
  wattroff(w, A_REVERSE);
  return (0);
}
