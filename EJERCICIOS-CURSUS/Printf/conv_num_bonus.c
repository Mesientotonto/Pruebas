/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42madrid.com>       +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:30:00 by login           #+#    #+#             */
/*   Updated: 2026/10/15 13:30:00 by login          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_set_sign(t_flags *f, t_num *num, long n)
{
	if (n < 0)
	{
		num->value = -n;
		num->prefix[0] = '-';
	}
	else
	{
		num->value = n;
		if (f->plus)
			num->prefix[0] = '+';
		else if (f->space)
			num->prefix[0] = ' ';
	}
}

int	ft_conv_int(t_flags *f, va_list *ap)
{
	t_num	num;

	ft_num_init(&num, 10, 0);
	ft_set_sign(f, &num, va_arg(*ap, int));
	return (ft_print_num(f, &num));
}

int	ft_conv_unsigned(t_flags *f, va_list *ap, int base, int upper)
{
	t_num	num;

	ft_num_init(&num, base, upper);
	num.value = va_arg(*ap, unsigned int);
	if (f->hash && base == 16 && num.value != 0)
	{
		num.prefix[0] = '0';
		num.prefix[1] = 'x';
		if (upper)
			num.prefix[1] = 'X';
	}
	return (ft_print_num(f, &num));
}

int	ft_conv_ptr(t_flags *f, va_list *ap)
{
	void	*ptr;
	t_num	num;

	ptr = va_arg(*ap, void *);
	if (ptr == NULL)
		return (ft_print_padded(f, "(nil)", 5));
	ft_num_init(&num, 16, 0);
	num.value = (unsigned long)ptr;
	num.prefix[0] = '0';
	num.prefix[1] = 'x';
	return (ft_print_num(f, &num));
}
