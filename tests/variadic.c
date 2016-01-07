#include <stdio.h>
#include <stdarg.h>

int		func_variadic(int first, ...)
{
	int		sum;
	va_list	ap;

	sum = first;
	va_start(ap, first);
	sum += va_arg(ap, int);
	sum += va_arg(ap, int);
	va_end(ap);
	return (sum);
}

int		main(void)
{
	int result;

	result = func_variadic(3, 4, 5);

	printf("%d", result);
	return (0);
}
