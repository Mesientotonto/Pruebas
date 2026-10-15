/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:07:07 by acornia           #+#    #+#             */
/*   Updated: 2026/08/29 16:07:09 by acornia          ###   ########.fr       */
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
		write(1, &str[i++], 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
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
				write(1, &dict[i++], 1);
			*first = 0;
			return ;
		}
		while (dict[i] && dict[i] != '\n')
			i++;
		if (dict[i] == '\n')
			i++;
	}
}

void	print_trio(char *dict, char *num, int len, int *first)
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

void	print_magnitude(char *dict, int zeros, int *first)
{
	char	power[64];
	int		i;

	if (zeros <= 0)
		return ;
	power[0] = '1';
	i = 1;
	while (i <= zeros)
		power[i++] = '0';
	power[i] = '\0';
	print_key(dict, power, first);
}

void	parse_any_number(char *dict, char *num)
{
	int		len;
	int		group_len;
	int		first;
	char	trio[4];
	int		i;

	len = ft_strlen(num);
	first = 1;
	if (len == 1 && num[0] == '0')
	{
		print_key(dict, "0", &first);
		ft_putstr("\n");
		return ;
	}
	while (len > 0)
	{
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
		if (!(trio[0] == '0' && (group_len < 2 || trio[1] == '0') && (group_len < 3 || trio[2] == '0')))
		{
			print_trio(dict, trio, group_len, &first);
			print_magnitude(dict, len - group_len, &first);
		}
		num += group_len;
		len -= group_len;
	}
	ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	int		fd;
	int		bytes;
	char	buf[16384];

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	bytes = read(fd, buf, 16383);
	if (bytes <= 0)
	{
		close(fd);
		ft_putstr("Dict Error\n");
		return (0);
	}
	buf[bytes] = '\0';
	close(fd);
	parse_any_number(buf, argv[1]);
	return (0);
}
