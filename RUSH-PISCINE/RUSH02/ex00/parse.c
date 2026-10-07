/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:21:06 by acornia           #+#    #+#             */
/*   Updated: 2026/08/29 13:24:07 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	get_file_size(char *file_path)
{
	int		fd;
	int		bytes_read;
	int		total_size;
	char	buffer[4096];

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	total_size = 0;
	bytes_read = read(fd, buffer, 4096);
	while (bytes_read > 0)
	{
		total_size += bytes_read;
		bytes_read = read(fd, buffer, 4096);
	}
	close(fd);
	if (bytes_read < 0)
		return (-1);
	return (total_size);
}

static char	*read_file_to_buffer(char *file_path, int *size)
{
	int		fd;
	char	*buffer;
	int		bytes_read;

	*size = get_file_size(file_path);
	if (*size <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (*size + 1));
	if (!buffer)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		return (NULL);
	}
	bytes_read = read(fd, buffer, *size);
	close(fd);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

void	free_dict(t_dict *dict, int size)
{
	int	i;

	if (!dict)
		return ;
	i = 0;
	while (i < size)
	{
		if (dict[i].key)
			free(dict[i].key);
		if (dict[i].value)
			free(dict[i].value);
		i++;
	}
	free(dict);
}

char	*get_dict_value(char *key, t_dict *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (dict[i].key && ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}

t_dict	*read_dict(char *file_path, int *size)
{
	char	*buffer;
	t_dict	*dict;
	int		entries;

	buffer = read_file_to_buffer(file_path, size);
	if (!buffer)
		return (NULL);
	entries = count_entries(buffer);
	if (entries == 0)
	{
		free(buffer);
		return (NULL);
	}
	dict = (t_dict *)malloc(sizeof(t_dict) * entries);
	if (!dict)
	{
		free(buffer);
		return (NULL);
	}
	*size = fill_dict(dict, buffer);
	free(buffer);
	return (dict);
}
