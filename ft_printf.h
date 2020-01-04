/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:31:38 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 19:21:05 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-0"
# define TYPES "cCsSpdiuxX%aAoeEfFgGnZ"

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_parse
{
	size_t		is_left;
	size_t		is_0_filled;
	size_t		is_width;
	size_t		width;
	size_t		is_prec;
	size_t		prec;
	char		type;
}				t_parse;
int				ft_printf(const char *str, ...);
size_t			ft_parse_str(const char *str, va_list args);
int				ft_is_type(char c, const char *flags);
size_t			ft_put_parsed_str(char *str, va_list args);
void			ft_init_struct(t_parse *parsed);
void			ft_fill_struct(va_list args, t_parse *parsed, char *str);
char			*ft_set_prec(char *str, t_parse *parsed, va_list args);
char			*ft_set_width(char *str, t_parse *parsed, va_list args);
size_t			ft_write_c(t_parse *parsed, char c);
size_t			ft_write_s(t_parse *parsed, char *tmp);
char			*ft_apply_prec_s(t_parse *parsed, char *tmp);
size_t			ft_write_diux(t_parse *parsed, long long value);
char			*ft_apply_prec_diux(t_parse *parsed, long long value);
char			*ft_return_prec_diux(size_t is_neg, size_t sz, char *tmp);
char			*ft_apply_width_diux(t_parse *parsed, long long value);
char			*ft_return_width_diux(t_parse *psd, size_t is_neg, size_t sz,
					char *tmp);
char			*ft_apply_prec_n_width_diux(t_parse *parsed, long long value);
size_t			ft_write_p(t_parse *parsed, void *addr);
char			*ft_apply_prec_p(t_parse *parsed, void *addr);
char			*ft_return_prec_p(size_t sz, char *tmp);
char			*ft_apply_width_p(t_parse *parsed, void *addr);
char			*ft_return_width_p(t_parse *parsed, size_t sz, char *tmp);
char			*ft_apply_prec_n_width_p(t_parse *parsed, void *addr);
char			*ft_hex_to_str(unsigned long long nbr, char *base);
char			*ft_lltoa(long long n);
int				ft_atoi(const char *s);
int				ft_isdigit(int c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_putchar(char c);
size_t			ft_putstr(char *s);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
