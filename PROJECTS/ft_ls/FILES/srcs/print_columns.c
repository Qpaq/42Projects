#include "ft_ls.h"

int		get_larger_size_or_links(t_files *head, char field)
{
	t_files	*ptr;
	int		largest;
	int		tmp;

	ptr = head;
	largest = 0;
	while (ptr)
	{
		if (field == 0)
			tmp = ptr->links;
		else
			tmp = ptr->size;
		if ((tmp = ft_strlen(ft_itoa(tmp))) > largest)
			largest = tmp;
		ptr = ptr->next;
	}
	return (largest);
}

void	pad_with_spaces(t_files *file)
{
}
