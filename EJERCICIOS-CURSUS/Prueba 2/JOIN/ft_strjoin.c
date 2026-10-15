/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:55:27 by acornia           #+#    #+#             */
/*   Updated: 2026/09/29 10:59:32 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str1;
	size_t	str2;

	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (str1 + str2 + 1))
	if (!str)
		return (NULL);
	ft_strcpy(str, s1, str1 + 1);
	ft_strlcat(str, s2, str1 + str2 + 1);
	return (str);
}