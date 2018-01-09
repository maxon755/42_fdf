/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 09:37:23 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/09 10:18:38 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reader.h"

static void		z_and_color(t_node *node, char *str)
{
	char **temp;

	if (ft_strchr(str, ','))
	{
		temp = ft_strsplit(str, ',');
		node->z = ft_atoi(temp[0]);
		node->color = ft_atoi16(temp[1]);
		ft_clear_strarr(&temp);
	}
	else
	{
		node->z = ft_atoi(str);
		node->color = 0xffffff;
	}
}

static void		fill_list(t_list **head, t_list **tail, char *line, size_t row)
{
	t_node		node;
	char		**arr;
	size_t		i;

	arr = ft_strsplit(line, ' ');
	i = 0;
	while (arr[i])
	{
		node.x = i;
		node.y = row;
		z_and_color(&node, arr[i]);
		if (!(*head))
		{
			*head = ft_lstnew(&node, sizeof(node));
			*tail = *head;
		}
		else
			*tail = ft_lstadd_back(*tail, ft_lstnew(&node, sizeof(node)));
		i++;
	}
	ft_clear_strarr(&arr);
}

static t_list	*read_file(int fd)
{
	t_list	*head;
	t_list	*tail;
	char	*line;
	size_t	row;

	row = 0;
	head = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		fill_list(&head, &tail, line, row);
		row++;
		ft_strdel(&line);
	}
	return (head);
}

t_list			*get_content(char *filename)
{
	t_list		*head;
	int			fd;

	fd = open(filename, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_putendl("File doesn`t exist");
		exit(1);
	}
	head = read_file(fd);
	close(fd);
	return (head);
}
