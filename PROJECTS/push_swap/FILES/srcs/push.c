#include "push_swap.h"

void	push_a(t_pushswap *data)
{
	int		*new_pile_a;

	if (data->length_b > 0)
	{
		new_pile_a = (int *)ft_memalloc(sizeof(int) * (data->length_a + 1));
		ft_memcpy(new_pile_a, data->pile_a, sizeof(int) * data->length_a);
		ft_memdel((void **)&(data->pile_a));
		new_pile_a[data->length_a] = data->pile_b[data->length_b - 1];
		data->pile_a = new_pile_a;
		data->length_a += 1;
		data->length_b -= 1;
	}
}

void	push_b(t_pushswap *data)
{
	int		*new_pile_b;

	if (data->length_a > 0)
	{
		new_pile_b = (int *)ft_memalloc(sizeof(int) * (data->length_b + 1));
		ft_memcpy(new_pile_b, data->pile_b, sizeof(int) * data->length_b);
		ft_memdel((void **)&(data->pile_b));
		new_pile_b[data->length_b] = data->pile_a[data->length_a - 1];
		data->pile_b = new_pile_b;
		data->length_b += 1;
		data->length_a -= 1;
	}
}
