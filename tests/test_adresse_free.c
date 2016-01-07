#include <stdio.h>
#include <stdlib.h>

int main()
{
	char	*a;
	char	*b;

	a = malloc(5);
	b = malloc(10);
	printf("a: %p\nb: %p\n\n", a, b);
	printf("a: %s\nb: %s\n\n", a, b);

	*a = 'd';
	*(a+1) = 'a';
	*(a+2) = 0;
	*b = 't';
	*(b+1) = 'e';
	*(b+2) = 0;
	printf("a: %p\nb: %p\n\n", a, b);
	printf("a: %s\nb: %s\n\n", a, b);
	
	free(a);
	free(b);
	printf("a: %p\nb: %p\n\n", a, b);
	printf("a: %s\nb: %s\n\n", a, b);
}
