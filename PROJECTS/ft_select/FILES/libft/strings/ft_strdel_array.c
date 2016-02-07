#include "libft.h"

void	ft_strdel_array(char ***as)
{
	char	**tab;

	tab = *as;
	while (*tab)
	{
		free(*tab);
		*tab = NULL;
		tab++;
	}
	free(*as);
	*as = NULL;
}
