/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 13:52:40 by acornia           #+#    #+#             */
/*   Updated: 2026/09/30 10:37:52 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	//Si es negativo ocupara un caracter para el signo
	if (n <= 0)
		len = 1;
	//Mientras queden numeros que procesar
	while (n != 0)
	{
		n = n/  10;			//Le quitamos el ultimo digito
		len++;				//Sumamos 1 a la longitud para cada digito
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	len = get_len(n);		//Obtenemos el tamaño
	str = (char *)malloc(sizeof(char) * (len + 1));		//+1 para el '\0'
	if (!str)
		return (NULL);
	str[len] = '\0';
	num = n;
	//Si era un cero, lo resolvemos rapido
	if (num == 0)
		str[0] = '0';
	//Si es negativo ponemos el signo
	else if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	//Mientras el numero sea mayor que cero
	while (num > 0)
	{
		//1. Obtenemos el ultimo digito con % 10
		//2. Le sumamos '0'
		//3. Lo guardamos en la posicion anterior
		str[len - 1] = (num % 10) + '0';
		//Recortamos el ultimo digito
		num = num / 10;
		//Retrodecemos el indice para escribir el siguiente numero
		len--;
	}
	return (str);		//Devolvemos la cadena terminada
}