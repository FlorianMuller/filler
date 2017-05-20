/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:17:38 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/19 16:09:12 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#	include <fcntl.h>

static int	ft_find_file(t_file **lst, t_file **new, int fd)
{
	int	ret;

	*new = *lst;
	ret = 1;
	while (*new != NULL && (*new)->fd != fd)
		*new = (*new)->next;
	if (*new == NULL)
	{
		if ((*new = (t_file *)ft_memalloc(sizeof(t_file))) == NULL)
			return (-1);
		ft_bzero((*new)->buff, BUFF_SIZE + 1);
		if ((ret = read(fd, (*new)->buff, BUFF_SIZE)) == -1)
			return (-1);
		if (!ret)
		{
			ft_memdel((void **)new);
			return (0);
		}
		(*new)->fd = fd;
		(*new)->next = *lst;
		*lst = *new;
	}
	return (ret);
}

static int	ft_read_line(char **line, t_file *file, int fd)
{
	int		ret;
	char	*end;
	int		buff_len;

	end = ft_strchr(file->buff, '\n');
	buff_len = (end) ? end - file->buff : ft_strlen(file->buff);
	if ((*line = ft_realloc(*line, ((*line == NULL) ? 0 : ft_strlen(*line))
		+ buff_len + 1)) == NULL)
		return (-1);
	ft_strncat(*line, file->buff, buff_len);
	if (end != NULL)
	{
		ft_memmove(file->buff, end + 1, ft_strlen(end));
		ft_strclr(file->buff + ft_strlen(file->buff) + 1);
		ret = 1;
	}
	else
	{
		ft_strclr(file->buff);
		if ((ret = read(fd, file->buff, BUFF_SIZE)) == -1)
			return (-1);
	}
	return (ret);
}

static int	ft_end(int ret, char **line, t_file **file, t_file **lst)
{
	t_file *f;

	f = *lst;
	if (ret == 0 && *line[0] == '\0')
	{
		ft_memdel((void **)line);
		if (*lst == *file)
			*lst = (*file)->next;
		else
		{
			while (f->next != *file)
				f = f->next;
			f->next = (*file)->next;
		}
		ft_memdel((void **)file);
		return (0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_file	*lst = NULL;
	t_file			*file;
	int				ret;

	if (line == NULL)
		return (-1);
	*line = NULL;
	if ((ret = ft_find_file(&lst, &file, fd)) < 1)
		return ((ret == 0) ? 0 : -1);
	while (!(ft_strchr(file->buff, '\n')) && ret)
	{
		if ((ret = ft_read_line(line, file, fd)) == -1)
			return (-1);
		if (!ft_end(ret, line, &file, &lst))
			return (0);
	}
	if (!ret)
		return (1);
	if ((ret = ft_read_line(line, file, fd)) == -1)
		return (-1);
	return (1);
}
