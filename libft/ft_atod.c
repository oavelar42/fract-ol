/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 13:12:19 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	decimal_part(const char *str)
{
	double	dec;
	double	div;

	dec = 0.0;
	div = 0.1;
	while (ft_isdigit(*str))
	{
		dec += div * (*str - '0');
		div /= 10;
		str++;
	}
	return (dec);
}

double	ft_atod(const char *str)
{
	int		sign;
	double	num;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
	*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = 10 * num + *str - '0';
		str++;
	}
	if (*str == '.')
	{
		num += decimal_part(++str);
	}
	return ((double)(sign * num));
}
