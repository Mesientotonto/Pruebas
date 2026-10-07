/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writestring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 10:30:25 by acornia           #+#    #+#             */
/*   Updated: 2026/08/22 10:32:31 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_string(char *str)
{
	if (!str)
	{
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(void)
{
	write_string("Hola, mundo");
	return (0);

}
