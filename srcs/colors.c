/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:35:23 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/06 14:34:37 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	paint_red_blue(t_env *env)
{
	size_t		i;
	t_vector	c;
	int			mid_z;

	c = get_center(env->init_map);
	mid_z = -c.w;
	i = 0;
	while (i < env->init_map.rows)
	{
		if (env->init_map.values[i][2] > mid_z)
			env->colors[i] = 0x0000aa;
		else
			env->colors[i] = 0xff0000;
		i++;
	}
	return (0);
}

int	paint_green(t_env *env)
{
	size_t		i;
	t_vector	c;
	int			mid_z;

	c = get_center(env->init_map);
	mid_z = -c.w;
	i = 0;
	while (i < env->init_map.rows)
	{
		if (env->init_map.values[i][2] > mid_z)
			env->colors[i] = 0x00aa00;
		else
			env->colors[i] = 0x00ff00;
		i++;
	}
	return (0);
}

int	paint_blue(t_env *env)
{
	size_t		i;
	t_vector	c;
	int			mid_z;

	c = get_center(env->init_map);
	mid_z = -c.w;
	i = 0;
	while (i < env->init_map.rows)
	{
		if (env->init_map.values[i][2] > mid_z)
			env->colors[i] = 0x0000aa;
		else
			env->colors[i] = 0x0000ff;
		i++;
	}
	return (0);
}

int	paint_red(t_env *env)
{
	size_t		i;
	t_vector	c;
	int			mid_z;

	c = get_center(env->init_map);
	mid_z = -c.w;
	i = 0;
	while (i < env->init_map.rows)
	{
		if (env->init_map.values[i][2] > mid_z)
			env->colors[i] = 0xaa0000;
		else
			env->colors[i] = 0xff0000;
		i++;
	}
	return (0);
}

int	colors(int keycode, t_env *env)
{
	if (keycode == 18)
		paint_red_blue(env);
	if (keycode == 19)
		paint_green(env);
	if (keycode == 20)
		paint_blue(env);
	if (keycode == 21)
		paint_red(env);
	return (0);
}
