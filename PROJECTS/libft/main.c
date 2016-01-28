#include "FILES/libft.h"
#include <stdio.h>

int		main(void)
{
	char	a[] = "		\nt";
	char	*b = ft_strtrim(a);

	ft_putendl(a);
	ft_putendl(b);
	return (0);
}
