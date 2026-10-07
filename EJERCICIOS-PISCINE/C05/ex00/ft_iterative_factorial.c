/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 13:26:59 by acornia           #+#    #+#             */
/*   Updated: 2026/08/31 12:35:30 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	if (nb < 0)
		return (0);
	i = 1;
	res = 1;
	while (i <= nb)
	{
		res = res * i;
		i++;
	}
	return (res);
}

// int	str_to_int(char *str)
// {
// 	int	i;
// 	int	res;
// 	int	sign;

// 	i = 0;
// 	res = 0;
// 	sign = 1;

// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (res * sign);
// }

// int	main(int argc, char **argv)
// {
// 	int	num;

// 	if (argc == 2)
// 	{
// 		num = str_to_int(argv[1]);
// 		printf("The original numer is: %d.\n", num);
// 		printf("His factorial is: %d.\n", ft_iterative_factorial(num));
// 		return (0);
// 	}
// 	return (0);
// }
