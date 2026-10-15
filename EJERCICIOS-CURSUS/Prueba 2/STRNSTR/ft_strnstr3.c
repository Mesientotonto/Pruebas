/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 10:17:06 by acornia           #+#    #+#             */
/*   Updated: 2026/10/07 10:22:14 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	s1;
	size_t	s2;

	if (little[0] = '\0')
		return ((char *)big);
	s1 = 0;
	while (big[s1] != '\0' && s1 < len)
	{
		s2 = 0;
		while (big[s1 + s2] == little[s2] && (s1 + s2) < len)
		{
			if (little[s2 + 1] == '\0')
				return ((char *)&big[s1]);
			s2++;
		}
		s1++;
	}
	return (NULL);
}