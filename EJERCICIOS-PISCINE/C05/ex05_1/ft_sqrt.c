/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 10:31:18 by acornia           #+#    #+#             */
/*   Updated: 2026/08/31 12:41:52 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 0;
	while (i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

// int	str_to_int(char *str)
// {
// 	int	i;
// 	int	res;

// 	i = 0;
// 	res = 0;
// 	if (str[i] >= '0' && str[i] <= '9')
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
// 		printf("Let's do the root of: %d.\n", num);
// 		printf("The result is: %d.\n", ft_sqrt(num));
// 		return (0);
// 	}
// 	printf("You have not entered enough values\n");
// 	return (0);
// }
