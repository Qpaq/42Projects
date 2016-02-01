#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int		main(void)
{
	uintmax_t	u = 429496720295;
	intmax_t	i = -3270003567987;

	printf("uint: %u, int: %i\n", UINT_MAX, INT_MAX);
	printf("uint: %ju, int: %ji\n", u, i);
	return (0);
}
