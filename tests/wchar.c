#include <unistd.h>
#include <stdio.h>
#include <wchar.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		main(void)
{
	wchar_t	a = L'é';
	wchar_t	b = L'א';
	wchar_t	c = L'您';
	wchar_t	d = L'好';	
	wchar_t	e[] = L"двуй";

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%S\n", e);
}
