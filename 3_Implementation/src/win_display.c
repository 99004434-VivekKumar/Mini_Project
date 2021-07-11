/**
 * @file win_display.c
 * @author Praveen Kumar G - 99004437(praveen.kumar5@ltts.com)
 * @brief function definition for printing winner of the game
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include <time.h>
#include "matrix.h"

/**
 * @brief Dispalys the winner of the game
 * 
 */
static int	win_displayner(t_struct *s)
{
  if (s->turn == 1)
    {
      if (s->mode == 0)
        cursor_position(s->game, 4, 6, "Player 1 WON !");
      if (s->mode == 1)
        cursor_position(s->game, 4, 6, "You WON !");
      if (s->mode == 2)
        cursor_position(s->game, 4, 6, "Bot1 WON !");
    }
  else
    {
      if (s->mode == 0)
        cursor_position(s->game, 4, 6, "Player 2 WON !");
      if (s->mode == 1)
        cursor_position(s->game, 4, 6, "Bot WON !");
      if (s->mode == 2)
        cursor_position(s->game, 4, 6, "Bot2 WON !");
    }
  return (0);
}

/**
 * @brief Displays the duration of game played
 * 
 */
int		win_display(t_struct *s, int tm)
{
  time_t	t;

  t = time(NULL);
  wclear(s->game);
  win_displayner(s);
  if (t != -1 && tm != -1)
    mvwprintw(s->game, 7, 6, "Game duration : %d seconds !", t - tm);
  mvwprintw(s->game, 10, 6, "Press ENTER for Main Screen");
  wrefresh(s->game);
  while (getch() != ENTER)
    ;
  wclear(s->game);
  return (player_mode_opt(s, 0));
}
