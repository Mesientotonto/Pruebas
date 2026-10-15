/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 11:39:59 by acornia           #+#    #+#             */
/*   Updated: 2026/08/22 12:05:20 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_line(int line[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ft_putchar(line[i] + '0');
		if (i < 3)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int	check_left(int line[4], int expected)
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			visible++;
		}
		i++;
	}
	return(visible == expected);
}

int	main(int argc, char **argv)
{
	int	linea[4] = {1, 3, 2, 4};
	int	rowleft;

	if (argc != 2)
	{
		write(1, "error", 5);
		return(1);
	}
	rowleft = argv[1][0] - '0';
	if (check_left(linea, rowleft))
		print_line(linea);
	else
		write(1, "error", 5);
	return (0);
}
