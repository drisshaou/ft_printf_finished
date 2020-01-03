/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 03:57:51 by dhaouhao          #+#    #+#             */
/*   Updated: 2019/12/29 03:49:35 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_set_width(char *str, t_parse *parsed, va_list args)
{
	int	arg_value;

	parsed->is_width = 1;
	if (ft_isdigit(*str))
	{
		parsed->width = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	else if (*str == '*')
	{
		str++;
		arg_value = va_arg(args, int);
		parsed->width = (arg_value >= 0) ? arg_value : -arg_value;
		if (arg_value < 0)
			parsed->is_left = 1;
	}
	if (str[ft_strlen(str) - 1] == 'p' || arg_value < 0)
		parsed->is_0_filled = 0;
	return (str);
}
