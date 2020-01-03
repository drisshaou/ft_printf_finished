/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:58:42 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 12:22:18 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_precision_s(t_parse *parsed, char *tmp)
{
	char	*str;
	char	*new_str;

	new_str = (tmp == NULL) ? ft_strdup("(null)") : ft_strdup(tmp);
	if (parsed->is_prec && parsed->prec < ft_strlen(new_str))
		str = ft_substr(new_str, 0, parsed->prec);
	else
		str = ft_strdup(new_str);
	free(new_str);
	return (str);
}
