/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:29:29 by acornia           #+#    #+#             */
/*   Updated: 2026/10/05 10:26:14 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	test_atoi(void);
void	test_bzero(void);
void	test_isalnum(void);
void	test_isalpha(void);
void	test_isascii(void);
void	test_isdigit(void);
void	test_calloc(void);
void	test_itoa(void);
void	test_memchr(void);
void	test_memcmp(void);
void	test_memcpy(void);
void	test_memmove(void);
void	test_memset(void);
void	test_putchar_fd(void);
void	test_putendl_fd(void);
void	test_putnbr_fd(void);
void	test_putstr_fd(void);
void	test_split(void);
void	test_strchr(void);
void	test_strdup(void);
void	test_striteri(void);
void	test_strjoin(void);
void	test_strlcat(void);
void	test_strlcpy(void);
void	test_strlen(void);
void	test_strmapi(void);
void	test_strncmp(void);
void	test_strnstr(void);
void	test_strrchr(void);
void	test_strtrim(void);
void	test_substr(void);
void	test_tolower(void);
void	test_toupper(void);
void	test_lstnew(void);
void	test_lstsize(void);
void	test_lstlast(void);
void    test_lstadd_front(void);
void    test_lstadd_back(void);
void    test_lstdelone(void);
void    test_lstiter(void);

int	main(void)
{
	test_tolower();
	test_toupper();
	test_strlen();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_strnstr();
	test_memset();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
	test_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_strmapi();
	test_striteri();
	test_split();
	test_lstnew();
	test_lstsize();
	test_lstlast();
	test_lstadd_front();
    test_lstadd_back();
    test_lstdelone();
    test_lstiter();
	printf("\n\n=== TODOS LOS TESTS COMPLETADOS ===\n");
	return (0);
}

void	test_atoi(void)
{
	char	*num;

	num = "-42";
	printf("\nft_atoi\n");
	printf("Vamos a hacer atoi de %s.\nEl resultado es: %d.\n", num, ft_atoi(num));
}

void	test_bzero(void)
{
	char str[6] = "Hola!";
		
	ft_bzero(str, 2);
	printf("\nft_bzero\n");
	printf("Posiciones 0 y 1 (nulos) : %d %d\n", str[0], str[1]);
	printf("Posiciones 2, 3 y 4 (texto): %c %c %c\n", str[2], str[3], str[4]);
}

void	test_calloc(void)
{
	char	*str;

	str = (char *)ft_calloc(4, sizeof(char));
	printf("\nft_calloc\n");
	if (str != NULL)
	{
		printf("Puntero asignado correctamente.\n");
		printf("Contenido: %d %d %d %d\n", str[0], str[1], str[2], str[3]);
		free(str);
	}
	else
		printf("Fallo al reservar memoria.\n");
}

void	test_isalnum(void)
{
	printf("\nft_isalnum\n");
	printf("'A' (letra)  : %d\n", ft_isalnum('A'));
	printf("'5' (número) : %d\n", ft_isalnum('5'));
	printf("'?' (símbolo): %d\n", ft_isalnum('?'));
}

void	test_isalpha(void)
{
	printf("\nft_isalpha\n");
	printf("'A' (letra)  : %d\n", ft_isalpha('A'));
	printf("'5' (número) : %d\n", ft_isalpha('5'));
	printf("'?' (símbolo): %d\n", ft_isalpha('?'));
}

void	test_isascii(void)
{
	printf("\nft_isascii\n");
	printf("'A' (letra)  : %d\n", ft_isascii('A'));
	printf("'5' (número) : %d\n", ft_isascii('5'));
	printf("'Ç' (símbolo): %d\n", ft_isascii(128));
}

void	test_isdigit(void)
{
	printf("\nft_isdigit\n");
	printf("'A' (letra)  : %d\n", ft_isdigit('A'));
	printf("'5' (número) : %d\n", ft_isdigit('5'));
	printf("'6' (numero): %d\n", ft_isdigit('6'));
}

void	test_itoa(void)
{
	int	num;

	num = -42;
	printf("\nft_itoa\n");
	printf("Vamos a hacer itoa de %d.\nEl resultado es: %s.\n", num, ft_itoa(num));
}

void	test_memchr(void)
{
	char	*str;

	str = "Hola 42";
	printf("\nft_memchr\n");
	printf("Vamos a buscar '4' en %s.\nEl resultado es: %s.\n", str, (char *)ft_memchr(str, '4', 7));
}

void	test_memcmp(void)
{
	char	*s1;
	char	*s2;

	s1 = "abc";
	s2 = "abd";
	printf("\nft_memcmp\n");
	printf("Vamos a comparar %s y %s (3 bytes).\nEl resultado es: %d.\n", s1, s2, ft_memcmp(s1, s2, 3));
}

void	test_memcpy(void)
{
	char	dest[10];
	char	*src;

	src = "42 Madrid";
	printf("\nft_memcpy\n");
	printf("Vamos a copiar '%s'.\nEl resultado es: %s.\n", src, (char *)ft_memcpy(dest, src, 10));
}

void	test_memmove(void)
{
	char	str[] = "42 Madrid";

	printf("\nft_memmove\n");
	printf("Vamos a solapar memoria.\nEl resultado es: %s.\n", (char *)ft_memmove(str + 3, str, 7));
}

void	test_memset(void)
{
	char	str[] = "42 Madrid";

	printf("\nft_memset\n");
	printf("Vamos a hacer memset de '*' en los primeros 2 bytes.\nEl resultado es: %s.\n", (char *)ft_memset(str, '*', 2));
}

void	test_putchar_fd(void)
{
	char	c;

	c = 'A';
	printf("\nft_putchar_fd\n");
	printf("Vamos a imprimir '%c' en el fd 1.\nEl resultado es:\n", c);
	ft_putchar_fd(c, 1);
	printf("\n");
}

void	test_putendl_fd(void)
{
	char	*str;

	str = "Hola 42";
	printf("\nft_putendl_fd\n");
	printf("Vamos a imprimir \"%s\" en el fd 1 (con salto).\nEl resultado es:\n", str);
	ft_putendl_fd(str, 1);
}
void	test_putnbr_fd(void)
{
	int num;

	num = -42;
	printf("\nft_putnbr_fd\n");
	printf("Vamos a imprimir %d en el fd 1.\nEl resultado es:\n", num);
	ft_putnbr_fd(num, 1);
	printf("\n");
}

void	test_putstr_fd(void)
{
	char	*str;

	str = "Hola 42";
	printf("\nft_putstr_fd\n");
	printf("Vamos a imprimir \"%s\" en el fd 1.\nEl resultado es:\n", str);
	ft_putstr_fd(str, 1);
	printf("\n");
}

void	test_split(void)
{
	char	**res;
	int	 i;

	i = 0;
	printf("\nft_split\n");
	printf("Vamos a separar \"Hola 42 Madrid\" por ' '.\nEl resultado es:\n");
	res = ft_split("Hola 42 Madrid", ' ');
	while (res && res[i])
	{
		printf("[%s]\n", res[i]);
		i++;
	}
}

void	test_strchr(void)
{
	char	*str;

	str = "Hola 42";
	printf("\nft_strchr\n");
	printf("Vamos a buscar '4' en \"%s\".\nEl resultado es: %s.\n", str, ft_strchr(str, '4'));
}

void	test_strdup(void)
{
	char	*str;

	str = "Hola 42";
	printf("\nft_strdup\n");
	printf("Vamos a duplicar \"%s\".\nEl resultado es: %s.\n", str, ft_strdup(str));
}

void	helper_striteri(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	test_striteri(void)
{
	char	str[] = "hola 42";
	
	printf("\nft_striteri\n");
	printf("Vamos a pasar a mayusculas \"%s\".\nEl resutado es:\n", str);
	ft_striteri(str, helper_striteri);
	printf("%s\n", str);
}

char	helper_strmapi(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	test_strmapi(void)
{
	char	*str;
	char	*res;

	str = "hola 42";
	printf("\nft_strmapi\n");
	res = ft_strmapi(str, helper_strmapi);
	printf("Vamos a mapear \"%s\".\nEl resultado es: %s.\n", str, res);
}

void	test_strjoin(void)
{
	char	*s1;
	char	*s2;

	s1 = "Hola ";
	s2 = "42";
	printf("\nft_strjoin\n");
	printf("Vamos a unir \"%s\" y \"%s\".\nEl resultado es: %s.\n", s1, s2, ft_strjoin(s1, s2));
}

void	test_strlcat(void)
{
	char	dst[20] = "Hola ";
	char	*src;

	src = "42 Madrid";
	printf("\nft_strlcat\n");
	printf("Vamos a concatenar \"%s\" en \"Hola \".\n", src);
	printf("Devuelve: %d. String final: %s.\n", (int)ft_strlcat(dst, src, 20), dst);
}

void	test_strlcpy(void)
{
	char	dst[20];
	char	*src;
	int		res;

	src = "Hola 42";
	printf("\nft_strlcpy\n");
	res = ft_strlcpy(dst, src, 20);
	printf("Vamos a copiar \"%s\".\nEl resultado es: %s (devuelve %d).\n", src, dst, res);
}

void	test_strlen(void)
{
	char	*str;

	str = "Hola 42";
	printf("\nft_strlen\n");
	printf("Vamos a medir \"%s\".\nEl resultado es: %d.\n", str, (int)ft_strlen(str));
}

void	test_strncmp(void)
{
	char	*s1;
	char	*s2;

	s1 = "Hola 42";
	s2 = "Hola 21";
	printf("\nft_strncmp\n");
	printf("Vamos a comparar \"%s\" y \"%s\" hasta 6 caracteres.\nEl resultado es: %d.\n", s1, s2, ft_strncmp(s1, s2, 6));
}

void	test_strnstr(void)
{
	char	*haystack;
	char	*needle;

	haystack = "Hola 42 Madrid";
	needle = "42";
	printf("\nft_strnstr\n");
	printf("Vamos a buscar \"%s\" en \"%s\" (max 10 bytes).\nEl resultado es: %s.\n", needle, haystack, ft_strnstr(haystack, needle, 10));
}

void	test_strrchr(void)
{
	char	*str;

	str = "Hola 42 Madrid 42";
	printf("\nft_strrchr\n");
	printf("Vamos a buscar la ultima 'a' en \"%s\".\nEl resultado es: %s.\n", str, ft_strrchr(str, 'a'));
}

void	test_strtrim(void)
{
	char	*str;
	char	*set;

	str = "  --Hola 42--  ";
	set = " -";
	printf("\nft_strtrim\n");
	printf("Vamos a recortar los caracteres \"%s\" de \"%s\".\nEl resultado es: \"%s\".\n", set, str, ft_strtrim(str, set));
}

void	test_substr(void)
{
	char	*str;
	char	*res;

	str = "Hola 42 Madrid";
	printf("\nft_substr\n");
	res = ft_substr(str, 5, 2);
	printf("Vamos a extraer 2 caracteres desde la posicion 5 de \"%s\".\nEl resultado es: \"%s\".\n", str, res);
}

void	test_tolower(void)
{
	char	c;

	c = 'A';
	printf("\nft_tolower\n");
	printf("Vamos a convertir '%c'.\nEl resultado es: '%c'.\n", c, ft_tolower(c));
}

void	test_toupper(void)
{
	char	c;

	c = 'a';
	printf("\nft_toupper\n");
	printf("Vamos a convertir '%c'.\nEl resultado es: '%c'.\n", c, ft_toupper(c));
}

void	test_lstnew(void)
{
	t_list *node = ft_lstnew("Hola 42");
	printf("\nft_lstnew\n");
	printf("ft_lstnew content: %s.\n", (char *)node->content);
	free(node);
}

void	test_lstsize(void)
{
	t_list	*n1 = ft_lstnew("Nodo 1");
	t_list	*n2 = ft_lstnew("Nodo 2");
	t_list	*n3 = ft_lstnew("Nodo 3");

	n1->next = n2;
	n2->next = n3;
	printf("\nft_lstsize\n");
	printf("ft_lstsize content: %d.\n", ft_lstsize(n1));
	free(n3);
	free(n2);
	free(n1);
}

void	test_lstlast(void)
{
	t_list	*n1 = ft_lstnew("hola");
	t_list	*n2 = ft_lstnew("que");
	t_list	*n3 = ft_lstnew("tal");

	n1->next = n2;
	n2->next = n3;
	printf("\nft_lstlast\n");
	printf("%s.\n", (char *)ft_lstlast(n1)->content);
	free(n3);
	free(n2);
	free(n1);
}

void    test_lstadd_front(void)
{
    t_list  *head;

    head = NULL;
    ft_lstadd_front(&head, ft_lstnew("que"));
    ft_lstadd_front(&head, ft_lstnew("hola"));
    printf("\nft_lstadd_front\n");
    printf("Primer nodo: %s. Segundo nodo: %s.\n", (char *)head->content, (char *)head->next->content);
    free(head->next);
    free(head);
}

void    test_lstadd_back(void)
{
    t_list  *head;

    head = NULL;
    ft_lstadd_front(&head, ft_lstnew("hola"));
    ft_lstadd_back(&head, ft_lstnew("tal"));
    printf("\nft_lstadd_back\n");
    printf("Primer nodo: %s. Ultimo nodo: %s.\n", (char *)head->content, (char *)head->next->content);
    free(head->next);
    free(head);
}

static void helper_del_content(void *content)
{
    free(content);
}

void    test_lstdelone(void)
{
    t_list  *node;

    node = ft_lstnew(ft_strdup("Hola 42"));
    printf("\nft_lstdelone\n");
    printf("Eliminando nodo con contenido: %s.\n", (char *)node->content);
    ft_lstdelone(node, helper_del_content);
    printf("Nodo eliminado correctamente.\n");
}

static void helper_print_content(void *content)
{
    printf("[%s]\n", (char *)content);
}

void    test_lstiter(void)
{
    t_list  *n1;
    t_list  *n2;
    t_list  *n3;

    n1 = ft_lstnew("hola");
    n2 = ft_lstnew("que");
    n3 = ft_lstnew("tal");
    n1->next = n2;
    n2->next = n3;
    printf("\nft_lstiter\n");
    printf("Iterando sobre la lista:\n");
    ft_lstiter(n1, helper_print_content);
    free(n3);
    free(n2);
    free(n1);
}