/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 11:06:28 by acornia           #+#    #+#             */
/*   Updated: 2026/08/28 12:11:20 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	else
	{
		return (nb * ft_recursive_power(nb, power - 1));
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
	int	nb;
	int	power;

	if (argc == 3)
	{
		nb  = str_to_int(argv[1]);
		power = str_to_int(argv[2]);
		printf("Vamos a elevar el numero %d por %d.\n", nb, power);
		printf("El resultado es: %d.\n", ft_recursive_power(nb, power));
	}
	return (0);
}
*/
