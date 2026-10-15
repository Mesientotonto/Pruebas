/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 13:13:53 by acornia           #+#    #+#             */
/*   Updated: 2026/09/28 13:21:02 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ori;
	unsigned char	*des;

	if (!src && !dest)
		return (NULL);
	ori = (unsigned char *)src;
	des = (unsigned char *)dest;
	if (ori > des)
	{
		while (n > 0)
		{
			n--;
			des[n] = ori[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}