/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:57:36 by acornia           #+#    #+#             */
/*   Updated: 2026/09/30 10:34:17 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

static int	count_words(const char *s, char c)
{
	int	is_in_word;
	int	count;

	count = 0;
	is_in_word = 0;
	while (*s)
	{
		if (*s != c && !is_in_word)
		{
			count++;
			is_in_word = 1;
		}
		else if (*s == c)
			is_in_word = 0;
		s++;
	}
	return (count);
}

static void	free_array(char **array, int index)
{
	while (index > 0)
	{
		index--;
		free (array[index]);
	}
	free(array);
}

static char	**fill_tab(char **array, const char *s, char c)
{
	int	len;
	int	i;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			array[i] = ft_substr(s, 0, len);
			if (!array[i])
			{
				free_array(array, i);
				return (NULL);
			}
			i++;
			s += len;
		}
		else
			s++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	return (fill_tab(res, s, c));
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
	str = (char *)malloc(sizeof(char) * (length + 1));
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
	char	*str_res;
	size_t	len;

	len = ft_strlen(s);
	str_res = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_res)
		return (NULL);
	ft_memcpy(str_res, s, len + 1);
	return (str_res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destiny;
	size_t				index;

	index = 0;
	destiny = (unsigned char *)dest;
	source = (const unsigned char *)src;
	while (index < n)
	{
		destiny[index] = source[index];
		index++;
	}
	return (destiny);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

#include <stdio.h>

int	main()
{
	char **ori = ft_split("Hola que tal", ' ');
	int	i = 0;
	
	while (ori[i] != NULL)
	{
		printf("%s\n", ori[i]);
		i++;
	}
	return (0);
}