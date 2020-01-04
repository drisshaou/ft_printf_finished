/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width_diux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:26:04 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 17:07:10 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_width_diux(t_parse *parsed, long long value)
{
	char	*tmp;
	size_t	size;
	size_t	is_neg;

	if (parsed->type == 'x')
		tmp = ft_hex_to_str(value, "0123456789abcdef");
	else if (parsed->type == 'X')
		tmp = ft_hex_to_str(value, "0123456789ABCDEF");
	else
		tmp = ft_lltoa(value < 0 ? -value : value);
	is_neg = (value < 0 && parsed->type != 'x' && parsed->type != 'X') ? 1 : 0;
	size = ft_strlen(tmp);
	size += (is_neg) ? 1 : 0;
	size = (parsed->is_width && parsed->width > size) ? parsed->width : size;
	return (ft_return_width_diux(parsed, is_neg, size, tmp));
}

char	*ft_return_width_diux(t_parse *psd, size_t is_neg, size_t sz, char *tmp)
{
	char	*str;
	size_t	ln;

	ln = sz - ft_strlen(tmp);
	if (!(str = malloc(sizeof(char) * (sz + 1))))
		return (NULL);
	if (psd->is_0_filled)
		ft_memset(str, '0', sz);
	else
		ft_memset(str, ' ', sz);
	if (is_neg && (psd->is_0_filled || psd->is_left))
		str[0] = '-';
	else if (is_neg && !psd->is_0_filled && !psd->is_left)
		str[ln - 1] = '-';
	if (is_neg && psd->is_left)
		ft_memcpy(str + 1, tmp, ft_strlen(tmp));
	else if (!is_neg && psd->is_left)
		ft_memcpy(str, tmp, ft_strlen(tmp));
	else if (!psd->is_left)
		ft_memcpy(str + ln, tmp, ft_strlen(tmp));
	str[sz] = '\0';
	free(tmp);
	return (str);
}
