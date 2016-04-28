#include "FILES/libft.h"
#include <stdio.h>

int		main(void)
{
	char 	a[] = "salu-t---davi";
	char	**test;
	test = ft_strsplit(a, '-');
	ft_putstr_array(test, '*');

//	printf("%s", ft_str_replace(test, "l", ""));
	return (0);
}
