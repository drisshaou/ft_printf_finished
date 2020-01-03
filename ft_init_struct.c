/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:22:16 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/02 02:18:27 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_parse *parsed)
{
	parsed->is_left = 0;
	parsed->is_0_filled = 0;
	parsed->is_width = 0;
	parsed->width = 0;
	parsed->is_prec = 0;
	parsed->prec = 0;
	parsed->type = 0;
	parsed->str = NULL;
}
