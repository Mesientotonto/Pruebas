/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 13:36:13 by acornia           #+#    #+#             */
/*   Updated: 2026/08/22 13:50:30 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	parse_input(char *str, int views[16]);
void	print_grid(int grid[4][4]);
int	solve(int grid[4][4], int views[16], int pos);

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	views[16];

	init_grid(grid);
	if (argc != 2 || !parse_input(argv[1], views))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (solve(grid, views, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
