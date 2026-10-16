/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 09:42:36 by acornia           #+#    #+#             */
/*   Updated: 2026/10/16 11:52:26 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = 0;
}

static void	ft_set_flag(char c, t_flags *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '#')
		flags->hash = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '+')
		flags->plus = 1;
}

static int	ft_parse_num(const char *str, int *out)
{
	int	i;

	i = 0;
	*out = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*out = *out * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}

int	ft_parse(const char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (ft_is_in(str[i], "-0# +"))
	{
		ft_set_flag(str[i], flags);
		i++;
	}
	i += ft_parse_num(str + i, &flags->width);
	if (str[i] == '.')
	{
		flags->dot = 1;
		i++;
		i += ft_parse_num(str + i, &flags->precision);
	}
	return (i);
}
