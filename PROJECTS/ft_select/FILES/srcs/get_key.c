#include "ft_select.h"

int		is_escape(char *key)
{
	if (key[0] == 27 && key[1] == 0 && key[2] == 0)
		return (1);
	return (0);
}

int		is_enter(char *key)
{
	if (key[0] == 10 && key[1] == 0 && key[2] == 0)
		return (1);
	return (0);
}

int		is_space(char *key)
{
	if (key[0] == 32 && key[1] == 0)
		return (1);
	return (0);
}

int		is_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] >= 65 && key[2] <= 68)
		return (1);
	return (0);
}


void	get_key(t_select *params)
{
	char	*key;
	
	(void)params; // DELTE

	key = ft_strnew(4);
	while (read(0, key, 3))
	{
		if (is_escape(key))
			break ;
		else if (is_space(key))
			ft_putendl("space");
		else if (is_enter(key))
			ft_printf("%zd", params->max_length);
		else if (is_arrow(key))
			ft_move(key[2] - 64);
	//	ft_printf("0: %d\n1: %d\n2: %d\n3: %d\n\n", key[0], key[1], key[2], key[3]);
		ft_bzero(key, 4);
	}
}
