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

char	**init_pile(char **argv, int argc)
{
	char	**pile;
	int		i;

	pile = (char **)ft_memalloc(sizeof(char *) * argc);
	i = 0;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
			return (NULL);
		pile[i] = ft_strdup(argv[i]);
		i++;
	}
	pile[i] = NULL;
	return (pile);
}

int		main(int argc, char **argv)
{
	char	**pile_a;

	if (argc == 1)
		return (0);
	if ((pile_a = init_pile(++argv, --argc)) == NULL)
	{
		ft_printf("{red}Error in command line arguments{eoc}");
		return (0);
	}
	while (*pile_a)
	{
		ft_putendl(*pile_a);
		pile_a++;
	}
	return (0);
}
