/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:31:45 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 12:34:38 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;

	if (!str)
		return (0);
	ret = 0;
	va_start(args, str);
	ret = (int)ft_parse_str(str, args);
	va_end(args);
	return (ret);
}
