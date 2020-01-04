/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 05:03:23 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 19:46:49 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_width_p(t_parse *parsed, void *addr)
{
	char		*tmp;
	size_t		size;
	intptr_t	val;

	val = (addr == NULL) ? 0 : (intptr_t)addr;
	tmp = ft_hex_to_str(val, "0123456789abcdef");
	size = ft_strlen(tmp) + 2;
	size = (parsed->is_width && parsed->width > size) ? parsed->width : size;
	return (ft_return_width_p(parsed, size, tmp));
}

char	*ft_return_width_p(t_parse *parsed, size_t sz, char *tmp)
{
	char	*str;
	size_t	ln;

	ln = sz - ft_strlen(tmp);
	if (!(str = malloc(sizeof(char) * (sz + 1))))
		return (NULL);
	if (parsed->is_0_filled)
		ft_memset(str, '0', sz);
	else
		ft_memset(str, ' ', sz);
	if (parsed->is_left)
	{
		ft_memcpy(str, "0x", 2);
		ft_memcpy(str + 2, tmp, ft_strlen(tmp));
	}
	else if (!parsed->is_left)
	{
		ft_memcpy(str + (ln - 2), "0x", 2);
		ft_memcpy(str + ln, tmp, ft_strlen(tmp));
	}
	str[sz] = '\0';
	free(tmp);
	return (str);
}
