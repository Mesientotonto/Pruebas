/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:40:08 by acornia           #+#    #+#             */
/*   Updated: 2026/09/29 16:00:43 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static int	count_words(const char *s, char c)
{
	bool	is_a_word;
	int		number_of_words;
	
	number_of_words = 0;
	is_a_word = false;
	while (*s != '\0')
	{
		if (*s != c && !is_a_word)
		{
			number_of_words++;
			is_a_word = true;
		}
		else if (*s == c)
			is_a_word = false;
		s++;
	}
	return (number_of_words);
}

static void	free_array(char **tab, int index)
{
	while (index > 0)
	{
		index--;
		free(tab[index]);
	}
	free(tab);
}

static char	**fill_array(char **res_str, const char *s, char c)
{
	size_t	lenght;
	int	i;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			lenght = 0;
			while (s[lenght] && s[lenght] != c)
				lenght++;
			res_str[i] = ft_substr(s, 0, lenght);
			if (!res_str[i])
			{
				free_array(res_str, i);
				return (NULL);
			}
			i++;
			s += lenght;
		}
		else
			s++;
	}
	res_str[i] = NULL;
	return (res_str);
}

char	**ft_split(const char *s, char c)
{
	char	**res_str;

	if (!s)
		return (NULL);
	res_str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res_str)
		return (NULL);
	return (fill_array(res_str, s, c));
}

#include <stdio.h>

int	main(void)
{
	
	char **result_split  = ft_split("holaquetal", 'a');

	while (*result_split != NULL)
	{
		printf("result strings split:[%s]\n", *result_split);
		*result_split++;
	}
	return (0);
}
