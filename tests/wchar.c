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
	int	ret;

	wchar_t	a = L'é';
	wchar_t	b = L'א';
	wchar_t	c = L'您';
	wchar_t	d = L'好';
//	wchar_t	e[] = L"двуй";

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);

	printf("\n");

	printf("%zu\n", sizeof(a));
	printf("%zu\n", sizeof(b));
	printf("%zu\n", sizeof(c));
	printf("%zu\n", sizeof(d));

	printf("\n");

	ret = printf("%S\n", L"двуй");
	printf("%d", ret);
}
