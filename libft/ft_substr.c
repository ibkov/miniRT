/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:08:29 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/06 21:29:34 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s,\
unsigned int start, size_t len)
{
	unsigned char	*str;
	char			*str_copy;
	int				temp_len;

	if (!s)
		return (0);
	if (start >= (unsigned int)len)
	{
		if (!(str_copy = (char*)malloc(sizeof(char) * 1)))
			return (0);
		str_copy[0] = '\0';
		return (str_copy);
	}
	temp_len = len;
	str = (unsigned char*)s;
	str += start;
	if (!(str_copy = malloc(sizeof(char) * len + 1)))
		return (0);
	while (*str && len--)
		*str_copy++ = *str++;
	*str_copy = '\0';
	return (str_copy - temp_len);
}
