/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:48:39 by acornia           #+#    #+#             */
/*   Updated: 2026/09/29 16:18:29 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	
	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return(src_len);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] != '\0' && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

#include <stdio.h>

int main(void)
{
    char    dst[10] = "hola";
    
    printf("ft_strlen de dst: %zu\n", ft_strlen(dst)); // Debería dar 4
    printf("ft_strlen de src: %zu\n", ft_strlen("que")); // Debería dar 3
    
    size_t  result = ft_strlcat(dst, "que", 7);
    printf("Resultado final: %zu\n", result);
    return (0);
}