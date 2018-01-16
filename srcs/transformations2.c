/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:15:49 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/16 11:20:11 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"

t_matrix	rotate_about_x(t_matrix a, float x)
{
	t_matrix rx;

	rx = get_x_rot_matrix(x);
	a = mult_matrix_f(a, rx);
	free_matrix(rx);
	return (a);
}

t_matrix	rotate_about_y(t_matrix a, float y)
{
	t_matrix ry;

	ry = get_y_rot_matrix(y);
	a = mult_matrix_f(a, ry);
	free_matrix(ry);
	return (a);
}

t_matrix	rotate_about_z(t_matrix a, float z)
{
	t_matrix rz;

	rz = get_z_rot_matrix(z);
	a = mult_matrix_f(a, rz);
	free_matrix(rz);
	return (a);
}
