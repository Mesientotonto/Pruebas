/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 13:05:20 by acornia           #+#    #+#             */
/*   Updated: 2026/09/30 13:14:07 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_str;
	unsigned char		*dest_str;

	if (!dest && !src)
		return (NULL);
	dest_str = (unsigned char *)dest;
	src_str = (const unsigned char *)src;
	if (dest_str > src_str)
	{
		while (n > 0)
		{
			n--;
			dest_str[n] = src_str[n];
		}
	}
	else
		ft_memcpy(dest_str, src_str, n);
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_str;
	unsigned char		*dest_str;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest_str = (unsigned char *)dest;
	src_str = (const unsigned char *)src;
	while (i < n)
	{
		dest_str[i] = src_str[i];
		i++;
	}
	return (dest);
}