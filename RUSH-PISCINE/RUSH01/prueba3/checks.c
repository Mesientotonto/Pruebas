/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 13:09:13 by acornia           #+#    #+#             */
/*   Updated: 2026/08/22 13:53:56 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row_left(int grid[4][4], int row, int expected)
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	while (i < 4)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			visible++;
		}
		i++;
	}
	return (visible == expected);
}

int	check_row_right(int grid[4][4], int row, int expected)
{
	int	i;
	int	max;
	int	visible;

	i = 3;
	max = 0;
	visible = 0;
	while (i >= 0)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			visible++;
		}
		i--;
	}
	return (visible == expected);
}

int	check_col_top(int grid[4][4], int col, int expected)
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	while (i < 4)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			visible++;
		}
		i++;
	}
	return (visible == expected);
}

int	check_col_bottom(int grid[4][4], int col, int expected)
{
	int	i;
	int	max;
	int	visible;

	i = 3;
	max = 0;
	visible = 0;
	while (i >= 0)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			visible++;
		}
		i--;
	}
	return (visible == expected);
}

int	check_all_views(int grid[4][4], int v[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_col_top(grid, i, v[i])
			|| !check_col_bottom(grid, i, v[i + 4])
			|| !check_row_left(grid, i, v[i + 8])
			|| !check_row_right(grid, i, v[i + 12]))
			return (0);
		i++;
	}
	return (1);
}
