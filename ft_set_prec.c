/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 03:57:17 by dhaouhao          #+#    #+#             */
/*   Updated: 2019/12/26 02:46:44 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_set_prec(char *str, t_parse *parsed, va_list args)
{
	int	arg_value;

	parsed->is_prec = 1;
	if (ft_isdigit(*str))
	{
		parsed->prec = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	else if (*str == '*')
	{
		str++;
		arg_value = va_arg(args, int);
		parsed->prec = (arg_value >= 0) ? arg_value : 0;
		if (arg_value < 0)
			parsed->is_prec = 0;
	}
	if (parsed->is_0_filled && parsed->is_prec)
		parsed->is_0_filled = 0;
	return (str);
}
