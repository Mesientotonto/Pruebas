/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:42:07 by acornia           #+#    #+#             */
/*   Updated: 2026/08/28 12:13:09 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (1);
	}
	else
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
}
/*
int	str_to_int(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	num;
	if (argc == 2)
	{
		num = str_to_int(argv[1]);
		printf("El numero es: %d\n", num);
		printf("El factorial es: %d", ft_recursive_factorial(num));
		return (0);
	}
}
*/
