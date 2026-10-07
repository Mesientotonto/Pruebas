/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 13:43:46 by acornia           #+#    #+#             */
/*   Updated: 2026/08/31 12:36:42 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
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
// 		printf("The origienal number is: %d.\n", num);
// 		printf("His factorial is: %d.\n", ft_recursive_factorial(num));
// 		return (0);
// 	}
// 	printf("You haven't entered enough values.");
// 	return (0);
// }
