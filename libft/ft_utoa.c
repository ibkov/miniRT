/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:01:14 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/06 21:02:28 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_in_num_utoa(long num)
{
	int		i;

	i = 1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = count_in_num_utoa(num);
	if (n == 0)
		return (str = ft_strdup("0"));
	if (!(str = malloc(sizeof(char) * len)))
		return (0);
	len--;
	str[len] = '\0';
	while (num / 10 >= 1)
	{
		str[--len] = (num % 10) + 48;
		num /= 10;
	}
	str[0] = (num % 10) + 48;
	return (str);
}
