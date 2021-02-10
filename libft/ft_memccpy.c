/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:04:12 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/06 21:05:11 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,\
int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	chr;
	size_t			i;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	chr = (unsigned char)c;
	while (n > i)
	{
		d[i] = s[i];
		if (s[i] == chr)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (0);
}
