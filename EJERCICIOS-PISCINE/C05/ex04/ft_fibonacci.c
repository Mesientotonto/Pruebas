/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:25:34 by acornia           #+#    #+#             */
/*   Updated: 2026/08/31 12:38:59 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index -1) + ft_fibonacci(index - 2));
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
// 	int	index;

// 	if (argc == 2)
// 	{
// 		index = str_to_int(argv[1]);
// 		printf("Let's do fibonacci with index %d.\n", index);
// 		printf("The result is: %d.\n", ft_fibonacci(index));
// 		return (0);
// 	}
// 	printf("You haven't entered enough values.");
// 	return (0);
// }
