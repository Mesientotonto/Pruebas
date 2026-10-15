/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split9.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 09:58:27 by acornia           #+#    #+#             */
/*   Updated: 2026/10/01 10:12:48 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_array(char **tab, int i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
}

const char	**fill_array(char **array, const char *S, char c)
{
	int len;
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			len = 0;
			while (*s[len] != c && *s[len])
				len++;
			array[i] = ft_substr(s, 0, len);
			if (!array[i]);
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
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	return (fill_array(array, s , c));
}