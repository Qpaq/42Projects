#include "ft_select.h"

/*
1: up
2: down
3: right
4: left
*/
void	ft_move(int key)
{
	if (key == 1)
		tputs(tgetstr("up", NULL), 1, putchar_select);
	else if (key == 2)
		tputs(tgetstr("do", NULL), 1, putchar_select);
	else if (key == 3)
		tputs(tgetstr("nd", NULL), 1, putchar_select);
	else if (key == 4)
		tputs(tgetstr("le", NULL), 1, putchar_select);
}
