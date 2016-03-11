#include "ft_select.h"

void	space_key_pressed(t_select *params)
{
	ft_printf("Window: %d / %d\nCursor: %d / %d\nList: %d\nMax: %zd\n", params->win_x, params->win_y, params->curs_x, params->curs_y, params->size_list, params->max_length);
}

void	return_key_pressed(t_select *params)
{
	restore_terminal();
	return_list(params);
	exit(0);
}

/*
1: up
2: down
3: right
4: left
*/
void	arrow_key_pressed(int key, t_select *params)
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
