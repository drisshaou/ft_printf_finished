/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 06:43:32 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/02 05:58:21 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_struct(va_list args, t_parse *parsed, char *str)
{
	char	*tmp;

	tmp = str;
	ft_init_struct(parsed);
	//parsed->str = ft_strjoin("%", tmp);
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
	// if (!ft_is_type(*str, "csdiuxXp%"))
	// 	parsed->str = ft_strjoin("%", tmp);
	free(tmp);
}
