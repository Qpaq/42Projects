#include "push_swap.h"

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
