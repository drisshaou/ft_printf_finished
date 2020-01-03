/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_prec_diux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:23:57 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 19:16:02 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_prec_diux(t_parse *parsed, long long value)
{
	char	*tmp;
	size_t	size;
	size_t	is_neg;

	if (parsed->type == 'x')
		tmp = ft_hex_to_str((unsigned long long)value);
	else if (parsed->type == 'X')
		tmp = ft_strupcase(ft_hex_to_str((unsigned long long)value));
	else
		tmp = ft_lltoa(value < 0 ? -value : value);
	is_neg = (value < 0 && parsed->type != 'x' && parsed->type != 'X') ? 1 : 0;
	size = ft_strlen(tmp);
	size = (parsed->prec > size) ? parsed->prec : size;
	size += (is_neg) ? 1 : 0;
	size = (parsed->prec == 0 && value == 0) ? 0 : size;
	return (ft_return_prec_diux(is_neg, size, tmp));
}

char	*ft_return_prec_diux(size_t is_neg, size_t sz, char *tmp)
{
	char	*str;
	size_t	ln;

	if (!(str = malloc(sizeof(char) * (sz + 1))))
		return (NULL);
	if (sz != 0)
	{
		ln = sz - ft_strlen(tmp);
		ft_memset(str, '0', sz);
		if (is_neg)
			str[0] = '-';
		ft_memcpy(str + ln, tmp, ft_strlen(tmp));
	}
	str[sz] = '\0';
	free(tmp);
	return (str);
}
