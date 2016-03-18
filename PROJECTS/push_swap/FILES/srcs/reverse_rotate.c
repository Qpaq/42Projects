#include "push_swap.h"

void	reverse_rotate_a(t_pushswap *data)
{
	int		last;
	int		i;

	if (data->length_a > 1)
	{
		last = data->pile_a[data->length_a - 1];
		i = data->length_a - 1;
		while (i > 0)
		{
			data->pile_a[i] = data->pile_a[i - 1];
			i--;
		}
		data->pile_a[0] = last;
	}
}

void	reverse_rotate_b(t_pushswap *data)
{
	int		last;
	int		i;

	if (data->length_b > 1)
	{
		last = data->pile_b[data->length_b - 1];
		i = data->length_b - 1;
		while (i > 0)
		{
			data->pile_b[i] = data->pile_b[i - 1];
			i--;
		}
		data->pile_b[0] = last;
	}
}

void	reverse_rotate_ab(t_pushswap *data)
{
	reverse_rotate_a(data);
	reverse_rotate_b(data);
}
