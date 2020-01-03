/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_diux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:29:06 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/02 02:25:04 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_diux(t_parse *parsed, long long value)
{
	char	*str;

	if (parsed->is_prec && parsed->is_width)
		str = ft_apply_prec_n_width_diux(parsed, value);
	else if (parsed->is_prec && !parsed->is_width)
		str = ft_apply_prec_diux(parsed, value);
	else
		str = ft_apply_width_diux(parsed, value);
	free(str);
	return (ft_putstr(str));
}
