/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:18:57 by acornia           #+#    #+#             */
/*   Updated: 2026/09/01 16:27:48 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_print(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i  >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rev_print(argv[1]);
		return (0);
	}
}