/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42madrid.com>       +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:30:00 by login           #+#    #+#             */
/*   Updated: 2026/10/15 13:30:00 by login          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init_flags(t_flags *f)
{
	f->minus = 0;
	f->zero = 0;
	f->dot = 0;
	f->hash = 0;
	f->space = 0;
	f->plus = 0;
	f->width = 0;
	f->precision = 0;
}

static void	ft_set_flag(char c, t_flags *f)
{
	if (c == '-')
		f->minus = 1;
	else if (c == '0')
		f->zero = 1;
	else if (c == '#')
		f->hash = 1;
	else if (c == ' ')
		f->space = 1;
	else if (c == '+')
		f->plus = 1;
}

static int	ft_parse_num(const char *s, int *out)
{
	int	i;

	i = 0;
	*out = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		*out = *out * 10 + (s[i] - '0');
		i++;
	}
	return (i);
}

int	ft_parse(const char *fmt, t_flags *f)
{
	int	i;

	i = 0;
	while (ft_is_in(fmt[i], "-0# +"))
	{
		ft_set_flag(fmt[i], f);
		i++;
	}
	i += ft_parse_num(fmt + i, &f->width);
	if (fmt[i] == '.')
	{
		f->dot = 1;
		i++;
		i += ft_parse_num(fmt + i, &f->precision);
	}
	return (i);
}
