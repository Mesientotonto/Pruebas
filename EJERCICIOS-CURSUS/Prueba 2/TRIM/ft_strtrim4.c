/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:01:15 by acornia           #+#    #+#             */
/*   Updated: 2026/10/07 12:28:43 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] != '\0' && ft_strchr(set, s[start]))
		start++;
	end = ft_strlen(s);
	while (end > start && ft_strchr(set, s[end - 1]))
		end--;
	return (ft_substr(s, start, end - start));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
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
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	str = malloc (sizeof(char) * (len + 1))
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

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	str_len;

	str_len = ft_strlen(s);
	str = malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	return (ft_memcpy(str, s, str_len + 1));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_str;
	unsigned char		*dst_str;
	size_t				i;

	i = 0;
	dst_str = (unsigned char *)dst;
	src_str = (const unsigned char *)src;
	while (i < n)
	{
		dst_str[i] = src_str[i];
		i++;
	}
	return (dst_str);
}