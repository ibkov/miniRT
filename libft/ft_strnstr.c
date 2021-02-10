/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:12:37 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/12 20:12:39 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			len_l;

	if (!haystack)
		ft_strlen(haystack);
	i = 0;
	len_l = ft_strlen(needle);
	while (haystack)
	{
		if (i + len_l > len)
			return (0);
		if (!(ft_strncmp(haystack, needle, len_l)))
			return (char*)(haystack);
		haystack++;
		i++;
	}
	return (0);
}
