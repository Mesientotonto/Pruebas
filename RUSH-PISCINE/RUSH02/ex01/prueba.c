/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 15:41:36 by acornia           #+#    #+#             */
/*   Updated: 2026/08/29 15:41:51 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	print_key(char *dict, char *key, int *first)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i])
	{
		j = 0;
		while (key[j] && dict[i + j] == key[j])
			j++;
		if (key[j] == '\0' && (dict[i + j] == ':' || dict[i + j] == ' '))
		{
			i += j;
			while (dict[i] == ' ' || dict[i] == ':')
				i++;
			if (!(*first))
				ft_putstr(" ");
			while (dict[i] && dict[i] != '\n')
			{
				write(1, &dict[i], 1);
				i++;
			}
			*first = 0;
			return ;
		}
		while (dict[i] && dict[i] != '\n')
			i++;
		if (dict[i] == '\n')
			i++;
	}
}

void	print_thousands_power(char *dict, int zeros, int *first)
{
	char	power[32];
	int		i;

	if (zeros <= 0)
		return ;
	power[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		power[i] = '0';
		i++;
	}
	power[i] = '\0';
	print_key(dict, power, first);
}

void	process_trio(char *dict, char *num, int len, int *first)
{
	char	key[3];

	if (len == 3 && num[0] != '0')
	{
		key[0] = num[0];
		key[1] = '\0';
		print_key(dict, key, first);
		print_key(dict, "100", first);
		num++;
		len--;
	}
	if (len == 2)
	{
		if (num[0] == '1' || num[1] == '0')
		{
			if (num[0] != '0')
				print_key(dict, num, first);
			return ;
		}
		else if (num[0] != '0')
		{
			key[0] = num[0];
			key[1] = '0';
			key[2] = '\0';
			print_key(dict, key, first);
		}
		num++;
		len--;
	}
	if (len == 1 && num[0] != '0')
	{
		key[0] = num[0];
		key[1] = '\0';
		print_key(dict, key, first);
	}
}

void	process_recursive(char *dict, char *num, int len, int *first)
{
	int		group_len;
	char	trio[4];
	int		i;

	if (len == 0)
		return ;
	group_len = len % 3;
	if (group_len == 0)
		group_len = 3;
	i = 0;
	while (i < group_len)
	{
		trio[i] = num[i];
		i++;
	}
	trio[i] = '\0';
	if (!(trio[0] == '0' && trio[1] == '0' && trio[2] == '0'))
	{
		process_trio(dict, trio, group_len, first);
		print_thousands_power(dict, len - group_len, first);
	}
	process_recursive(dict, num + group_len, len - group_len, first);
}

void	process_number(char *dict, char *num)
{
	int	len;
	int	first;

	first = 1;
	len = ft_strlen(num);
	if (len == 1 && num[0] == '0')
		print_key(dict, "0", &first);
	else
		process_recursive(dict, num, len, &first);
	ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	int		fd;
	int		bytes;
	char	*buffer;

	if (argc != 2 || !is_valid(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	buffer = (char *)malloc(sizeof(char) * 8192);
	if (!buffer)
		return (0);
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		ft_putstr("Dict Error\n");
		return (0);
	}
	bytes = read(fd, buffer, 8191);
	if (bytes <= 0)
	{
		close(fd);
		free(buffer);
		ft_putstr("Dict Error\n");
		return (0);
	}
	buffer[bytes] = '\0';
	close(fd);
	process_number(buffer, argv[1]);
	free(buffer);
	return (0);
}
