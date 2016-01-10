#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdlib.h>
# include <unistd.h>

int		sudoku(char **grid, int position);
void	print_sudoku(char **final_grid);
void	copy_sudo(char **original_grid, char **copy);
void	free_grid(char **grid);
int		is_valid_number(char **lines);
int		is_valid_char(char **line);
int		number_is_valid(char nb, char **grid, int line_number, int col_number);

#endif
