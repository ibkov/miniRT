/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:07:57 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/12 20:08:01 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *restrict dst,\
const void *restrict src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	if (!dst && !src)
		return (0);
	i = 0;
	d = (char*)dst;
	s = (const char*)src;
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dst);
}
