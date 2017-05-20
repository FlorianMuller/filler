/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 14:26:46 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/18 05:37:12 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

typedef	struct	s_file
{
	int				fd;
	char			buff[BUFF_SIZE + 1];
	struct s_file	*next;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
