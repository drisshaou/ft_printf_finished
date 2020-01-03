/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:16:43 by dhaouhao          #+#    #+#             */
/*   Updated: 2019/12/24 02:02:50 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cur;

	cur = (unsigned char *)b;
	while (len-- > 0)
		*(cur++) = (unsigned char)c;
	return (b);
}
