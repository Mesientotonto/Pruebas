/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 10:32:42 by acornia           #+#    #+#             */
/*   Updated: 2026/08/29 10:47:42 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_pos_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i != 0 && i % 3 == 0 && i % 5 == 0)
			write(1, "5", 1);
		else if (i != 0 && i % 5 == 0)
			write(1, "3", 1);
		else if (i != 0 && i % 3 == 0)
			write(1, "5", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	char	str[] = "Welcome to 42 School";

	printf("La frase original es: %s.\n", str);
	printf("La frase modificada es: ");
	fflush(stdout);
	ft_print_pos_value(str);
	return (0);
}
