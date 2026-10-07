/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 12:23:03 by acornia           #+#    #+#             */
/*   Updated: 2026/08/31 13:16:43 by acornia          ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
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
// 		i ++;
// 	}
// 	return (res);
// }

// int	main(int argc, char **argv)
// {
// 	int	num;

// 	if (argc == 2)
// 	{
// 		num = str_to_int(argv[1]);
// 		printf("Let's go to the next prime number after: %d.\n", num);
// 		printf("That prime number is: %d.\n", ft_find_next_prime(num));
// 		return (0);
// 	}
// 	printf("You have not entered enough values.");
// 	return (0);
// }