
/**
 * @file main.c
 * @author Praveen Kumar G - 99004437(praveen.kumar5@ltts.com)
 * @brief function definition for opening page of game and background
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include "matrix.h"

int	start_curse()
{
  if (initscr() == NULL)
    return (str_put("Couldn't initscr.\n", 2));
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_YELLOW, COLOR_BLUE);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  curs_set(0);
  if (noecho() == ERR)
    return (str_put("Couldn't noecho.\n", 2));
  if (keypad(stdscr, TRUE) == ERR)
    return (str_put("Couldn't keypad.\n", 2));
  return (0);
}
/**
 * @brief quits the game
 * 
 */
void	quit(t_struct *s)
{
  if (s != NULL)
    free(s);
  endwin();
  exit(0);
}

int		main()
{
  t_struct	*s;
  WINDOW	*frame;

  if (start_curse() == -1 || (s = malloc(sizeof(*s))) == NULL)
    quit(s);
  if ((frame = newwin(25, 51, 1, 3)) == NULL)
    return (str_put("Couldn't create frame window.\n", 2));
  if ((s->game = newwin(23, 49, 2, 4)) == NULL)
    return (str_put("Couldn't create game window.\n", 2));
  wbkgd(frame, COLOR_PAIR(3));
  wbkgd(s->game, COLOR_PAIR(1));
  wborder(frame, '+', '+', '+', '+', '+', '+', '+', '+');
  wrefresh(stdscr);
  wrefresh(frame);
  player_mode_opt(s, 0);
  quit(s);
  return (0);
}
