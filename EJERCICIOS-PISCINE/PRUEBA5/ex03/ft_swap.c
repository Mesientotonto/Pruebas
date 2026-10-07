/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:32:38 by acornia           #+#    #+#             */
/*   Updated: 2026/09/03 16:37:32 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	swap;
	
	swap = *a;
	*a = *b;
	*b = swap;
}

int	main(void)
{
	int	n1;
	int	n2;

	n1 = 2;
	n2 = 5;
	ft_swap(&n1, &n2);
	printf("%d %d", n1, n2);
	return (0);
}