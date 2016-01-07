#include <stdio.h>

int		square(int n)
{
	return (n * n);
}

int		main(void)
{
	int		i;
	
	i = 1;
	while (i <= 10)
	{
		printf("%d\n", square(i));
		i++;
	}
	return (0);
}
