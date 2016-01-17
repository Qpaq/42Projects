#include <stdio.h>

int		main(void)
{
	printf("char %lu\n", sizeof(char));
	printf("char* %lu\n", sizeof(char*));
	printf("int %lu\n", sizeof(int));
	printf("int* %lu\n", sizeof(int*));
	printf("unsigned int %lu\n", sizeof(unsigned int));
	printf("long %lu\n", sizeof(long));
	printf("long long %lu\n", sizeof(long long));
	printf("double %lu\n", sizeof(double));
	printf("float %lu\n", sizeof(float));
}
