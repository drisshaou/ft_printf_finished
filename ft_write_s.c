/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:29:21 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 19:15:26 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_s(t_parse *parsed, char *tmp)
{
	char	*str;
	size_t	size;
	size_t	len;
	size_t	ret;
	char	chr;

	chr = (parsed->is_0_filled) ? '0' : ' ';
	str = ft_apply_prec_s(parsed, tmp);
	len = ft_strlen(str);
	size = (parsed->is_width && parsed->width > len) ? parsed->width - len : 0;
	ret = 0;
	if (parsed->is_left)
	{
		ret = ft_putstr(str);
		while (size-- > 0)
			ret += ft_putchar(chr);
	}
	else
	{
		while (size-- > 0)
			ret += ft_putchar(chr);
		ret += ft_putstr(str);
	}
	free(str);
	return (ret);
}
