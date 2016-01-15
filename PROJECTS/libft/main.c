#include "FILES/libft.h"

int		main(void)
{
	char	a[] = "david";
	char	b[20] = "TEDGUI";
	char	*res;
	res = ft_strjoin_nolimit(a, "/", b);
	ft_putendl(res);
	return (0);
}
