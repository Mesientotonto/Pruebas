/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:15:04 by acornia           #+#    #+#             */
/*   Updated: 2026/10/16 11:57:06 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_format(char c, t_flags *flags, va_list *args)
{
	if (c == 'c')
		return (ft_conv_char(flags, args));
	if (c == 's')
		return (ft_conv_str(flags, args));
	if (c == 'p')
		return (ft_conv_ptr(flags, args));
	if (c == 'd' || c == 'i')
		return (ft_conv_int(flags, args));
	if (c == 'u')
		return (ft_conv_unsigned(flags, args, 10, 0));
	if (c == 'x')
		return (ft_conv_unsigned(flags, args, 16, 0));
	if (c == 'X')
		return (ft_conv_unsigned(flags, args, 16, 1));
	if (c == '%')
		return (ft_putchar('%', 1));
	return (0);
}

static int	ft_loop(const char *str, va_list *args)
{
	t_flags	flags;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			count += write(1, &str[i], 1);
		else
		{
			ft_init_flags(&flags);
			i += ft_parse(&str[i + 1], &flags) + 1;
			count += ft_format(str[i], &flags, args);
		}
		if (str[i] != '\0')
			i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = ft_loop(str, &args);
	va_end(args);
	return (count);
}
