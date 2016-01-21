#include "FILES/libft.h"
#include <stdio.h>

int		main(void)
{
	char test[] = " \tje fais un test \n \t ";
	printf("%s", ft_strtrim_nolimit(test, 't', 'i', NULL));
	return (0);
}
