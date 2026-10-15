/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 13:39:19 by acornia           #+#    #+#             */
/*   Updated: 2026/10/07 15:26:19 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

static size_t	count_words(const char *s, char c)
{
	size_t	counter;
	size_t	in_word;
	
	counter = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s != c && !in_word)
		{
			counter++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (counter);
}

static void	free_array(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**fill_array(char **array, const char *s, char c)
{
	size_t	length;
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c && *s)
		{
			length = 0;
			while (s[length] != c && s[length])
				length++;
			array[i] = ft_substr(s, 0, length);
			if (!array[i])
			{
				free_array(array, i);
				return (NULL);
			}
			i++;
			s += length;
		}
		else
			s++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	return (fill_array(array, s, c));
}

int	main(void)
{
	char	**str = ft_split("---Hola--q-u-e--tal----", '-');
	size_t	i = 0;

	while (str && str[i] != NULL)
	{
		printf("[%s]\n", str[i]);
		i++;
	}
	if (str)
		free_array(str, i);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	length;
	size_t	i;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (length < start)
		return (ft_strdup(""));
	if (len > length - start)
		len = length - start;
	str = malloc(sizeof(char) * (len + 1));
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
	size_t	length;
	char	*str;
	
	length = ft_strlen(s);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, length + 1);
	return (str);
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
