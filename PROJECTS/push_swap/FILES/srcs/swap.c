#include "push_swap.h"

void	swap_a(t_pushswap *data)
{
	int		temp;

	if (data->length_a > 1)
	{
		temp = data->pile_a[data->length_a - 1];
		data->pile_a[data->length_a - 1] = data->pile_a[data->length_a - 2];
		data->pile_a[data->length_a - 2] = temp;
		if (data->pos_smallest_a == data->length_a - 1)
			data->pos_smallest_a = data->length_a - 2;
		else if (data->pos_smallest_a == data->length_a - 2)
			data->pos_smallest_a = data->length_a - 1;
	}
}

void	swap_b(t_pushswap *data)
{
	int		temp;

	if (data->length_b > 1)
	{
		temp = data->pile_b[data->length_b - 1];
		data->pile_b[data->length_b - 1] = data->pile_b[data->length_b - 2];
		data->pile_b[data->length_b - 2] = temp;
	}
}

void	swap_ab(t_pushswap *data)
{
	swap_a(data);
	swap_b(data);
}
