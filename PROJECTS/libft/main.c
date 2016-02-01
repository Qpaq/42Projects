#include "FILES/libft.h"
#include <stdio.h>

int		main(void)
{
	printf("%s\n", ft_itoa_base(10, 16, 1));
	printf("%s\n", ft_itoa_base(16, 16, 1));
	printf("%s\n", ft_itoa_base(17, 16, 1));
	printf("%s\n", ft_itoa_base(5, 16, 1));
	return (0);
}
