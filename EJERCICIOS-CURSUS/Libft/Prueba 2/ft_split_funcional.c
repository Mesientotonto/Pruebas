/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_funcional.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:45:27 by acornia           #+#    #+#             */
/*   Updated: 2026/09/29 11:45:36 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// --- FUNCIONES AUXILIARES NECESARIAS PARA EL TEST ---
size_t	ft_strlen(const char *str)
{
	size_t i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i = 0;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// Prototipo necesario porque fill_tab la llama antes de que esté definida abajo
char    *ft_substr(char const *s, unsigned int start, size_t len);

// --- TU CÓDIGO CORREGIDO ---

static int  count_words(char const *s, char c) // CORREGIDO: consr -> const
{
    int count;
    int in_word;

    count = 0;
    in_word = 0;
    while (*s != '\0')
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

static void free_array(char **tab, int i)
{
    while (i > 0)
    {
        i--;
        free(tab[i]);
    }
    free(tab);
}

static char **fill_tab(char **tab, const char *s, char c)
{
    int     i;
    size_t  len;

    i = 0;
    while (*s)
    {
        if (*s != c)
        {
            len = 0;
            while (s[len] && s[len] != c)
                len++;
            tab[i] = ft_substr(s, 0, len);
            if (!tab[i])
            {
                free_array(tab, i);
                return (NULL);
            }
            i++;
            s += len;
        }
        else
            s++;
    }
    tab[i] = NULL;
    return (tab);
}

char    **ft_split(char const *s, char c)
{
    char    **tab;

    if (!s)
        return (NULL);
    tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!tab)
        return (NULL);
    return (fill_tab(tab, s, c));
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub_str;
    size_t  sub_len;
    size_t  i;

    if (!s)
        return (NULL);
    sub_len = ft_strlen(s);
    if (sub_len < start)
        return (ft_strdup(""));
    if (len > sub_len - start)
        len = sub_len - start;
    sub_str = (char *)malloc(sizeof(char) * (len + 1));
    if (!sub_str)
        return (NULL);
    i = 0;
    while (i < len && s[start + i] != '\0')
    {
        sub_str[i] = s[start + i]; // CORREGIDO: substr -> sub_str
        i++;
    }
    sub_str[i] = '\0';             // CORREGIDO: substr -> sub_str
    return (sub_str);              // CORREGIDO: substr -> sub_str
}

// --- TESTS ---

static void test_split(char const *s, char c)
{
    char    **result;
    int     i;

    printf("Cadena: \"%s\" | Delimitador: '%c'\n", s, c);
    result = ft_split(s, c);
    if (!result)
    {
        printf("  [!] Error: ft_split devolvió NULL\n\n");
        return ;
    }
    i = 0;
    while (result[i])
    {
        printf("  tab[%d] -> \"%s\"\n", i, result[i]);
        free(result[i]);
        i++;
    }
    printf("  tab[%d] -> NULL\n\n", i);
    free(result);
}

int main(void)
{
    printf("=== TESTS DE FT_SPLIT ===\n\n");

    test_split("  hola   42  madrid ", ' ');
    test_split("---separado--por---guiones---", '-');
    test_split("una_sola_palabra", ',');
    test_split("", 'z');
    test_split("     ", ' ');

    return (0);
}