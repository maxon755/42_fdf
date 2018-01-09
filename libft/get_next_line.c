/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:03:55 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/12 13:08:14 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		fill_and_cut(char **line, char **buffer, char *line_end)
{
	size_t	len;
	char	*temp;

	len = line_end - *buffer;
	*line = ft_strnew(len);
	if (*line)
		ft_memcpy(*line, *buffer, len);
	temp = *buffer;
	if (*line_end == '\n')
		*buffer = ft_strdup(++line_end);
	else
		*buffer = ft_strdup(line_end);
	ft_strdel(&temp);
}

static int		read_source(const int fd, char **buffer)
{
	int		bytes;
	char	*temp;
	char	*temp2;

	temp = ft_strnew(BUFF_SIZE);
	temp2 = *buffer;
	if ((bytes = read(fd, temp, BUFF_SIZE)) == -1)
		return (ERROR);
	*buffer = ft_strjoin(*buffer, temp);
	ft_strdel(&temp);
	ft_strdel(&temp2);
	return (bytes);
}

static int		fetch_line(const int fd, char **buffer, char **line, int bytes)
{
	char	*line_end;

	line_end = NULL;
	if (!(line_end = ft_strchr(*buffer, '\n')) && bytes > 0)
	{
		bytes = read_source(fd, buffer);
		return (fetch_line(fd, buffer, line, bytes));
	}
	if ((bytes > 0 && line_end) || (!bytes && ft_strlen(*buffer)))
	{
		if (!line_end)
			line_end = *buffer + ft_strlen(*buffer);
		fill_and_cut(line, buffer, line_end);
		return (1);
	}
	if (bytes == -1)
		return (ERROR);
	fill_and_cut(line, buffer, *buffer);
	return (FILE_END);
}

t_list			*get_file(const int fd, t_list *head)
{
	t_list *temp;

	while (head)
	{
		if (head->content_size == (size_t)fd)
			return (head);
		temp = head;
		head = head->next;
	}
	ft_lstadd_back(temp, ft_lstnew(ft_strnew(BUFF_SIZE), fd));
	temp = temp->next;
	temp->content_size = fd;
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*file;
	char			*temp;

	if (fd < 0)
		return (ERROR);
	if (!head)
	{
		temp = ft_strnew(BUFF_SIZE);
		head = ft_lstnew(temp, BUFF_SIZE);
		head->content_size = fd;
		file = head;
		ft_strdel(&temp);
	}
	else
		file = get_file(fd, head);
	return (fetch_line(fd, (char **)&(file->content), line, 1));
}
