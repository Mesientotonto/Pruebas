/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 12:18:18 by acornia           #+#    #+#             */
/*   Updated: 2026/08/29 13:34:11 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	run_program(char *dict_path, char *nbr_str)
{
	t_dict	*dict;
	int		dict_size;

	if (!is_valid_number(nbr_str))
	{
		ft_putstr("Error\n");
		return (1);
	}
	dict_size = 0;
	dict = read_dict(dict_path, &dict_size);
	if (!dict)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	if (!process_number(nbr_str, dict, dict_size))
	{
		ft_putstr("Dict Error\n");
		free_dict(dict, dict_size);
		return (1);
	}
	free_dict(dict, dict_size);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (run_program("numbers.dict", argv[1]) != 0)
			return (1);
	}
	else if (argc == 3)
	{
		if (run_program(argv[1], argv[2]) != 0)
			return (1);
	}
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
