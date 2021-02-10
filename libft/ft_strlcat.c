/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:11:08 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/12 20:11:11 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;

	len_dst = 0;
	while (dst[len_dst] != '\0' && len_dst < dstsize)
		len_dst++;
	i = len_dst;
	while (src[len_dst - i] && len_dst + 1 < dstsize)
	{
		dst[len_dst] = src[len_dst - i];
		len_dst++;
	}
	if (i < dstsize)
		dst[len_dst] = '\0';
	return (i + ft_strlen(src));
}
