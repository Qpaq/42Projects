#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_power(int n, int pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_power(n, pow - 1));
}

char	*ft_strrev(char *str)
{
	int		n;
	int		length;
	char	temp;

	length = 0;
	while (str[length])
		length++;
	while (n < (length / 2))
	{
		temp = str[n];
		str[n] = str[length - n - 1];
		str[length - n - 1] = temp;
		n++;
	}
	return (str);
}

char	*ft_itoa(int n, int base)
{
	char	*str;
	int		sign;
	int		i;
	int		length;

	i = 0;
	if ((sign = n) < 0)
	{
		n = -n;
		i++;
	}
	length = 0;
	while (n > ft_power(base, length))
		length++;
	str = (char*)malloc(length * sizeof(*str));
	while (n > 0)
	{
		if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + 'A';
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

int main()
{
	printf("%s\n", ft_itoa(345, 10));
	printf("%s\n", ft_itoa(5, 2));
	printf("%s\n", ft_itoa(15, 2));
	printf("%s\n", ft_itoa(35, 16));
	printf("%s\n", ft_itoa(200, 16));
	printf("%s\n", ft_itoa(101, 2));
}
