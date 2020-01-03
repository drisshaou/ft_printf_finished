/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 06:43:32 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 19:21:28 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_struct(va_list args, t_parse *parsed, char *str)
{
	char	*tmp;

	tmp = str;
	ft_init_struct(parsed);
	while (*str)
	{
		str += (*str == '0' && *(str + 1) == '-') ? 1 : 0;
		if (*str == '-')
			parsed->is_left = 1;
		else if (*str == '0')
			parsed->is_0_filled = 1;
		str += (*str == '-' || *str == '0') ? 1 : 0;
		if (ft_isdigit(*str) || *str == '*')
			str = ft_set_width(str, parsed, args);
		if (*str == '.')
			str = ft_set_prec(++str, parsed, args);
		while (*str == 'l' || *str == 'h')
			str++;
		if (ft_is_type(*str, TYPES))
			parsed->type = *str;
		str++;
	}
	free(tmp);
}

void	ft_init_struct(t_parse *parsed)
{
	parsed->is_left = 0;
	parsed->is_0_filled = 0;
	parsed->is_width = 0;
	parsed->width = 0;
	parsed->is_prec = 0;
	parsed->prec = 0;
	parsed->type = 0;
}
