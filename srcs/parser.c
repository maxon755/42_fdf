/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:01:57 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/13 09:05:38 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		fill_init_map(t_object *obj, t_list *head)
{
	int i;

	i = 0;
	while (head)
	{
		obj->vert.values[i][0] = ((t_node *)head->content)->x;
		obj->vert.values[i][1] = ((t_node *)head->content)->y;
		obj->vert.values[i][2] = ((t_node *)head->content)->z;
		obj->vert.values[i][3] = 1;
		obj->colors[i] = ((t_node *)head->content)->color;
		head = head->next;
		i++;
	}
}

static int		count_model_rows(t_list *head)
{
	int count;
	int temp;

	if (!head)
		return (0);
	count = 1;
	temp = ((t_node *)head->content)->y;
	while (head)
	{
		if (temp != ((t_node *)head->content)->y)
		{
			count++;
			temp = ((t_node *)head->content)->y;
		}
		head = head->next;
	}
	return (count);
}

static void		calculate_points(t_object *obj, t_list *head)
{
	int		i;
	int		temp;
	size_t	points;

	if (!head)
		return ;
	temp = ((t_node *)head->content)->y;
	head = head->next;
	points = 1;
	i = 0;
	while (head)
	{
		if (temp != ((t_node *)head->content)->y)
		{
			obj->p_in_row[i] = points;
			points = 0;
			temp = ((t_node *)head->content)->y;
			i++;
		}
		points++;
		head = head->next;
	}
	obj->p_in_row[i] = points;
}

t_object		parse_content(t_list *head)
{
	int			n_points;
	int			n_rows;
	t_object	obj;

	n_points = ft_lstlen(head);
	obj.vert.rows = n_points;
	if (obj.vert.rows == 0)
	{
		ft_putendl("No model. File is empty");
		exit(0);
	}
	obj.vert.cols = 4;
	obj.vert.values = create_matrix(obj.vert.rows,
										obj.vert.cols);
	obj.colors = (long long *)(malloc(sizeof(long long) * obj.vert.rows));
	fill_init_map(&obj, head);
	n_rows = count_model_rows(head);
	obj.p_in_row = (size_t *)(malloc(sizeof(size_t) * n_rows));
	calculate_points(&obj, head);
	ft_lst_erase(head);
	return (obj);
}
