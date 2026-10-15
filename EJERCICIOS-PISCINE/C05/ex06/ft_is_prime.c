/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 11:37:41 by acornia           #+#    #+#             */
/*   Updated: 2026/08/31 12:55:49 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// int	str_to_int(char *str)
// {
// 	int	i;
// 	int	res;

// 	i = 0;
// 	res = 0;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (res);
// }

// int	main(int argc, char **argv)
// {
// 	int	num;

// 	if (argc == 2)
// 	{
// 		num = str_to_int(argv[1]);
// 		printf("Let's see if %d is prime.\n", num);
// 		printf("If it is prime it will put 1 and if not 0, the result is: ");
// 		printf("%d.\n", ft_is_prime(num));
// 		return (0);
// 	}
// 	printf("You have not entered enough values.");
// 	return (0);
// }
