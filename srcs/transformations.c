/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 08:48:58 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/16 11:17:18 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix	translate(t_matrix a, float x, float y, float z)
{
	t_matrix	t;

	t = get_translation_matrix(x, y, z);
	a = mult_matrix_f(a, t);
	free_matrix(t);
	return (a);
}

t_matrix	scale(t_matrix a, float x, float y, float z)
{
	t_matrix	s;
	t_matrix	t;
	t_matrix	t_b;
	t_vector	c;

	c = get_center(a);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	t_b = get_translation_matrix(c.x, c.y, c.z);
	s = get_scale_matrix(x, y, z);
	t = mult_matrix_f(t, s);
	t = mult_matrix_f(t, t_b);
	a = mult_matrix_f(a, t);
	free_matrix(s);
	free_matrix(t);
	free_matrix(t_b);
	return (a);
}

t_matrix	rotate_about_x_center(t_matrix a, float x)
{
	t_matrix rx;
	t_matrix t;
	t_matrix t_b;
	t_vector c;

	c = get_center(a);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	t_b = get_translation_matrix(c.x, c.y, c.z);
	rx = get_x_rot_matrix(x);
	t = mult_matrix_f(t, rx);
	t = mult_matrix_f(t, t_b);
	a = mult_matrix_f(a, t);
	free_matrix(rx);
	free_matrix(t);
	free_matrix(t_b);
	return (a);
}

t_matrix	rotate_about_y_center(t_matrix a, float y)
{
	t_matrix ry;
	t_matrix t;
	t_matrix t_b;
	t_vector c;

	c = get_center(a);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	t_b = get_translation_matrix(c.x, c.y, c.z);
	ry = get_y_rot_matrix(y);
	t = mult_matrix_f(t, ry);
	t = mult_matrix_f(t, t_b);
	a = mult_matrix_f(a, t);
	free_matrix(ry);
	free_matrix(t);
	free_matrix(t_b);
	return (a);
}

t_matrix	rotate_about_z_center(t_matrix a, float z)
{
	t_matrix rz;
	t_matrix t;
	t_matrix t_b;
	t_vector c;

	c = get_center(a);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	t_b = get_translation_matrix(c.x, c.y, c.z);
	rz = get_z_rot_matrix(z);
	t = mult_matrix_f(t, rz);
	t = mult_matrix_f(t, t_b);
	a = mult_matrix_f(a, t);
	free_matrix(rz);
	free_matrix(t);
	free_matrix(t_b);
	return (a);
}
