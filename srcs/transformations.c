/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 08:48:58 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/06 14:41:47 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix	translate(t_matrix a, float x, float y, float z)
{
	t_matrix	t;
	t_matrix	temp;

	temp = a;
	t = get_translation_matrix(x, y, z);
	a = mult_matrix(a, t);
	free_matrix(t);
	free_matrix(temp);
	return (a);
}

int				scale(t_env *env, float x, float y, float z)
{
	t_matrix	t;
	t_matrix	t_b;
	t_matrix	s;
	t_vector	c;

	c = get_center(env->map);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	t_b = get_translation_matrix(c.x, c.y, c.z);
	s = get_scale_matrix(x, y, z);
	t = mult_matrix(t, s);
	t = mult_matrix(t, t_b);
	env->map = mult_matrix(env->map, t);
	free_matrix(t);
	return (0);
}

static t_matrix	get_rotation_matrix(float x, float y, float z)
{
	t_matrix rx;
	t_matrix ry;
	t_matrix rz;

	rx = get_x_rot_matrix(x);
	ry = get_y_rot_matrix(y);
	rz = get_z_rot_matrix(z);
	rx = mult_matrix(rx, ry);
	rx = mult_matrix(rx, rz);
	return (rx);
}

int				rotate(t_env *env, float x_angle, float y_angle, float z_angle)
{
	t_matrix	t;
	t_matrix	t_b;
	t_matrix	r;
	t_vector	c;

	c = get_center(env->map);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	t_b = get_translation_matrix(c.x, c.y, c.z);
	r = get_rotation_matrix(x_angle, y_angle, z_angle);
	t = mult_matrix(t, r);
	t = mult_matrix(t, t_b);
	env->map = mult_matrix(env->map, t);
	free_matrix(t);
	return (0);
}
