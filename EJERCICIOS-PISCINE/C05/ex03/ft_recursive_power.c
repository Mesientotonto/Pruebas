/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 14:48:29 by acornia           #+#    #+#             */
/*   Updated: 2026/08/31 12:38:16 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
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
// 	int	power;

// 	if (argc == 3)
// 	{
// 		num = str_to_int(argv[1]);
// 		power = str_to_int(argv[2]);
// 		printf("We are going to raise the number %d by %d.\n", num, power);
// 		printf("The result is %d.\n", ft_recursive_power(num, power));
// 		return (0);
// 	}
// 	printf("You haven't entered enough values.");
// 	return (0);
// }
