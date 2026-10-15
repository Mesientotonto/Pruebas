/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:48:26 by acornia           #+#    #+#             */
/*   Updated: 2026/09/28 10:38:18 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función ft_memcpy (de memory copy) copia un número determinado de 
bytes ($n$) desde una zona de memoria de origen (src) hacia una zona de 
memoria de destino (dst).*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		*des;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	des = (unsigned char *)dest;
	ptr = (const unsigned char *)src;
	while (i < n)
	{
		des[i] = ptr[i];
		i++;
	}
	return (des);
}
