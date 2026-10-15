/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits_rev.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:02:40 by acornia           #+#    #+#             */
/*   Updated: 2026/09/01 11:08:49 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_digits(void)
{
	char	c;
	
	c = '9';
	while (c >= '0' && c <= '9')
	{
		write (1, &c, 1);
		c--;
	}
}

int	main(void)
{
	ft_print_digits();
	return (0);
}