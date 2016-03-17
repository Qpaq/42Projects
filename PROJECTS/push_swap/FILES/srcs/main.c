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

int		*init_piles(t_pushswap *data, char **argv, int argc)
{
	int		*pile;
	int		i;

	pile = (int *)ft_memalloc(sizeof(int) * argc);
	i = 0;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (NULL);
		pile[i] = ft_atoi(argv[i]);
		i++;
	}
	data->pile_a = pile;
	data->length_a = i;
	data->pile_b = (int *)ft_memalloc(sizeof(int));
	return (pile);
}

void	print_pile(int *pile, int length)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (i < length)
	{
		if (start)
			ft_putchar(' ');
		ft_putnbr(pile[i]);
		start = 1;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_pushswap	*data;

	if (argc == 1)
		return (0);
	data = (t_pushswap *)ft_memalloc(sizeof(t_pushswap));
	if (init_piles(data, ++argv, --argc) == NULL)
	{
		ft_printf("{red}Error in command line arguments{eoc}");
		return (0);
	}


	print_pile(data->pile_a, data->length_a);
	ft_printf("\na: %d, b: %d\n", data->length_a, data->length_b);
	print_pile(data->pile_b, data->length_b);

	ft_putendl("\npush");
	push_b(data);
	push_b(data);
	push_b(data);
	push_a(data);
	push_b(data);
	push_a(data);
	ft_putendl("bbbaba\n");

	print_pile(data->pile_a, data->length_a);
	ft_printf("\na: %d, b: %d\n", data->length_a, data->length_b);
	print_pile(data->pile_b, data->length_b);


	return (0);
}
