/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:05:37 by acornia           #+#    #+#             */
/*   Updated: 2026/08/28 12:13:39 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	if (nb < 0)
	{
		return (0);
	}
	i = 1;
	res = 1;
	while (i <= nb)
	{
		res = res * i;
		i++;
	}
	return (res);
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
		printf("El numero es %d\n", num);
		printf("El resultado del factorial es: %d", ft_iterative_factorial(num));
		return (0);
	}
}
*/
