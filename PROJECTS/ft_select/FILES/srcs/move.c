#include "ft_select.h"

/*
1: up
2: down
3: right
4: left
*/
void	ft_move(int key, t_select *params)
{
	if (key == 1)
	{
		params->curs_y -= params->curs_y == 0 ? 0 : 1;
		tputs(tgetstr("up", NULL), 1, putchar_select);
	}
	else if (key == 2 && params->curs_y < params->size_list)
	{
		params->curs_y += 1;
		tputs(tgetstr("do", NULL), 1, putchar_select);
	}
	else if (key == 3 && params->curs_x < (int)params->max_length)
	{
		params->curs_x += 1;
		tputs(tgetstr("nd", NULL), 1, putchar_select);
	}
	else if (key == 4)
	{
		params->curs_x -= params->curs_x == 0 ? 0 : 1;
		tputs(tgetstr("le", NULL), 1, putchar_select);
	}
}
