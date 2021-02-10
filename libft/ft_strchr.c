/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:19:16 by burswyck          #+#    #+#             */
/*   Updated: 2020/10/28 19:22:22 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	while (*string != symbol && *string)
	{
		string++;
	}
	if (symbol == '\0')
		return ((char*)string);
	if (*string == '\0')
		return (0);
	return ((char*)string);
}
