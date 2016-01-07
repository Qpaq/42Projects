#include "ft_printf.h"

int		main(void)
{
	int		ret;
	ret = ft_printf("%d", 5);
	ft_putchar('\n');
	ft_putnbr(ret);
}
