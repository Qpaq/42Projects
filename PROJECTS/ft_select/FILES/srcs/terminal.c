#include "ft_select.h"

int		restore_terminal(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	tputs(tgetstr("ve", NULL), 1, putchar_select);
	tputs(tgetstr("te", NULL), 1, putchar_select);
	return (0);
}

int		init_raw_mode(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, putchar_select);
	tputs(tgetstr("vs", NULL), 1, putchar_select);
	return (0);
}
