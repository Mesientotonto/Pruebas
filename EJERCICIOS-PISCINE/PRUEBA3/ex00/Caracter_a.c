/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Caracter_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:41:55 by acornia           #+#    #+#             */
/*   Updated: 2026/09/01 15:48:17 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	caracter_a(char  *str)
{
	write(1, "a\n", 2);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		caracter_a(argv[1]);
		return (0);
	}
}