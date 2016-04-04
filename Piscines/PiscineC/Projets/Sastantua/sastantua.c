/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 15:08:59 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/09 21:43:47 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	levels_size(int size,
					int *level_length_first_line, int *level_length_last_line)
{
	int		level;
	int		augmentation;

	level = 1;
	level_length_first_line[1] = 3;
	augmentation = 2;
	while (level <= size)
	{
		if (level % 2 == 0)
			augmentation += 1;
		if (level != 1)
		{
			level_length_first_line[level] = level_length_last_line[level - 1]
											+ augmentation * 2;
		}
		level_length_last_line[level] = level_length_first_line[level]
										+ (level + 2 - 1) * 2;
		level++;
	}
}

void	print_line(int *pyramide, int current_line,
					int *lengthfirstline, int *lengthlastline)
{
	int		start_print;
	int		current_char;

	current_char = 1;
	while (current_char <= lengthlastline[pyramide[0]])
	{
		start_print = ((lengthlastline[pyramide[0]] -
						(lengthfirstline[pyramide[1]]
						+ (current_line - 1) * 2)) / 2) + 1;
		if (current_char == start_print)
			ft_putchar('/');
		else if (current_char == (start_print +
								(lengthfirstline[pyramide[1]]
								+ (current_line - 1) * 2) - 1))
			ft_putchar('\\');
		else if ((current_char > start_print) && (current_char <
							(start_print + (lengthfirstline[pyramide[1]]
								+ (current_line - 1) * 2) - 1)))
			ft_putchar('*');
		else
			ft_putchar(' ');
		current_char++;
	}
}

void	print_line_door(int *pyramide, int current_line,
						int *lengthfirstline, int *lengthlastline)
{
	int		start_print;
	int		current_char;

	current_char = 1;
	while (current_char <= lengthlastline[pyramide[0]])
	{
		start_print = ((lengthlastline[pyramide[0]]
					- (lengthfirstline[pyramide[1]]
						+ (current_line - 1) * 2)) / 2) + 1;
		if (current_char == start_print)
			ft_putchar('/');
		else if (current_char == (start_print
				+ (lengthfirstline[pyramide[1]] + (current_line - 1) * 2) - 1))
			ft_putchar('\\');
		else if ((current_char > start_print)
				&& (current_char < (start_print
						+ (lengthfirstline[pyramide[1]]
						+ (current_line - 1) * 2) - 1)))
			ft_putchar('*');
		else
			ft_putchar(' ');
		current_char++;
	}
}

void	print_level(int *pyramide, int *lengthfirstline, int *lengthlastline)
{
	int		current_line;

	current_line = 1;
	while (current_line <= pyramide[1] + 2)
	{
		if (pyramide[1] < pyramide[0])
			print_line(pyramide, current_line, lengthfirstline, lengthlastline);
		else
			print_line_door(pyramide, current_line,
							lengthfirstline, lengthlastline);
		current_line++;
		ft_putchar('\n');
	}
}

void	sastantua(int size)
{
	int		level;
	int		level_length_first_line[size];
	int		level_length_last_line[size];
	int		pyramide[3];

	pyramide[0] = size;
	pyramide[2] = 1;
	level = 1;
	levels_size(size, level_length_first_line, level_length_last_line);
	while (level <= size)
	{
		pyramide[1] = level;
		if (level % 2 == 1)
			pyramide[2] += 2;
		print_level(pyramide, level_length_first_line, level_length_last_line);
		level++;
	}
}
