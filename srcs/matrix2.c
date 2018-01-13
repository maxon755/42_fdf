/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:43:18 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/13 09:00:43 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"
#include <math.h>

t_matrix	get_translation_matrix(float x, float y, float z)
{
	t_matrix t;

	t.rows = 4;
	t.cols = 4;
	t.values = create_matrix(t.rows, t.cols);
	t.values[0][0] = 1;
	t.values[1][1] = 1;
	t.values[2][2] = 1;
	t.values[3][0] = x;
	t.values[3][1] = y;
	t.values[3][2] = z;
	t.values[3][3] = 1;
	return (t);
}

t_matrix	get_scale_matrix(float x, float y, float z)
{
	t_matrix	s;

	s.rows = 4;
	s.cols = 4;
	s.values = create_matrix(s.rows, s.cols);
	s.values[0][0] = x;
	s.values[1][1] = y;
	s.values[2][2] = z;
	s.values[3][3] = 1;
	return (s);
}

t_matrix	get_x_rot_matrix(float x_angle)
{
	t_matrix	rx;

	rx.rows = 4;
	rx.cols = 4;
	rx.values = create_matrix(rx.rows, rx.cols);
	rx.values[1][1] = cos(x_angle);
	rx.values[1][2] = sin(x_angle);
	rx.values[2][1] = -sin(x_angle);
	rx.values[2][2] = cos(x_angle);
	rx.values[0][0] = 1;
	rx.values[3][3] = 1;
	return (rx);
}

t_matrix	get_y_rot_matrix(float y_angle)
{
	t_matrix	ry;

	ry.rows = 4;
	ry.cols = 4;
	ry.values = create_matrix(ry.rows, ry.cols);
	ry.values[0][0] = cos(y_angle);
	ry.values[0][2] = -sin(y_angle);
	ry.values[2][0] = sin(y_angle);
	ry.values[2][2] = cos(y_angle);
	ry.values[1][1] = 1;
	ry.values[3][3] = 1;
	return (ry);
}

t_matrix	get_z_rot_matrix(float z_angle)
{
	t_matrix	rz;

	rz.rows = 4;
	rz.cols = 4;
	rz.values = create_matrix(rz.rows, rz.cols);
	rz.values[0][0] = cos(z_angle);
	rz.values[0][1] = sin(z_angle);
	rz.values[1][0] = -sin(z_angle);
	rz.values[1][1] = cos(z_angle);
	rz.values[2][2] = 1;
	rz.values[3][3] = 1;
	return (rz);
}
