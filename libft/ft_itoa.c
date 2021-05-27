/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:17:00 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:41:59 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	get_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n != 0)
	{
		++count;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		count;

	count = get_len(n);
	res = malloc(sizeof(char) * (count + 1));
	if (res == NULL)
		return (NULL);
	res[count] = '\0';
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		--count;
		res[count] = get_size(n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
