#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(int n)
{
	if (n >= 16)
		ft_puthex(n / 16);
	if ((n % 16) >= 10)
		ft_putchar((n % 16) - 10 + 65);
	else
		ft_putchar((n % 16) + 48);
}

int		main()
{
	int		a;
	a = 3;
	printf("%p\n", &a);
	printf("%d\n", (int)&a);
	ft_puthex((int)&a);
}
