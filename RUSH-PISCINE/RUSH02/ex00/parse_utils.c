/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:23:37 by acornia           #+#    #+#             */
/*   Updated: 2026/08/29 13:34:48 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	count_entries(char *buf)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == ':')
			count++;
		i++;
	}
	return (count);
}

static char	*extract_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	while (str[start] == ' ' || str[start] == '\t')
		start++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'
			|| str[end - 1] == '\n'))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	process_entry(t_dict *dict, char *buf, int *i, int *k)
{
	int	colon;

	colon = *i;
	while (*i > 0 && buf[*i - 1] != '\n')
		(*i)--;
	dict[*k].key = extract_word(buf, *i, colon);
	*i = colon + 1;
	while (buf[*i] && buf[*i] != '\n')
		(*i)++;
	dict[*k].value = extract_word(buf, colon + 1, *i);
	(*k)++;
}

int	fill_dict(t_dict *dict, char *buf)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (buf[i])
	{
		if (buf[i] == ':')
			process_entry(dict, buf, &i, &k);
		else
			i++;
	}
	return (k);
}
