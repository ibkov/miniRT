/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burswyck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:11:11 by burswyck          #+#    #+#             */
/*   Updated: 2020/11/12 20:05:24 by burswyck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_intlen(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
		return (11);
	if (num > 0)
		while (num > 0)
		{
			num /= 10;
			count++;
		}
	else if (num == 0)
		return (1);
	else
	{
		num = num * -1;
		while (num > 0)
		{
			num /= 10;
			count++;
		}
		count++;
	}
	return (count);
}

char		*collect_str(int n, char *str_num, int i)
{
	while (n > 0)
	{
		str_num[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str_num);
}

char		*ft_itoa(int n)
{
	char	*str_num;
	int		i;

	i = ft_intlen(n);
	if (!(str_num = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	str_num[i--] = '\0';
	if (n == -2147483648)
	{
		str_num[i--] = '8';
		n = -214748364;
	}
	if (n == 0)
	{
		str_num[i] = '0';
		return (str_num);
	}
	if (n < 0)
	{
		str_num[0] = '-';
		n = -n;
	}
	return (collect_str(n, str_num, i));
}
