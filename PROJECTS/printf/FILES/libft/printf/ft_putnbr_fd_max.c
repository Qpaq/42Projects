#include "libft.h"

void	ft_putnbr_fd_max(intmax_t n, int fd)
{
	uintmax_t nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd_max(nbr / 10, fd);
		ft_putnbr_fd_max(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}
