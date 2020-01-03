/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:29:35 by dhaouhao          #+#    #+#             */
/*   Updated: 2019/12/29 03:44:05 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s || !(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < ft_strlen(s))
		while (i < len && s[i + start])
		{
			substr[i] = s[i + start];
			i++;
		}
	substr[i] = '\0';
	return (substr);
}
