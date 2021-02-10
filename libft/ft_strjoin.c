/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:32:14 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/06 21:39:10 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	int		len_all_str;

	if (!s1 || !s2)
		return (0);
	len_all_str = ft_strlen(s1) + ft_strlen(s2);
	if (!(str_joined = malloc(sizeof(str_joined) * (len_all_str) + 1)))
		return (0);
	while (*s1)
		*str_joined++ = *s1++;
	while (*s2)
		*str_joined++ = *s2++;
	*str_joined = '\0';
	return (str_joined - len_all_str);
}
