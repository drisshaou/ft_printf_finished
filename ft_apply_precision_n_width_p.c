/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision_n_width_p.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 05:03:23 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 16:37:30 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_precision_n_width_p(t_parse *parsed, void *addr)
{
	char	*tmp;
	size_t	len;
	size_t	size;
	char	*str;

	tmp = ft_apply_precision_p(parsed, addr);
	len = ft_strlen(tmp);
	size = (parsed->width > len && parsed->width > 0) ? parsed->width : len;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(str, ' ', size);
	if (parsed->is_left)
		ft_memcpy(str, tmp, len);
	else
		ft_memcpy(str + (size - len), tmp, len);
	str[size] = '\0';
	free(tmp);
	return (str);
}
