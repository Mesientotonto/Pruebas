/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42madrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 13:58:21 by acornia           #+#    #+#             */
/*   Updated: 2026/09/01 14:16:20 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_42madrid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i != 0 && i % 3 == 0 && i % 5 == 0)
			write(1, "7", 1);
		else if (i != 0 && i % 5 == 0)
			write(1, "3", 1);
		else if (i != 0 && i % 3 == 0)
			write(1, "5", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("La frase original es: %s.\n", argv[1]);
		printf("La frase cambida es:");
		fflush(stdout);
		ft_42madrid(argv[1]);
		write(1, "\n", 1);
		return (0);
	}
}