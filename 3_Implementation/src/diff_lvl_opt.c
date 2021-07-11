/**
 * @file diff_lvl_opt.c
 * @author Hemanth (hemanth.aradhyula@lttts.com)
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
static int	move_game_lvl(t_struct *s, char **str, int key)
{
  int		i;

  i = 0;
  if (key == KEY_UP)
    {
      if (s->lvl == 0)
        s->lvl = 2;
      else
        --s->lvl;
    }
  else if (key != 0)
    {
      if (s->lvl == 2)
	s->lvl = 0;
      else
	++s->lvl;
    }
  while (++i != 4)
    {
      if (i - 1 == s->lvl)
        cursor_position(s->game, i + 6, 6, str[i - 1]);
      else
        mvwprintw(s->game, i + 6, 6, str[i - 1]);
    }
  return (0);
}
/**
 * @brief selecting the difficulty level and features
 * 
 */
static int	print_diff_lvl_opt(t_struct *s)
{
  mvwprintw(s->game, 4, 6, "Select Difficulty Level :");
  mvwprintw(s->game, 14, 6, "Use arrow keys to move.");
  mvwprintw(s->game, 15, 6, "Press ENTER to chose.");
  mvwprintw(s->game, 16, 6, "Press b to go back.");
  return (0);
}
/**
 * @brief selection of Difficulty level 
 * 
 */
int	diff_lvl_opt(t_struct *s, int key)
{
  char	*str[3];

  wclear(s->game);
  s->lvl = 0;
  str[0] = "Easy";
  str[1] = "Medium";
  str[2] = "Hard";
  print_diff_lvl_opt(s);
  move_game_lvl(s, str, 0);
  wrefresh(s->game);
  while (s->mode != 0 && (key = getch()) != ENTER)
    if (key == KEY_UP || key == KEY_DOWN || key == 'b')
      {
	if (key == 'b')
	  {
	    wclear(s->game);
	    return (player_mode_opt(s, 0));
	  }
	move_game_lvl(s, str, key);
	wrefresh(s->game);
      }
  matrix_struct_opt(s, 0, 1);
  return (0);
}
