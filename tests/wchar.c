#include <unistd.h>
#include <stdio.h>
#include <wchar.h>

int		main(void)
{
	char un = 229;
	char deux = 65;
	char trois = 89;
	write(1, &un, 1);
	write(1, &deux, 1);
	write(1, &trois, 1);

	/*
	int	ret;

	wchar_t	a = L'é';
	wchar_t	b = L'א';
	wchar_t	c = L'您';
	wchar_t	d = L'好';
	wchar_t e = L'α';
//	wchar_t	e[] = L"двуй";

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);

	ret = printf("%S\n", L"Test");
	printf("%d", ret);
	*/
}
