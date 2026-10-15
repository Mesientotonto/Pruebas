/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 13:06:27 by acornia           #+#    #+#             */
/*   Updated: 2026/09/28 13:11:31 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ori;
	unsigned char	*des;
	size_t			i;

	i = 0;
	ori = (unsigned char *)src;
	des = (unsigned char *)dest;
	while (i < n)
	{
		des[i] = ori[i];
		i++;
	}
	return (des);
}