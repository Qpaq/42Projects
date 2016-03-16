#include "push_swap.h"

int		ft_isnumber(char *value)
{
	int		i;

	i = 0;
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**init_pile(t_pushswap *data, char **argv, int argc)
{
	char	**pile;
	int		i;

	pile = (char **)ft_memalloc(sizeof(char *) * argc);
	i = 0;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (NULL);
		pile[i] = ft_strdup(argv[i]);
		i++;
	}
	data->pile_a = pile;
	data->length_a = i;
	return (pile);
}

void	print_pile(char **pile, int length)
{
	int		i;

	i = 0;
	while (i < length)
	{
		ft_putendl(pile[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_pushswap	*data;

	if (argc == 1)
		return (0);
	data = (t_pushswap *)ft_memalloc(sizeof(t_pushswap));
	if (init_pile(data, ++argv, --argc) == NULL)
	{
		ft_printf("{red}Error in command line arguments{eoc}");
		return (0);
	}
	print_pile(data->pile_a, data->length_a);
	ft_putnbr(data->length_a);
	return (0);
}
