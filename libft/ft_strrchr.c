/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:12:55 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/12 20:12:58 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		position_last;
	char	*new_str;

	new_str = (char*)s;
	position_last = -1;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			position_last = index;
		index++;
	}
	if (c == '\0')
		return (new_str + index);
	new_str += position_last;
	if (position_last == -1)
		return (0);
	return (new_str);
}
