/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:35:23 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/13 11:45:06 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	change_color(t_env *env, long long a, long long b)
{
	size_t		i;
	t_vector	c;
	int			mid_z;

	c = get_center(env->obj.vert);
	mid_z = c.w;
	i = 0;
	while (i < env->obj.vert.rows)
	{
		if (env->obj.vert.values[i][2] < mid_z)
			env->obj.colors[i] = a;
		else
			env->obj.colors[i] = b;
		i++;
	}
	return (0);
}

int	colors(int keycode, t_env *env)
{
	if (keycode == 18)
		change_color(env, 0x000099, 0xff0000);
	if (keycode == 19)
		change_color(env, 0x009900, 0x00ff00);
	if (keycode == 20)
		change_color(env, 0x000099, 0x0000ff);
	if (keycode == 21)
		change_color(env, 0x990000, 0xff0000);
	return (0);
}
