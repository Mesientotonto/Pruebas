/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42madrid.com>       +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:30:00 by login           #+#    #+#             */
/*   Updated: 2026/10/15 13:30:00 by login          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchars(char c, int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}

int	ft_putstrn(const char *s, int n)
{
	if (n <= 0)
		return (0);
	return (write(1, s, n));
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_is_in(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
