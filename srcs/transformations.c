/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 08:48:58 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/09 11:30:48 by mgayduk          ###   ########.fr       */
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

t_matrix	scale(t_matrix a, float x, float y, float z)
{
	t_matrix	s;
	t_matrix	t;
	t_matrix	t_b;
	t_matrix	temp;
	t_vector	c;

	c = get_center(a);
	printf("center of model:\nx: %f\ny: %f\nz: %f\n", c.x, c.y, c.z);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	ft_putendl("translation to center");
	print_matrix(t);
	t_b = get_translation_matrix(c.x, c.y, c.z);
	ft_putendl("translation back");
    print_matrix(t_b);
	//print_matrix(t_b);
	s = get_scale_matrix(x, y, z);
	//print_matrix(s);
	temp = t;
	t = mult_matrix(t, s);
	//print_matrix(t);
	free_matrix(temp);
	temp = t;
	t = mult_matrix(t, t_b);
	//print_matrix(t);
	free_matrix(temp);
	temp = a;
	a = mult_matrix(a, t);
	print_matrix(a);
	free_matrix(s);
	free_matrix(t);
	free_matrix(t_b);
	free_matrix(temp);
	return (a);
}

t_matrix		rotate_about_x_center(t_matrix a, float x)
{
	t_matrix rx;
	t_matrix t;
	t_matrix t_b;
	t_matrix temp;
	t_vector c;

	temp = a;
	c = get_center(a);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	t_b = get_translation_matrix(c.x, c.y, c.z);
	rx = get_x_rot_matrix(x);
	t = mult_matrix(t, rx);
	t = mult_matrix(t, t_b);
	a = mult_matrix(a, t);
	free_matrix(rx);
	free_matrix(t);
	free_matrix(t_b);
	free_matrix(temp);
	return (a);
}

t_matrix		rotate_about_y_center(t_matrix a, float y)
{
	t_matrix ry;
	t_matrix t;
	t_matrix t_b;
	t_matrix temp;
	t_vector c;

	temp = a;
	c = get_center(a);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	t_b = get_translation_matrix(c.x, c.y, c.z);
	ry = get_y_rot_matrix(y);
	t = mult_matrix(t, ry);
	t = mult_matrix(t, t_b);
	a = mult_matrix(a, t);
	free_matrix(ry);
	free_matrix(t);
	free_matrix(t_b);
	free_matrix(temp);
	return (a);
}

t_matrix		rotate_about_z_center(t_matrix a, float z)
{
	t_matrix rz;
	t_matrix t;
	t_matrix t_b;
	t_matrix temp;
	t_vector c;

	temp = a;
	c = get_center(a);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	t_b = get_translation_matrix(c.x, c.y, c.z);
	rz = get_z_rot_matrix(z);
	t = mult_matrix(t, rz);
	t = mult_matrix(t, t_b);
	a = mult_matrix(a, t);
	free_matrix(rz);
	free_matrix(t);
	free_matrix(t_b);
	free_matrix(temp);
	return (a);
}
/*
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
*/
