/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:12:18 by acornia           #+#    #+#             */
/*   Updated: 2026/08/29 13:29:18 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

/* utils.c */
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);

/* parse.c */
t_dict	*read_dict(char *file_path, int *size);
char	*get_dict_value(char *key, t_dict *dict, int size);
void	free_dict(t_dict *dict, int size);

/* parse_utils.c */
int		count_entries(char *buf);
int		fill_dict(t_dict *dict, char *buf);

/* convert.c */
int		is_valid_number(char *str);
int		process_number(char *num_str, t_dict *dict, int dict_size);

#endif
