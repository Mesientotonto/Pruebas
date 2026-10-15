/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:33:53 by acornia           #+#    #+#             */
/*   Updated: 2026/10/07 11:52:13 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL;)
	start = 0;
	while (s[start] != '\0' && ft_strchr(set, s[start]))
		start++;
	end = ft_strlen(s);
	while (end > start && ft_strchr(set, s[end - 1]))
		end--;
	return (ft_substr());
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len < start)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	leng;
	size_t	i;

	leng = ft_strlen(s);
	str = malloc(sizeof(char) * (leng + 1));
	if (!str)
		return (str);
	ft_memcpy(str, s, leng + 1);
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_str;
	unsigned char		*dst_str;
	size_t				i;

	i = 0;
	dst_str = (unsigned char *)dest;
	src_str = (const unsigned char *)src;
	while (i < n)
	{
		dst_str[i] = src_str[i];
		i++;
	}
	return (dst_str);
}