/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 18:52:53 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/12 19:54:03 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char *argv[])
{
	int		iarg;
	int		iletter;

	iarg = 1;
	iletter = 0;
	while (iarg < argc)
	{
		while (argv[iarg][iletter] != '\0')
		{
			ft_putchar(argv[iarg][iletter]);
			iletter++;
		}
		ft_putchar('\n');
		iletter = 0;
		iarg++;
	}
	return (0);
}
