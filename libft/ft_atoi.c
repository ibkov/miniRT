/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:01:14 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/06 21:02:28 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			minus_in_num;
	long long	number;

	minus_in_num = 0;
	number = 0;
	while ((*str >= 7 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		minus_in_num = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		number = number * 10 + (*str - 48);
		str++;
	}
	if ((number > (number * 10)) && minus_in_num)
		return (0);
	if (number > (number * 10))
		return (-1);
	if (minus_in_num)
		return ((int)number * -1);
	return ((int)number);
}
