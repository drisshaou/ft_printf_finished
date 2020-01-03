/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 04:41:15 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/01/03 16:20:48 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex_to_str(unsigned long long nbr)
{
	char	*hex;
	char	*base;
	int		nbr_final[20];
	int		len;
	int		i;

	base = "0123456789abcdef";
	len = (nbr == 0) ? 1 : 0;
	nbr_final[0] = 0;
	while (nbr)
	{
		nbr_final[len++] = nbr % 16;
		nbr /= 16;
	}
	if (!(hex = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (--len >= 0)
		hex[i++] = base[nbr_final[len]];
	hex[i] = '\0';
	return (hex);
}
