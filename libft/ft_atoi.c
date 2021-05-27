/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 13:12:19 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	neg;
	int	res;

	count = 0;
	neg = 1;
	res = 0;
	while (str[count] == ' ' || str[count] == '\n' || str[count] == '\t'
		|| str[count] == '\v' || str[count] == '\f' || str[count] == '\r')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			neg = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		res = (res * 10) + (str[count] - '0');
		count++;
	}
	return (res * neg);
}
