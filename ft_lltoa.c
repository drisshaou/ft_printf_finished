/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 01:12:22 by dhaouhao          #+#    #+#             */
/*   Updated: 2019/12/25 01:24:19 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getllsize(unsigned long long n, int sign)
{
	unsigned int i;

	i = 0;
	while ((n / 10) > 0)
	{
		i++;
		n /= 10;
	}
	i += (sign < 0) ? 1 : 0;
	return (i + 1);
}

char	*ft_lltoa(long long n)
{
	char				*str;
	int					size;
	int					sign;
	unsigned long long	nbr;

	sign = (n < 0) ? -1 : 1;
	nbr = (unsigned long long)(sign < 0 ? -n : n);
	size = ft_getllsize(nbr, sign);
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = (size == 0 && sign == -1) ? '-' : nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
