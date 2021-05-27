/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:17:00 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:41:59 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	*leak(char **ptr, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static char	**fill(char const *s, int words, char c, char **ptr)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = ft_wordlen(s, c);
		ptr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!(ptr[i]))
			return (leak(ptr, i));
		j = 0;
		while (j < len)
			ptr[i][j++] = *s++;
		ptr[i][j] = '\0';
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char	const *s, char c)
{
	char	**ptr;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count(s, c);
	ptr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!(ptr))
		return (NULL);
	ptr = fill(s, words, c, ptr);
	return (ptr);
}
