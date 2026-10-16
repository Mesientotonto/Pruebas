/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 09:56:33 by acornia           #+#    #+#             */
/*   Updated: 2026/10/16 11:56:39 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_padded(t_flags *flags, char const *str, int len)
{
	int	count;

	count = 0;
	if (!flags->minus)
		count += ft_putchar(' ', flags->width - len);
	count += ft_putstr(str, len);
	if (flags -> minus)
		count += ft_putchar(' ', flags->width - len);
	return (count);
}

int	ft_conv_char(t_flags *flags, va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	return (ft_print_padded(flags, &c, 1));
}

int	ft_conv_str(t_flags *flags, va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (str == NULL && (!flags->dot || flags->precision >= 6))
		str = "(null)";
	else if (str == NULL)
		str = "";
	len = ft_strlen(str);
	if (flags->dot && flags->precision < len)
		len = flags->precision;
	return (ft_print_padded(flags, str, len));
}
