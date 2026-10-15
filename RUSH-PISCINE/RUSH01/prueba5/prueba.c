/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 11:43:35 by acornia           #+#    #+#             */
/*   Updated: 2026/08/23 13:02:43 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_grid(int grid[4][4])                                             //Funcion que imprime la solucion
{
	int	row;
	int	col;
	char	ch;

	row = 0;
	while (row < 4)                                                        //Recorre cada linea
	{
		col = 0;
		while (col < 4)                                                //Recorre cada columna
		{
			ch = grid[row][col] + '0';                             //Convertimos el numero en caracter
			write(1, &ch, 1);                                      //Escribe el caracter
			if (col < 3)                                           //Si no estamos en la ultima columna
				write(1, " ", 1);                              //Escribe un espacio
			col++;
		}
		write(1, "\n", 1);                                             //Si termina de recorrer las columnas va a la siguiente linea
		row++;
	}
}

int	parse_input(char *str, int views[16])                                  //Lee los caracteres y se asegura de que sean validos
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])                                                         //Recorre los caracteres del str dado
	{
		if (i % 2 == 0)                                                //Deben estar en los indices pares
		{
			if (str[i] < '1' || str[i] > '4' || j >= 16)           //Comprueba si no es menor que 1 y menor que 4
				return (0);                                    //Tambien que no hayamos puesto mas de 16
			views[j] = str[i] - '0';
			j++;
		}
		else if (str[i] != ' ')                                        //Si esta en los indices impares
			return (0);
		i++;
	}
	return (j == 16 && str[i - 1] != ' ');                                 //El parseo es exitoso si el ultimo no es un espacio
}

int	check_line(int grid[4][4], int pos, int step, int expected)            //Comprueba una linea en cualquier direccion
{
	int	i;
	int	max;
	int	visible;
	int	val;

	i = 0;
	max = 0;
	visible = 0;
	while (i < 4)
	{
		val = grid[(pos + i * step) / 4][(pos + i * step) % 4];        //Leemos 4 casillas consecutivas calculando la fila
		if (val > max)                                                 //y la columna. Si el tamaño de la caja actual val
		{                                                              //es mayor que la caja mas alta vista hasta ahora
			max = val;                                             //incrementamos visible y actualizamos el record max.
			visible++;                                             //Al final, devuelve si las cajas visibles coinciden.
		}
		i++;
	}
	return (visible == expected);
}

int	check_all_views(int grid[4][4], int v[16])                             //Recorre los 4 lados usando una funcion generica
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_line(grid, i, 4, v[i])                              //Puntos de vista superiores
			|| !check_line(grid, 12 + i, -4, v[i + 4])             //Puntos de vista inferiores
			|| !check_line(grid, i * 4, 1, v[i + 8])               //Puntos de vista izquierdos
			|| !check_line(grid, i * 4 + 3, -1, v[i + 12]))        //Puntos de vista derechos
			return (0);
		i++;
	}
	return (1);
}

int	solve(int grid[4][4], int views[16], int pos)                          //Backtracking
{
	int	row;
	int	col;
	int	num;
	int	i;

	if (pos == 16)                                                         //Significa que ya hemos rellenado todo
		return (check_all_views(grid, views));
	row = pos / 4;                                                         //Coordenadas y pruebas de numeros
	col = pos % 4;
	num = 0;
	while (++num <= 4)
	{
		i = -1;
		while (++i < 4)
			if (grid[row][i] == num || grid[i][col] == num)        //Validacion de repeticion
				break ;
		if (i == 4)
		{                                                              //Si i == 4 significa que no encontro duplicados y la
			grid[row][col] = num;                                  //posicion es valida. Asignamos grid[r][c] = num e
			if (solve(grid, views, pos +1))                        //intentamos resolver la siguiente casilla (pos + 1)
				return (1);                                    //Si esa llamada devuelve 1 propagamos la victoria
			grid[row][col] = 0;                                    //retornando 1.
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	views[16];
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			grid[r][c] = 0;
			c++;
		}
		r++;
	}
	if (argc != 2 || !parse_input(argv[1], views))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (solve(grid, views, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
