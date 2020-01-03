/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:29:45 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 17:15:33 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_c(t_parse *parsed, char c)
{
	size_t	size;
	char	chr;
	size_t	ret;

	ret = 0;
	chr = (parsed->is_0_filled && parsed->type == '%') ? '0' : ' ';
	size = (parsed->is_width && parsed->width > 1) ? parsed->width - 1 : 0;
	if (parsed->is_left)
	{
		ret += ft_putchar(c);
		while (size-- > 0)
			ret += ft_putchar(chr);
	}
	else
	{
		while (size-- > 0)
			ret += ft_putchar(chr);
		ret += ft_putchar(c);
	}
	return (ret);
}
