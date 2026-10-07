/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:12:27 by acornia           #+#    #+#             */
/*   Updated: 2026/08/25 15:32:32 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int nb)
{
	 if (nb <= 2147483647 && nb >= -2147483648)
	 {
		 if (nb == -2147483648)
		 {
			 ft_putchar('-');
			 ft_putchar('2');
			 ft_putnbr(147483648);
		 }
		 else if (nb < 0)
		 {
			 ft_putchar('-');
			 nb = -nb;
		 }
		 else if (nb > 9)
		 {
			 ft_putnbr(nb / 10);
			 ft_putnbr(nb % 10);
		 }
		 else
		 {
			 ft_putchar(nb + '0');
		 }
	 }
}

int	main(void)
{
	ft_putnbr(3577);
	return (0);
}
