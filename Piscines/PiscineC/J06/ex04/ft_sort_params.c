/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 20:27:32 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/13 15:38:45 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	**sort_table(char **tab, int size)
{
	int		iarg;
	int		iletter;
	char	*temp;

	iarg = 2;
	iletter = 0;
	while (iarg < size)
	{
		while (tab[iarg][iletter] != '\0')
		{
			if (tab[iarg - 1][iletter] > tab[iarg][iletter])
			{
				temp = tab[iarg];
				tab[iarg] = tab[iarg - 1];
				tab[iarg - 1] = temp;
				iarg = 1;
				break ;
			}
			iletter++;
		}
		iletter = 0;
		iarg++;
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	int		iarg;
	int		iletter;

	iarg = 1;
	iletter = 0;
	argv = sort_table(argv, argc - 1);
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
