
void	ft_putchar(char c);

void	ft_print_hexa(unsigned char nb)
{
	if (nb >= 16)
		ft_print_hexa(nb / 16);
	if ((nb % 16) >= 10)
		ft_putchar((nb % 16) - 10 + 65);
	else
		ft_putchar((nb % 16) + 48);
}
