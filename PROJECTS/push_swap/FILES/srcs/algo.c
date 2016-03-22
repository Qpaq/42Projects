#include "push_swap.h"

/*
int		check_pile_reverse(int *pile, int length)
{
	int		i;

	i = 1;
	while (i < length)
	{
		if (pile[i - 1] > pile[i])
			return (0);
		i++;
	}
	return (1);
}
*/

int		check_pile(int *pile, int length)
{
	int		i;

	if (length == 1)
		return (1);
	i = 1;
	while (i < length)
	{
		if (pile[i - 1] < pile[i])
		{
			/*
			if (check_pile_reverse(pile, length))
				return (-1);
			else
			*/
				return (0);
		}
		i++;
	}
	return (1);
}

void	put_smallest_last(t_pushswap *data)
{
	int		i;

	i = 0;
	if (data->pos_smallest_a < data->length_a / 2)
		while (data->pos_smallest_a != data->length_a - 1)
			rotate_a(data);
	else
		while (data->pos_smallest_a != data->length_a - 1)
			reverse_rotate_a(data);
}

void	sort_pile(t_pushswap *data)
{
	while (42)
	{
		put_smallest_last(data);
		if (check_pile(data->pile_a, data->length_a))
		{
			if (data->length_b == 0)
				break ;
			else
				while (data->length_b > 0)
					push_a(data);
		}
		else
			push_b(data);
	}
}
/*
	print_pile(data->pile_a, data->length_a);
	print_pile(data->pile_b, data->length_b);
	ft_printf("\na: %d, b: %d // Smallest: %d (%d)\n", data->length_a, data->length_b, data->smallest_a, data->pos_smallest_a);

	ft_putchar('\n');
	sort_pile(data);

	print_pile(data->pile_a, data->length_a);
	print_pile(data->pile_b, data->length_b);
	ft_printf("\na: %d, b: %d // Smallest: %d (%d)\n", data->length_a, data->length_b, data->smallest_a, data->pos_smallest_a);
	*/
