/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:57:08 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/18 16:57:48 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "includes/libftasm.h"

int			main(int argc, char **argv)
{
	char 	tg[6] = "coucou";
	char	tg2[6] = "coucou";

	int		i = 0;

	printf("\033[31mtest : ft_memset(\"coucou\", 'a', 4)\033[0m\n");
	printf("%s\n", (char*)ft_memset(tg, 'a', 4));
	printf("%s\n", (char*)memset(tg2, 'a', 4));
	printf("\n\033[31mtest : ft_bzero(\"coucou\", 4)\033[0m\n");
	ft_bzero(tg, 4);
	bzero(tg2, 4);
	while (i < 6)
	{
		printf("%c", tg[i++]);
	}
	printf("\n");
	i = 0;
	while (i < 6)
	{
		printf("%c", tg2[i++]);
	}
	printf("\n");
	printf("\n\033[31mtest : ft_isalpha(int c)\033[0m\n");
	printf("c = %d\n", ft_isalpha('c'));
	printf("C = %d\n", ft_isalpha('C'));
	printf("a = %d\n", ft_isalpha('a'));
	printf("z = %d\n", ft_isalpha('z'));
	printf("A = %d\n", ft_isalpha('A'));
	printf("Z = %d\n", ft_isalpha('Z'));
	printf("/ = %d\n", ft_isalpha('/'));
	printf("\\0 = %d\n", ft_isalpha('\0'));
	printf("\n\033[31mtest : ft_isdigit(int c)\033[0m\n");
	printf("0 = %d\n", ft_isdigit('0'));
	printf("9 = %d\n", ft_isdigit('9'));
	printf("5 = %d\n", ft_isdigit('5'));
	printf("a = %d\n", ft_isdigit('a'));
	printf("'9' + 1 = %d\n", ft_isdigit('9' + 1));
	printf("\n\033[31mtest : ft_isdigit(int c)\033[0m\n");
	printf("c = %d\n", ft_isalnum('c'));
	printf("C = %d\n", ft_isalnum('C'));
	printf("\\0 = %d\n", ft_isalnum('\0'));
	printf("5 = %d\n", ft_isalnum('5'));
	printf("[ = %d\n", ft_isalnum('['));
	printf("\n\033[31mtest : ft_isascii(int c)\033[0m\n");
	printf("-1 = %d\n", ft_isascii(-1));
	printf("135 = %d\n", ft_isascii(135));
	printf("10 = %d\n", ft_isascii(10));
	printf("78 = %d\n", ft_isascii(78));
	printf("\n\033[31mtest : ft_isprint(int c)\033[0m\n");
	printf("25 = %d\n", ft_isprint(25));
	printf("133 = %d\n", ft_isprint(133));
	printf("space = %d\n", ft_isprint(' '));
	printf("~ = %d\n", ft_isprint('~'));
	printf("\n\033[31mtest : ft_toupper(int c)\033[0m\n");
	printf("a = %c\n", ft_toupper('a'));
	printf("A = %c\n", ft_toupper('A'));
	printf("[ = %c\n", ft_toupper('['));
	printf("\n\033[31mtest : ft_tolower(int c)\033[0m\n");
	printf("a = %c\n", ft_tolower('a'));
	printf("A = %c\n", ft_tolower('A'));
	printf("[ = %c\n", ft_tolower('['));
	printf("\n\033[31mtest : ft_strlen(const char *s)\033[0m\n");
	printf("%d = ft_strlen(\"ta mere\")\n", ft_strlen("coucou"));
	printf("%d = ft_strlen(\"cou\\0cou\")\n", ft_strlen("cou\0cou"));
	printf("%d = ft_strlen(\"\")\n", ft_strlen(""));
	printf("%d = strlen(\"cou\\0cou\")\n", strlen("cou\0cou"));
	printf("\n\033[31mtest : ft_puts(const char *s)\033[0m\n");
	printf("%d = ft_puts(\"ta mere\")\n", ft_puts("ta mere"));
	printf("%d = puts(\"ta mere\")\n", puts("ta mere"));
	printf("%d = ft_puts(NULL)\n", ft_puts(NULL));
	printf("%d = puts(NULL)\n", puts(NULL));
	printf("\n\033[31mtest : ft_strcat(char *s1, const char *s2)\033[0m\n");
	char s1[100] = "cou";
	char s2[100] = "jajajaja";
	printf("s1 = cou, s2 = tg\n%s\n", ft_strcat(s1, "tg"));
	printf("%s\n", strcat(s1, "tg"));
	printf("\n\033[31mtest : ft_strdup(const char *s1)\033[0m\n");
	printf("%s\n", ft_strdup(s1));
	printf("%s\n", strdup(s1));
	printf("\n\033[31mtest : ft_memcpy(void *dst, const void *src, size_t len)\033[0m\n");
	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("= %s\n", ft_memcpy(s1, s2, 4));
	i = 0;
	while (i < 4)
	{
		printf("s1 = %p, s2 = %p\n", s1[i], s2[i]);
		i++;
	}
	printf("\n\033[31mtest : ft_min(int fd)\033[0m\n");
	printf("min 3 : 9 = %d\n", ft_min(3, 9));
	printf("min 9 : 3 = %d\n", ft_min(9, 3));
	printf("min 3 : 3 = %d\n", ft_min(3, 3));
	printf("\n\033[31mtest : ft_max(int fd)\033[0m\n");
	printf("max 3 : 9 = %d\n", ft_max(3, 9));
	printf("max 9 : 3 = %d\n", ft_max(9, 3));
	printf("max 3 : 3 = %d\n", ft_max(3, 3));
	printf("\n\033[31mtest : ft_strclr(char *s)\033[0m\n");
	char s3[10] = "coucou";
	ft_strclr(s3);
	printf("coucou = %s\n", s3);
	printf("\n\033[31mtest : ft_strnew(size_t size)\033[0m\n");
	printf("ft_strnew(6)\n");
	i = 0;
	char *sto = NULL;
	sto = ft_strnew(6);
	while (i < 6)
	{
		printf("%d", sto[i]);
		i++;
	}
	printf("\n");
	free(sto);
	sto = NULL;
	printf("\n\033[31mtest : ft_strjoin(const char *s1, const char *s2)\033[0m\n");
	printf("ft_strjoin(\"coucou\",\"tg\") = %s\n", ft_strjoin("coucou", "tg"));	
	printf("ft_strjoin(\"coucou\",NULL) = %s\n", ft_strjoin("coucou", NULL));
	printf("ft_strjoin(NULL,\"tg\") = %s\n", ft_strjoin(NULL, "tg"));
	printf("ft_strjoin(NULL, NULL) = %s\n", ft_strjoin(NULL, NULL));
	printf("\n\033[31mtest : ft_strchr(const char *s, int c)\033[0m\n");
	char s4[10] = "coucou";
	printf("ft_strchr(\"coucou\", 'u' = %s\n", ft_strchr(s4, 'u'));
	printf("ft_strchr(\"coucou\", 'o' = %s\n", ft_strchr(s4, 'o'));
	printf("ft_strchr(\"coucou\", '\\0' = %s\n", ft_strchr(s4, '\0'));
	printf("strchr(\"coucou\", 'u' = %s\n", strchr("coucou", 'u'));
	printf("strchr(\"coucou\", 'o' = %s\n", strchr("coucou", 'o'));
	printf("strchr(\"coucou\", '\\0' = %s\n", strchr("coucou", '\0'));
	printf("\n\033[31mtest : ft_strncpy(char *dst, const char *s, size_t n)\033[0m\n");
	char s5[10] = "coucou";
	char s6[10] = "coucou";
	printf("ft_strncpy(\"coucou\", \"tg\", 2) = %s\n", ft_strncpy(s5, "tg", 2));
	printf("strncpy(\"coucou\", \"tg\", 2) = %s\n", strncpy(s6, "tg", 2));
	printf("ft_strncpy(\"coucou\", \"tg\", 10) = %s\n", ft_strncpy(s5, "tg", 10));
	printf("strncpy(\"coucou\", \"tg\", 10) = %s\n", strncpy(s6, "tg", 10));
	printf("\n\033[31mtest : ft_strsub(char const *s, unsigned int start, size_t len)\033[0m\n");
	printf("ft_strsub(\"coucou\", 0, 10) = %s\n", ft_strsub("coucou", 0, 10));
	printf("ft_strsub(\"coucou\", 2, 3) = %s\n", ft_strsub("coucou", 2, 3));
	printf("ft_strsub(\"coucou\", 4, 2) = %s\n", ft_strsub("coucou", 4, 2));
	printf("ft_strsub(\"coucou\", 10, 3) = %s\n", ft_strsub("coucou", 10, 3));
	printf("ft_strsub(NULL, 0, 10) = %s\n", ft_strsub(NULL, 0, 10));
	printf("ft_strsub(\"\", 0, 10) = %s\n", ft_strsub("", 0, 10));
	printf("\n\033[31mtest : ft_abs(int c)\033[0m\n");
	printf("ft_abs(5) = %d\n", ft_abs(5));
	printf("ft_abs(0) = %d\n", ft_abs(0));
	printf("ft_abs(-5) = %d\n", ft_abs(-5));
	printf("\n\033[31mtest : ft_cat(int fd)\033[0m\n");
	if (argc == 2)
	{
		int fd = open("main.c", O_RDONLY);
		ft_cat(0);
		ft_cat(fd);
	}
	else
		ft_cat(0);
	return (1);
}
