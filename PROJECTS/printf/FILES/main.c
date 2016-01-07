#include "ft_printf.h"

int		main(void)
{
	int		ret;
	ret = ft_printf("tag 1: %d, tag2: %f %t \n", 5, 3.14);
	ft_putnbr(ret);
}
