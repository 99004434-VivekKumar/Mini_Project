/**
 * @file player_mode_opt.c
 * @author Vivek Kumar Yadav - 99004434(vivek.yadav@ltts.com)
 * @brief funtion definitions of each player mode options
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"

/**
 * @brief player mode selecttion through the arrow keys
 * 
 * @param s 
 * @param str 
 * @param key 
 * @return int 
 */
static int	move_game_mode(t_struct *s, char **str, int key)
{
  int		i;

  i = 0;
  if (key == KEY_UP)
    {
      if (s->mode == 0)
	s->mode = 3;
      else
	--s->mode;
    }
  else if (key != 0)
    {
      if (s->mode == 3)
	s->mode = 0;
      else
	++s->mode;
    }
  while (++i != 5)
    {
      if (i - 1 == s->mode)
	cursor_position(s->game, i + 6, 6, str[i - 1]);
      else
	mvwprintw(s->game, i + 6, 6, str[i - 1]);
    }
    return (0);
}

/**
 * @brief display options for player mode selecttion and other options
 * 
 * @param s 
 * @param key 
 * @return int 
 */
int	player_mode_opt(t_struct *s, int key)
{
  char	*str[4];

  s->mode = 0;
  str[0] = "Player vs Player";
  str[1] = "Player vs Bot";
  str[2] = "Bot1 vs Bot2";
  str[3] = "Exit";
  mvwprintw(s->game, 4, 6, "Select Player Mode:");
  mvwprintw(s->game, 14, 6, "Use Arrow Keys to Move.");
  mvwprintw(s->game, 15, 6, "Press ENTER to Choose");
  move_game_mode(s, str, 0);
  wrefresh(s->game);
  while ((key = getch()) != ENTER)
    {
      if (key == KEY_UP || key == KEY_DOWN)
	{
	  move_game_mode(s, str, key);
	  wrefresh(s->game);
	}
    }
  if (s->mode == 3)
    quit(s);
  diff_lvl_opt(s, 0);
  return (0);
}
