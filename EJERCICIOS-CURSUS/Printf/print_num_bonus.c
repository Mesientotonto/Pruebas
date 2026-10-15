/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42madrid.com>       +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:30:00 by login           #+#    #+#             */
/*   Updated: 2026/10/15 13:30:00 by login          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_num_init(t_num *num, int base, int upper)
{
	num->value = 0;
	num->base = base;
	num->upper = upper;
	num->digits = 0;
	num->zeros = 0;
	num->spaces = 0;
	num->prefix[0] = '\0';
	num->prefix[1] = '\0';
	num->prefix[2] = '\0';
}

static int	ft_numlen(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

static int	ft_put_digits(unsigned long n, int base, int upper)
{
	char	*digits;
	int		count;

	digits = "0123456789abcdef";
	if (upper)
		digits = "0123456789ABCDEF";
	count = 0;
	if (n >= (unsigned long)base)
		count += ft_put_digits(n / base, base, upper);
	count += write(1, &digits[n % base], 1);
	return (count);
}

static void	ft_num_prepare(t_flags *f, t_num *num)
{
	int	plen;

	plen = ft_strlen(num->prefix);
	num->digits = ft_numlen(num->value, num->base);
	if (f->dot && f->precision == 0 && num->value == 0)
		num->digits = 0;
	num->zeros = ft_max(f->precision - num->digits, 0);
	if (f->zero && !f->minus && !f->dot)
		num->zeros = ft_max(f->width - plen - num->digits, 0);
	num->spaces = ft_max(f->width - plen - num->zeros - num->digits, 0);
}

int	ft_print_num(t_flags *f, t_num *num)
{
	int	count;

	ft_num_prepare(f, num);
	count = 0;
	if (!f->minus)
		count += ft_putchars(' ', num->spaces);
	count += ft_putstrn(num->prefix, ft_strlen(num->prefix));
	count += ft_putchars('0', num->zeros);
	if (num->digits > 0)
		count += ft_put_digits(num->value, num->base, num->upper);
	if (f->minus)
		count += ft_putchars(' ', num->spaces);
	return (count);
}
