/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:50:07 by acornia           #+#    #+#             */
/*   Updated: 2026/10/16 11:57:52 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}	t_flags;

typedef struct s_num
{
	unsigned long	value;
	int				base;
	int				upper;
	int				digits;
	int				zeros;
	int				spaces;
	char			prefix[3];
}	t_num;

int		ft_printf(const char *fmt, ...);
int		ft_putchar(char c, int n);
int		ft_putstr(const char *s, int n);
int		ft_strlen(const char *s);
int		ft_max(int a, int b);
int		ft_is_in(char c, const char *set);
void	ft_init_flags(t_flags *f);
int		ft_parse(const char *fmt, t_flags *f);
int		ft_print_padded(t_flags *f, const char *s, int len);
int		ft_conv_char(t_flags *f, va_list *ap);
int		ft_conv_str(t_flags *f, va_list *ap);
int		ft_conv_ptr(t_flags *f, va_list *ap);
int		ft_conv_int(t_flags *f, va_list *ap);
int		ft_conv_unsigned(t_flags *f, va_list *ap, int base, int upper);
void	ft_num_init(t_num *num, int base, int upper);
int		ft_print_num(t_flags *f, t_num *num);

#endif
