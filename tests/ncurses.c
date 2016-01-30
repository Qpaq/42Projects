#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int		main(void)
{
	initscr();	
	printf("%d / %d\n", LINES, COLS);
	endwin();
	return (0);
}
