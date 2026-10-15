/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 10:57:26 by acornia           #+#    #+#             */
/*   Updated: 2026/09/30 11:24:45 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s,unsigned int start, size_t len)
{
	size_t	length;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (length < start)
		return (ft_strdup(""));
	if (len > length - start)
		len = length - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len + 1);
	return (dup);
}

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char	*destiny;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	destiny = (unsigned char *)dest;
	source = (const unsigned char *)src;
	while (i < n)
	{
		destiny[i] = source[i];
		i++;
	}
	return (destiny);
}