/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cambia_caja.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 13:20:58 by acornia           #+#    #+#             */
/*   Updated: 2026/09/01 13:41:18 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *cambia_caja(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	main(void)
{
	char texto[] = "Hola buenas";
	
	printf("%s.\n", cambia_caja(texto));
	return (0);
}