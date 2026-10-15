/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:07:44 by acornia           #+#    #+#             */
/*   Updated: 2026/08/31 12:40:00 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_sqrt(int nb, int i);

int	ft_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	return (ft_recursive_sqrt(nb, 1));
}

int	ft_recursive_sqrt(int nb, int i)
{
	if (i * i == nb)
		return (i);
	if (i * i > nb)
		return (0);
	return (ft_recursive_sqrt(nb, i + 1));
}

// int	str_to_int(char *str)
// {
// 	int	i;
// 	int	res;
// 	int	sign;

// 	i = 0;
// 	res = 0;
// 	sign = 1;
// 	if (str[i] == '+' || str[i] == '-')
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
// 	int	nb;

// 	if (argc == 2)
// 	{
// 		nb = str_to_int(argv[1]);
// 		printf("Let's do the root of %d.\n", nb);
// 		printf("The result is: %d.\n", ft_sqrt(nb));
// 		return (0);
// 	}
// 	printf("You haven't entered enough values.");
// 	return (0);
// }
