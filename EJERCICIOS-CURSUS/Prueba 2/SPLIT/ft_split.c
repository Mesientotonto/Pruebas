/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:05:40 by acornia           #+#    #+#             */
/*   Updated: 2026/09/29 11:44:25 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	count;				//Total de palabras encontradas
	int	in_word;			//Estado: 0(fuera de una palabra), 1(dentro de una palabra)

	count = 0;
	in_word = 0;
	while (*s != '\0')		//Mientras no lleguemos al '\0' de la cadena
	{
		//Si el caracter actual NO es el delimitador y estabamos FUERA de una palabra
		if (*s != c && !in_word)
		{
			in_word = 1;	//Entramos en una palabra
			count++;		//Contabilizamos una palabra nueva
		}
		//Si el caracter actual SI es el delimitador
		else if (*s == c)
			in_word = 0;	//Salimos de la palabra
		s++;				//Avanzamos al siguiente caracter de la cadena
	}
	return (count);
}
/*Si el sistema se queda sin memoria a mitad de la extraccion, esta funcion deshace todo el
trabajo para evitar memory leaks*/

static void	free_array(char **tab, int i)
{
	//'i' representa el numero exacto de palabras que se lograton asignar con exito
	while (i > 0)
	{
		i--;				//Restamos primero. Si i era 2, pasamos al indice 1
		free(tab[i]);		//Liberamos la palabra en esa posicion
	}
	free(tab);				//Una vez liberamos todas las palabras, liberamos la matriz
}

static char	**fill_tab(char **tab, const char *s, char c)
{
	int		i;				//Indice para la matriz tab
	size_t	len;			//Longitud de la palbra actual

	i = 0;
	while (*s)				//Recorremos toda la cadena principal
	{
		if (*s != c)		//Si encontramos un caracter valido
		{
			len = 0;
			//Medimos la palabra: avanzamos len mientras no haya '\0'
			while (s[len] && s[len] != c)
				len++;
			//Extraemos esa porcion exacta usando ft_substr
			tab[i] = ft_substr(s, 0, len);
			//Si substr fallo por falta de memoria
			if (!tab[i])
			{
				free_array(tab, i);
				return (NULL);
			}
			i++;			//Avanzamos al siguiente hueco en la matriz
			s += len;		//Saltamos de golpe todos los caracteres de la palabra
		}
		else
		{
			s++;			//Si era un delimitador, simplemente lo ignoramos y avanzamos
		}
	}
	tab[i] = NULL;			//Al terminar, ponemos el cerrojo
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	return (fill_tab(tab, s, c));
}
