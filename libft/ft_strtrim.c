/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:13:31 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/06 21:51:38 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findchr(const char *s, int symbol)
{
	if (symbol != '\0')
		while (*s)
			if (*s++ == symbol)
				return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	begin_index;
	unsigned int	end_index;
	char			*new_str;
	int				i;

	if (!s1)
		return (0);
	i = 0;
	begin_index = 0;
	end_index = ft_strlen(s1) - 1;
	if (!*set || !*s1)
		return ((char*)s1);
	while (ft_findchr(set, s1[begin_index]))
		begin_index++;
	while (ft_findchr(set, s1[end_index]) && end_index > 0)
		end_index--;
	if (!(new_str = (char*)malloc(sizeof(*new_str)\
				* (end_index - begin_index) + 2)))
		return (0);
	while (end_index >= begin_index)
		new_str[i++] = s1[begin_index++];
	new_str[i] = '\0';
	return (new_str);
}
