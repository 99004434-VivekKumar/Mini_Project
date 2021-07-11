#ifndef MATRIX_H_
# define MATRIX_H_

# define ENTER 10
# define ESCAPE 27
# define SPACE 32
# define YMIN 5
# define YMAX 17
# define XMIN 24

# include <stdlib.h>
# include <ncurses.h>
# include <curses.h>

typedef struct	s_list
{
  int		x;
  int		y;
  int		pos;
  int		select;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_struct
{
  WINDOW	*game;
  int		mode;
  int		lvl;
  int		line;
  int		al_per_line;
  int		turn;
}		t_struct;


int	consol_color(WINDOW *w, int y, int x, int key);

/**
 * @brief Dispalys the winner in the game 
 * 
 */
int	win_display(t_struct *s, int tm);

int	print_opti(t_struct *s, t_list *list);

/**
 * @brief Dispalys the turn to play
 * 
 */
int	print_list(t_struct *s, t_list *list, int i);

int	matrix_size(t_list *list, int y);

/**
 * @brief Deletes the element in the list
 * 
*/
int	matrix_del(t_struct *s, t_list *list, int i, int y);

int	matrix(t_struct *s, t_list *list, int i, int y);

/**
 * @brief Checks the difficulty level
 * 
 */
int	check_lvl(t_struct *s, t_list *list);

/**
 * @brief Creates the size of list 
 * 
 */
int	list_size(t_list *list);

/**
 * @brief Deletes the list w
 * 
 */
int	delete_list(t_list **list);

int	add_next_elem(t_list **list, int x, int y);

int	init_list(t_list **list, int x, int y);

/**
 * @brief Move in left and right direction
 * 
 */
int	move_left_right(t_struct *s, t_list *list, int key);

/**
 * @brief Choose the level of difficulty for game 
 * 
 */
int	diff_lvl_opt(t_struct *s, int key);

/**
 * @brief Instructions of the game for user
 * 
 */
int	matrix_line_opt(t_struct *s, int key, int i, int choice);

/**
 * @brief Builds the list of elements
 * 
 */
int	build_list(t_struct *s, int x, int y, int max);

/**
 * @brief selectts the maximum number of elemnts in list
 * 
 */
int	case_matrix(t_struct *s, t_list *list);
/**
 * @brief Dispalys the options of different modes 
 * 
 */
int	player_mode_opt(t_struct *s, int key);

/**
 * @brief Game between two players
 * 
 */
int	player_vs_player(t_struct *s, t_list *list, int key, int lock);

/**
 * @brief Game between Computer and a player
 * 
 */
void	player_vs_bot(t_struct *s, t_list *list, int key, int lock);

/**
 * @brief Game between two compuetrs
 * 
 */
int	bot_vs_bot(t_struct *s, t_list *list, int lock);

/**
 * @brief Keys to move directions
 * 
 */
int	move_up_down(t_struct *s, t_list *list, int key);

/**
 * @brief Loads the game
 * 
 */
int	load_game(t_struct *s, t_list *list);

/**
 * @brief Deletes the selectted list in the game
 * 
 */
int	delete_selectted(t_struct *s, t_list **list, int *lock);

/**
 * @brief Position selecttion
 * 
 */
int	selectt_pos(t_struct *s, t_list *list, int *lock);

int	str_put(char *str, int output);

int	print_videorev(WINDOW *w, int y, int x, char *str);

int	cursor_position_notselectt(WINDOW *w, int y, int x, char *str);

/**
 * @brief Displays the cursor position
 * 
 */
int	cursor_position(WINDOW *w, int y, int x, char *str);

/**
 * @brief To quit the game
 * 
 */
void	quit(t_struct *s);

/**
 * @brief Calculates the number of lines which game is being played
 * 
 */
int	matrix_line_count(t_list *tmp, t_list *list, int i);

/**
 * @brief Console interface
 * 
 */
int	console_config(WINDOW *w, t_list *list);

/**
 * @brief Chooses the matrix structure of games i.e rectangular or pyramid
 * 
 */
int	matrix_struct_opt(t_struct *s, int key, int choice);

int	matrix_struct_per_line(t_struct *s, int key, int i);

int	rectangular_matrix_build(t_struct *s, int x, int y, int i);


/**
 * @brief Dealloactes the memory after the game is over
 * 
 */
char	**deloct_malloc(char **str, int sizeb, int size);

int	free_memory(char **str);

#endif /* !MATRIX_H_ */
