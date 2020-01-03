/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_prec_n_width_diux.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:26:57 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 19:16:21 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_prec_n_width_diux(t_parse *parsed, long long value)
{
	char	*tmp;
	size_t	len;
	size_t	size;
	char	*str;

	tmp = ft_apply_prec_diux(parsed, value);
	len = ft_strlen(tmp);
	size = (parsed->width > len && parsed->width > 0) ? parsed->width : len;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(str, ' ', size);
	if (parsed->is_left)
		ft_memcpy(str, tmp, len);
	else
		ft_memcpy(str + (size - len), tmp, len);
	str[size] = '\0';
	free(tmp);
	return (str);
}
