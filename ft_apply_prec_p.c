/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_prec_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 05:03:23 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 19:47:10 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_prec_p(t_parse *parsed, void *addr)
{
	char		*tmp;
	size_t		size;
	intptr_t	val;

	val = (addr == NULL) ? 0 : (intptr_t)addr;
	tmp = ft_hex_to_str((unsigned long long)val);
	size = ft_strlen(tmp);
	size = (parsed->prec > size) ? parsed->prec + 2 : size + 2;
	size = (parsed->prec == 0 && val == 0) ? 2 : size;
	return (ft_return_prec_p(size, tmp));
}

char	*ft_return_prec_p(size_t sz, char *tmp)
{
	char	*str;
	size_t	ln;

	if (!(str = malloc(sizeof(char) * (sz + 1))))
		return (NULL);
	ln = sz - ft_strlen(tmp);
	ft_memset(str, '0', sz);
	ft_memcpy(str, "0x", 2);
	if (sz > 2)
		ft_memcpy(str + ln, tmp, ft_strlen(tmp));
	str[sz] = '\0';
	free(tmp);
	return (str);
}
