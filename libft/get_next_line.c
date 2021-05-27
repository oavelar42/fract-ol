/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:30:45 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 15:16:35 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ret(char **line, char **next, char *aux_ptr)
{
	char			*aux;

	if (aux_ptr)
	{
		*line = ft_strndup(*next, aux_ptr - *next);
		aux = ft_strndup(aux_ptr + 1, ft_strlen(aux_ptr + 1));
		free(*next);
		*next = aux;
		return (1);
	}
	if (*next)
	{
		*line = *next;
		*next = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*next[OPEN_MAX];
	char			ptr[BUFFER_SIZE + 1];
	char			*aux_ptr;
	int				b;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, ptr, 0) < 0)
		return (-1);
	if (!next[fd])
		next[fd] = ft_strndup("", 1);
	while (!(aux_ptr = ft_strchr(next[fd], '\n'))
			&& ((b = read(fd, ptr, BUFFER_SIZE)) > 0))
	{
		ptr[b] = 0;
		if (next[fd])
			aux_ptr = ft_strjoin(next[fd], ptr);
		else
			aux_ptr = ft_strndup(ptr, b);
		if (next[fd])
			free(next[fd]);
		next[fd] = aux_ptr;
	}
	return (ft_ret(line, &next[fd], aux_ptr));
}
