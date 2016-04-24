#include "push_swap.h"

int		ft_isnumber(char *value)
{
	int		i;

	i = 0;
	while (value[i])
	{
		if (!ft_isdigit(value[i]) && value[i] != '-' && value[i] != '+')
			return (0);
		i++;
	}
	if (ft_strlen(value) == 1)
		if (value[0] == '-' || value[0] == '+')
			return (0);
	return (1);
}

int		check_duplicate(int nb, int *pile, int length)
{
	int		i;

	i = 0;
	while (i < length)
	{
		if (pile[i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		*init_piles(t_pushswap *data, char **argv, int argc)
{
	int		*pile;
	int		i;
	int		nb;

	pile = (int *)ft_memalloc(sizeof(int) * argc);
	i = 0;
	if (ft_isnumber(argv[0]))
			data->smallest_a = ft_atoi(argv[0]);
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (NULL);
		nb = ft_atoi(argv[i]);
		if (!check_duplicate(nb, pile, i))
			return (NULL);
		if (nb <= data->smallest_a)
		{
			data->smallest_a = nb;
			data->pos_smallest_a = i;
		}
		pile[i] = ft_atoi(argv[i]);
		i++;
	}
	data->pile_a = pile;
	data->length_a = i;
	data->pile_b = (int *)ft_memalloc(sizeof(int));
	return (pile);
}

int		main(int argc, char **argv)
{
	t_pushswap	*data;

	if (argc == 1)
		return (0);
	data = (t_pushswap *)ft_memalloc(sizeof(t_pushswap));
	data->sequence = ft_strnew(1);
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		data->verbose = 1;
		argc--;
		argv++;
	}
	if (init_piles(data, ++argv, --argc) == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	sort_pile(data);
	ft_printf("{red}FINAL SEQUENCE (%d):\n%s{eoc}", data->nb_of_moves, ft_strtrim(data->sequence));
	return (0);
}
