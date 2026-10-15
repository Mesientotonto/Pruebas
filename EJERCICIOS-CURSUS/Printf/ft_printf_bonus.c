/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42madrid.com>       +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:30:00 by login           #+#    #+#             */
/*   Updated: 2026/10/15 13:30:00 by login          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_dispatch(char c, t_flags *f, va_list *ap)
{
	if (c == 'c')
		return (ft_conv_char(f, ap));
	if (c == 's')
		return (ft_conv_str(f, ap));
	if (c == 'p')
		return (ft_conv_ptr(f, ap));
	if (c == 'd' || c == 'i')
		return (ft_conv_int(f, ap));
	if (c == 'u')
		return (ft_conv_unsigned(f, ap, 10, 0));
	if (c == 'x')
		return (ft_conv_unsigned(f, ap, 16, 0));
	if (c == 'X')
		return (ft_conv_unsigned(f, ap, 16, 1));
	if (c == '%')
		return (ft_putchars('%', 1));
	return (0);
}

static int	ft_loop(const char *fmt, va_list *ap)
{
	t_flags	flags;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
			count += write(1, &fmt[i], 1);
		else
		{
			ft_init_flags(&flags);
			i += ft_parse(&fmt[i + 1], &flags) + 1;
			count += ft_dispatch(fmt[i], &flags, ap);
		}
		if (fmt[i])
			i++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, fmt);
	count = ft_loop(fmt, &ap);
	va_end(ap);
	return (count);
}
