/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:19:55 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 18:12:06 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main()
{
	int ret;
	char s2[] = "ceci est un test du printf";
	char c = 'a';
	char *s1;
	s1 = &c;

	// char v = '\0';
	// write(1, &v, 1);
	// printf("\n\n");


	ret = ft_printf("%8lc", '&');
	printf("ret : %d\n", ret);
	ret = ft_printf("%8lc", '&');
	printf("ret : %d\n", ret);
	printf("\n\n");
	printf("\n\n");


	// ret = ft_printf("^.^/%-24c^.^/", (char)0);
	// printf("ret : %d\n", ret);
	// ret = printf("^.^/%-24c^.^/", (char)0);
	// printf("ret : %d\n", ret);
	// printf("\n\n");
	// printf("\n\n");


// Qde          p6rEj-2147483647DHeK780000001Pwhret : 45
// Qde         p6rEj-2147483647DHeK780000001Pwhret : 46
// Qde*         p6rEj-2147483647DHeK780000001Pwhret : 45
// Qde*         p6rEj-2147483647DHeK780000001Pwhret : 46

//Qde         p6rEj-2147483647DHeK780000001Pwh

	//ret = ft_printf("%*.*u|%%|\n", -10, -5, 84);
	ret = ft_printf("Qde%-10cp6rEj%11.2dD%-cHeK7%*.5XPwh\n", '\0', -2147483647, '\0', 0, -2147483647);
	printf("ret : %d\n", ret);
	//ret = printf("%*.*u|%%|\n", -10, -5, 84);
	ret = printf("Qde%-10cp6rEj%11.2dD%-cHeK7%*.5XPwh\n", '\0', -2147483647, '\0', 0, -2147483647);
	printf("ret : %d\n", ret);
	printf("\n\n");
	printf("\n\n");

	ft_printf("|%c|\n", '\0');
	printf("|%c|", '\0');
	printf("\n\n");
	printf("\n\n");
	ft_printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	printf("\n\n");
	printf("\n\n");

	ft_printf("%*.*d|%%|\n", 10, 5, -42);
	printf("%*.*d|%%|\n", 10, 5, -42);
	printf("\n\n");
	ft_printf("%0*d|%%|\n", 5, -42);
	printf("%0*d|%%|\n", 5, -42);
	printf("\n\n");
	ft_printf("%-*d|%%|\n", 5, -42);
	printf("%-*d|%%|\n", 5, -42);
	printf("\n\n");


	ft_printf("|%0*x|\n", -20, 255);
	printf("|%0*x|\n\n", -20, 255);
	ft_printf("|%.*i|\n", -20, 20);
	printf("|%.*i|\n\n", -20, 20);
	ft_printf("|%.*u|\n", -20, 20);
	printf("|%.*u|\n\n", -20, 20);
	ft_printf("|%.*x|\n", -20, 20);
	printf("|%.*x|\n\n", -20, 20);
	ft_printf("pointer : |%p|\n", NULL);
	printf("pointer : |%p|\n\n", NULL);
	ft_printf("|%.*s|\n", -20, "abcd");
	printf("|%.*s|\n\n", -20, "abcd");
	// ft_printf("|%.*c|\n", -20, 'a');
	// printf("|%.*c|\n\n", -20, 'a');
	ft_printf("|%*%|\n", -20);
	printf("|%*%|\n\n", -20);

	// char *output;
	// output = "";
	// read(1, output, 50);
	// output[51] = '\0';


	ft_printf("%0*.*x|%%|\n", -10, 5, 0xda0);
	printf("%0*.*x|%%|\n\n", -10, 5, 0xda0);

	ft_printf("%0*.*d|%%|\n", -10, 5, 123);
	printf("%0*.*d|%%|\n\n", -10, 5, 123);

	ft_printf("%0*.*i|%%|\n", -10, 5, 345);
	printf("%0*.*i|%%|\n\n", -10, 5, 345);

	ft_printf("%0*.*u|%%|\n", -10, 5, 546);
	printf("%0*.*u|%%|\n\n", -10, 5, 546);


	printf("\n\n----------NUMBERS----------\n");

	printf("\n\n----------test1----------\n");
	ft_printf("|%-.10d|\n", 50);
	printf("|%-.10d|\n", 50);

	printf("\n\n----------test2----------\n");
	ft_printf("|%0.10d|\n", 50);
	printf("|%0.10d|\n", 50);

	printf("\n\n----------test3----------\n");
	ft_printf("|%.010d|\n", 50);
	printf("|%.010d|\n", 50);

	printf("\n\n----------test4----------\n");
	ft_printf("|%-*d|\n", 10, 50);
	printf("|%-*d|\n", 10, 50);

	printf("\n\n----------test5----------\n");
	ft_printf("|%.*d|\n", 10, 50);
	printf("|%.*d|\n", 10, 50);

	printf("\n\n----------test6----------\n");
	ft_printf("|%*.d|\n", 10, 50);
	printf("|%*.d|\n", 10, 50);

	printf("\n\n----------test7----------\n");
	ft_printf("|%0*d|\n", 10, -50);
	printf("|%0*d|\n", 10, -50);

	printf("\n\n----------test8----------\n");
	ft_printf("|%-.010d|\n", 50);
	printf("|%-.010d|\n", 50);

	printf("\n\n----------test9----------\n");
	ft_printf("|%-.010d|\n", 50);
	printf("|%-.010d|\n", 50);

	printf("\n\n----------test10----------\n");
	ft_printf("|%*.0d|\n", 10, 50);
	printf("|%*.0d|\n", 10, 50);

	printf("\n\n----------test11----------\n");
	ft_printf("|%0*.d|\n", 10, 50);
	printf("|%0*.d|\n", 10, 50);


	printf("\n\n----------STRINGS----------\n");

	printf("\n\n----------test12----------\n");
	ft_printf("|%.s|\n", "hi low\0don't print me lol\0");
	printf("|%.s|\n", "hi low\0don't print me lol\0");

	printf("\n\n----------test12----------\n");
	ft_printf("|%.10s|\n", s2);
	printf("|%.10s|\n", s2);

	printf("\n\n----------test13----------\n");
 	ft_printf("|%-10s|\n", s2);
	printf("|%-10s|\n", s2);

	printf("\n\n----------test14----------\n");
	ft_printf("|%-.10s|\n", s2);
	printf("|%-.10s|\n", s2);

	printf("\n\n----------test15----------\n");
	ft_printf("|%.010s|\n", s2);
	printf("|%.010s|\n", s2);

	printf("\n\n----------test16----------\n");
	ft_printf("|%.40s|\n", s2);
	printf("|%.40s|\n", s2);

	printf("\n\n----------test17----------\n");
	ft_printf("|%-40s|\n", s2);
	printf("|%-40s|\n", s2);

	printf("\n\n----------test18----------\n");
	ft_printf("|%-.40s|\n", s2);
	printf("|%-.40s|\n", s2);

	printf("\n\n----------test19----------\n");
	ft_printf("|%.040s|\n", s2);
	printf("|%.040s|\n", s2);

	printf("\n\n----------test20----------\n");
	ft_printf("|%.*s|\n", 10, s2);
	printf("|%.*s|\n", 10, s2);

	printf("\n\n----------test21----------\n");
	ft_printf("|%-*s|\n", 10, s2);
	printf("|%-*s|\n", 10, s2);

	printf("\n\n----------test21----------\n");
	ft_printf("|%*.s|\n", 10, s2);
	printf("|%*.s|\n", 10, s2);

	printf("\n\n----------test23----------\n");
	ft_printf("|%.*s|\n", 10, s2);
	printf("|%.*s|\n", 10, s2);

	printf("\n\n----------test24----------\n");
	ft_printf("|%.50s|\n", s2);
	printf("|%.50s|\n", s2);

	printf("\n\n----------test25----------\n");
	ft_printf("|%-50s|\n", s2);
	printf("|%-50s|\n", s2);

	printf("\n\n----------test26----------\n");
	ft_printf("|%-.50s|\n", s2);
	printf("|%-.50s|\n", s2);

	printf("\n\n----------test27----------\n");
	ft_printf("|%.050s|\n", s2);
	printf("|%.050s|\n", s2);

	printf("\n\n----------test28----------\n");
	ft_printf("|%.*s|\n", 50, s2);
	printf("|%.*s|\n", 50, s2);

	printf("\n\n----------test29----------\n");
	ft_printf("|%-*s|\n", 50, s2);
	printf("|%-*s|\n", 50, s2);

	printf("\n\n----------test30----------\n");
	ft_printf("|%*.s|\n", 50, s2);
	printf("|%*.s|\n", 50, s2);

	printf("\n\n----------test31----------\n");
	ft_printf("|%.*s|\n", 10, s2);
	printf("|%.*s|\n", 10, s2);

	printf("\n\n----------CHARS----------\n");

	printf("\n\n----------test32----------\n");
	ft_printf("|%*c|\n", 50, c);
	printf("|%*c|\n", 50, c);

	printf("\n\n----------test33----------\n");
	ft_printf("|%-10c|\n", c);
	printf("|%-10c|\n", c);

	printf("\n\n----------test34----------\n");
	ft_printf("|%*.c|\n", 50, c);
	printf("|%*.c|\n", 50, c);

	//printf("\n\n----------HEXA UNSIGNED INT----------\n");
	printf("\n\n----------HEXA----------\n");

	printf("\n\n----------test35----------\n");
	ft_printf("|%x|\n", -42);
	printf("|%x|\n", -42);

	printf("\n\n----------test35 '----------\n");
	ft_printf("|%0*x|\n", -20, ULLONG_MAX);
	printf("|%0*llx|\n", -20, ULLONG_MAX);

	printf("\n\n----------test35 ''----------\n");
	ft_printf("|%20x|\n", -10);
	printf("|%20x|\n", -10);

	printf("\n\n----------test35 '''----------\n");
	ft_printf("|%30.20x|\n", -10);
	printf("|%30.20x|\n", -10);

	printf("\n\n----------test36----------\n");
	ft_printf("|%.10X|\n", 42);
	printf("|%.10X|\n", 42);

	printf("\n\n----------test37----------\n");
	ft_printf("|%-10X|\n", 42);
	printf("|%-10X|\n", 42);

	printf("\n\n----------test38----------\n");
	ft_printf("|%*x|\n", 10, 42);
	printf("|%*x|\n", 10, 42);

	printf("\n\n----------test39----------\n");
	ft_printf("|%-.10X|\n", 42);
	printf("|%-.10X|\n", 42);

	printf("\n\n----------test40----------\n");
	ft_printf("|%0.X|\n", 42);
	printf("|%0.X|\n", 42);

	printf("\n\n----------test41----------\n");
	ft_printf("|%15.*x|\n", 10, -42);
	printf("|%15.*x|\n", 10, -42);

	printf("\n\n----------test42----------\n");
	ft_printf("|%X|\n", 9999999);
	printf("|%X|\n", 9999999);

	printf("\n\n----------UNSIGNED INT----------\n");

	printf("\n\n----------test43----------\n");
	ft_printf("|%-.10u|\n", 2000546511);
	printf("|%-.10u|\n", 2000546511);

	printf("\n\n----------test44----------\n");
	ft_printf("|%0.10u|\n", 2000546511);
	printf("|%0.10u|\n", 2000546511);

	printf("\n\n----------test45----------\n");
	ft_printf("|%.030u|\n", 2000546511);
	printf("|%.030u|\n", 2000546511);

	printf("\n\n----------test46----------\n");
	ft_printf("|%-*u|\n", 30, 2000546511);
	printf("|%-*u|\n", 30, 2000546511);

	printf("\n\n----------POINTER INT----------\n");

	printf("\n\n----------test47----------\n");
	ft_printf("|%p|\n", s1);
	printf("|%p|\n", s1);

	printf("\n\n----------test48----------\n");
	ft_printf("|%30p|\n", s1);
	printf("|%30p|\n", s1);

	printf("\n\n----------%%----------\n");

	printf("\n\n----------test49----------\n");
	ft_printf("|%%|\n");
	printf("|%%|\n");

	printf("\n\n----------test50----------\n");
	ft_printf("|%20%|\n");
	printf("|%20%|\n");

	printf("\n\n----------test51----------\n");
	ft_printf("|%*%|\n", -20);
	printf("|%*%|\n", -20);

	printf("\n\n----------test52----------\n");
	ft_printf("|%-*%|\n", 20);
	printf("|%-*%|\n", 20);

//Null specifier tests
	// ft_printf("%");
	// ft_printf("%5");
	// ft_printf("%05");
	// ft_printf("%-05");
	// ft_printf("%-5");

	return (0);
}

//gcc -Wall -Werror -Wextra ft_write_c.c ft_init_struct.c ft_apply_width_diux.c ft_substr.c ft_write_diux.c ft_is_type.c ft_printf.c ft_parse_str.c ft_set_prec.c ft_return_precision_diux.c ft_write_s.c ft_isdigit.c ft_set_width.c ft_return_width_diux.c ft_lltoa.c ft_putchar.c ft_strdup.c ft_atoi.c ft_get_formated.c ft_memcpy.c ft_putstr.c ft_strjoin.c ft_fill_struct.c ft_memset.c ft_strlen.c ft_hex_to_str.c ft_apply_precision_n_width_diux.c ft_apply_precision_diux.c ft_strupcase.c main.c && ./a.out

//cc -o ./a.out main.c libftprintf.a
//gcc -Wall -Werror -Wextra libftprintf.a main.c && ./a.out

