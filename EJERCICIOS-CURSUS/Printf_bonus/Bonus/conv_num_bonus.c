/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:48:16 by acornia           #+#    #+#             */
/*   Updated: 2026/10/16 11:57:46 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_set_sign(t_flags *flags, t_num *num, long n)
{
	if (n < 0)
	{
		num->value = -n;
		num->prefix[0] = '-';
	}
	else
	{
		num->value = n;
		if (flags->plus)
			num->prefix[0] = '+';
		else if (flags->space)
			num->prefix[0] = ' ';
	}
}

int	ft_conv_int(t_flags *flags, va_list *args)
{
	t_num	num;

	ft_num_init(&num, 10, 0);
	ft_set_sign(flags, &num, va_arg(*args, int));
	return (ft_print_num(flags, &num));
}

int	ft_conv_unsigned(t_flags *flags, va_list *args, int base, int upper)
{
	t_num	num;

	ft_num_init(&num, base, upper);
	num.value = va_arg(*args, unsigned int);
	if (flags->hash && base == 16 && num.value != 0)
	{
		num.prefix[0] = '0';
		num.prefix[1] = 'x';
		if (upper)
			num.prefix[1] = 'X';
	}
	return (ft_print_num(flags, &num));
}

int	ft_conv_ptr(t_flags *flags, va_list *args)
{
	void	*ptr;
	t_num	num;

	ptr = va_arg(*args, void *);
	if (ptr == NULL)
		return (ft_print_padded(flags, "(nil)", 5));
	ft_num_init(&num, 16, 0);
	num.value = (unsigned long)ptr;
	num.prefix[0] = '0';
	num.prefix[1] = 'x';
	return (ft_print_num(flags, &num));
}
