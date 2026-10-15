/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 12:59:14 by acornia           #+#    #+#             */
/*   Updated: 2026/08/22 13:57:23 by acornia          ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

#include <unistd.h>

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

void	print_grid(int grid[4][4])
{
	int		r;
	int		c;
	char	ch;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			ch = grid[r][c] + '0';
			write(1, &ch, 1);
			if (c < 3)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}
