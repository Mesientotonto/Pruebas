/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:57:52 by acornia           #+#    #+#             */
/*   Updated: 2026/08/29 14:01:39 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_valid_number(char *str)
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

static int	print_key(char *key, t_dict *dict, int dict_size, int *first)
{
	char	*val;

	val = get_dict_value(key, dict, dict_size);
	if (!val)
		return (0);
	if (!(*first))
		ft_putchar(' ');
	ft_putstr(val);
	*first = 0;
	return (1);
}

static int	print_two_digits(char *str, t_dict *dict, int size, int *first)
{
	char	tmp[3];

	if (str[0] == '0' && str[1] == '0')
		return (1);
	if (str[0] == '0')
	{
		tmp[0] = str[1];
		tmp[1] = '\0';
		return (print_key(tmp, dict, size, first));
	}
	if (str[0] == '1' || str[1] == '0')
		return (print_key(str, dict, size, first));
	tmp[0] = str[0];
	tmp[1] = '0';
	tmp[2] = '\0';
	if (!print_key(tmp, dict, size, first))
		return (0);
	tmp[0] = str[1];
	tmp[1] = '\0';
	return (print_key(tmp, dict, size, first));
}

static int	print_group(char *str, t_dict *dict, int size, int *first)
{
	char	tmp[2];

	if (str[0] != '0')
	{
		tmp[0] = str[0];
		tmp[1] = '\0';
		if (!print_key(tmp, dict, size, first))
			return (0);
		if (!print_key("100", dict, size, first))
			return (0);
	}
	return (print_two_digits(str + 1, dict, size, first));
}

int	process_number(char *num_str, t_dict *dict, int dict_size)
{
	int		first;
	int		len;
	char	fmt[4];

	first = 1;
	if (ft_strcmp(num_str, "0") == 0)
		return (print_key("0", dict, dict_size, &first)
			&& (ft_putchar('\n'), 1));
	len = ft_strlen(num_str);
	fmt[0] = '0';
	fmt[1] = '0';
	fmt[2] = '0';
	fmt[3] = '\0';
	if (len >= 1)
		fmt[2] = num_str[len - 1];
	if (len >= 2)
		fmt[1] = num_str[len - 2];
	if (len >= 3)
		fmt[0] = num_str[len - 3];
	if (!print_group(fmt, dict, dict_size, &first))
		return (0);
	ft_putchar('\n');
	return (1);
}
