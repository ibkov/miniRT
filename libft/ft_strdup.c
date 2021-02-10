/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:10:34 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/12 20:10:37 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*new_str;

	if (!s1)
		return (0);
	if (!(str = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	new_str = str;
	while (*s1)
		*str++ = *s1++;
	*str = '\0';
	return (new_str);
}
