/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 05:03:23 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 19:15:26 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_p(t_parse *parsed, void *addr)
{
	char	*str;

	if (parsed->is_prec && parsed->is_width)
		str = ft_apply_prec_n_width_p(parsed, addr);
	else if (parsed->is_prec && !parsed->is_width)
		str = ft_apply_prec_p(parsed, addr);
	else
		str = ft_apply_width_p(parsed, addr);
	free(str);
	return (ft_putstr(str));
}
