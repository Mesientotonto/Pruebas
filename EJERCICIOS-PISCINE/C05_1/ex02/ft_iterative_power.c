/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:47:30 by acornia           #+#    #+#             */
/*   Updated: 2026/08/28 12:12:41 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	res;

	if (power < 0)
	{
		return (0);
	}
	i = 1;
	res = 1;
	while (i <= power)
	{
		res = res * nb;
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
	int	power;
	if (argc == 3)
	{
		num = str_to_int(argv[1]);
		power = str_to_int(argv[2]);
		printf("Vamos a elevar el numero %d por %d.\n", num, power);
		printf("El resultado es: %d.", ft_iterative_power(num, power));
		return (0);
	}
}
*/
