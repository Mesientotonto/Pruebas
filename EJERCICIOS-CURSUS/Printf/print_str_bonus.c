/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42madrid.com>       +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:30:00 by login           #+#    #+#             */
/*   Updated: 2026/10/15 13:30:00 by login          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_padded(t_flags *f, const char *s, int len)
{
	int	count;

	count = 0;
	if (!f->minus)
		count += ft_putchars(' ', f->width - len);
	count += ft_putstrn(s, len);
	if (f->minus)
		count += ft_putchars(' ', f->width - len);
	return (count);
}

int	ft_conv_char(t_flags *f, va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	return (ft_print_padded(f, &c, 1));
}

int	ft_conv_str(t_flags *f, va_list *ap)
{
	char	*s;
	int		len;

	s = va_arg(*ap, char *);
	if (s == NULL && (!f->dot || f->precision >= 6))
		s = "(null)";
	else if (s == NULL)
		s = "";
	len = ft_strlen(s);
	if (f->dot && f->precision < len)
		len = f->precision;
	return (ft_print_padded(f, s, len));
}
