#include "push_swap.h"

void	rotate_a(t_pushswap *data)
{
	int		first;
	int		i;

	if (data->length_a > 1)
	{
		first = data->pile_a[0];
		i = 1;
		while (i < data->length_a)
		{
			data->pile_a[i - 1] = data->pile_a[i];
			i++;
		}
		data->pile_a[i - 1] = first;
		data->pos_smallest_a -= 1;
		if (data->pos_smallest_a == -1)
			data->pos_smallest_a = data->length_a - 1;
	}
}

void	rotate_b(t_pushswap *data)
{
	int		first;
	int		i;

	if (data->length_b > 1)
	{
		first = data->pile_b[0];
		i = 1;
		while (i < data->length_b)
		{
			data->pile_b[i - 1] = data->pile_b[i];
			i++;
		}
		data->pile_b[i - 1] = first;
	}
}

void	rotate_ab(t_pushswap *data)
{
	rotate_a(data);
	rotate_b(data);
}
