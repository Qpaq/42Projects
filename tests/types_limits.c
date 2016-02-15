#include <stdio.h>
#include <stdint.h>
#include <limits.h>

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
	printf("long double %lu\n", sizeof(long double));
	printf("float %lu\n", sizeof(float));
	printf("uintmax %lu\n", sizeof(uintmax_t));
	printf("intmax %lu\n", sizeof(intmax_t));

// ============================================================

	printf("\nMAXIMUMS\n");
	printf("uintmax: %u, intmax: %i\n", UINT_MAX, INT_MAX);
	printf("longmax: %li, llongmax: %lli\n", LONG_MAX, LLONG_MAX);
	printf("ulongmax: %lu, ullongmax: %llu\n", ULONG_MAX, ULLONG_MAX);
}
