/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_parsed_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 06:47:36 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 18:40:54 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_parsed_str(char *str, va_list args)
{
	t_parse	parsed;
	size_t	ret;

	ret = 0;
	ft_fill_struct(args, &parsed, str);
	if (parsed.type == '%')
		ret = ft_write_c(&parsed, '%');
	else if (parsed.type == 'c')
		ret = ft_write_c(&parsed, (char)va_arg(args, int));
	else if (parsed.type == 's')
		ret = ft_write_s(&parsed, va_arg(args, char *));
	else if (parsed.type == 'd' || parsed.type == 'i')
		ret = ft_write_diux(&parsed, va_arg(args, int));
	else if (parsed.type == 'u')
		ret = ft_write_diux(&parsed, va_arg(args, unsigned int));
	else if (parsed.type == 'x' || parsed.type == 'X')
		ret = ft_write_diux(&parsed, va_arg(args, unsigned long));
	else if (parsed.type == 'p')
		ret = ft_write_p(&parsed, va_arg(args, void*));
	return (ret);
}
