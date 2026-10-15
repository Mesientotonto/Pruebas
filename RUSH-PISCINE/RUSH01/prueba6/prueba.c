/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 13:03:51 by acornia           #+#    #+#             */
/*   Updated: 2026/08/23 13:22:48 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putchar(grid[row][col] + '0');
			if (col < 3)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int	parse_input(char *str, int views[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4' || j >= 16)
				return (0);
			views[j] = str[i] - '0';
			j++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (j == 16 && str[i - 1] != ' ');
}

int	is_valid(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_views(int grid[4][4], int v[16])
{
	int	i;
	int	j;
	int	max;
	int	count;

	i = 0;
	while (i < 4)
	{
		max = 0;
		count = 0;
		j = 0;
		while (j < 4)
		{
			if(grid[j][i] > max)
			{
				max = grid[j][i];
				count++;
			}
			j++;
		}
		if (count != v[i])
			return (0);
		i++;
	}
	return (1);
}

int	solve(int grid[4][4], int v[16], int row, int col)
{
	int	num;

	if (row == 4)
		return (check_views(grid, v)); // Falta añadir las otras 3 vistas de forma sencilla
	if (col == 4)
		return (solve(grid, v, row + 1, 0));
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, v, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	views[16];
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	if (argc != 2 || !parse_input(argv[1], views))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (solve(grid, views, 0 , 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}

