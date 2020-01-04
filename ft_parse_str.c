/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:33:09 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 18:03:57 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_parse_str(const char *str, va_list args)
{
	int		i;
	char	*string;
	size_t	ret;

	ret = 0;
	while (*str)
	{
		i = (*str == '%') ? 1 : 0;
		while (str[i] && ((*str != '%' && str[i] != '%') ||
		(*str == '%' && !ft_is_type(str[i], TYPES))))
			i++;
		if (i > 0)
		{
			if (*str == '%' && ft_is_type(str[i], TYPES) && i++)
				ret += ft_put_parsed_str(ft_substr(str, 1, i - 1), args);
			else
			{
				string = ft_substr(str, 0, i);
				ret += ft_putstr(string);
				free(string);
			}
			str += i;
		}
	}
	return (ret);
}
