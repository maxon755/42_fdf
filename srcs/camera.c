/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 08:52:55 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/10 12:11:19 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_matrix	get_look_matrix(t_vector e, t_vector f, t_vector r, t_vector u)
{
	t_matrix m;

	m.rows = 4;
	m.cols = 4;
	m.values = create_matrix(m.rows, m.cols);
	m.values[0][0] = r.x; 
	m.values[1][0] = r.y;
	m.values[2][0] = r.z;
	m.values[0][1] = u.x;
	m.values[1][1] = u.y;
	m.values[2][1] = u.z;
	m.values[0][2] = f.x;
	m.values[1][2] = f.y;
	m.values[2][2] = f.z;
	m.values[3][0] = -e.x * r.x - e.y * r.y - e.z * r.z;
	m.values[3][1] = -e.x * u.x - e.y * u.y - e.z * u.z;
	m.values[3][2] = -e.x * f.x - e.y * f.y - e.z * f.z;
	m.values[3][3] = 1;
	return (m);
}

t_matrix	look_at(t_vector eye, t_vector target, t_vector up_dir)
{
	t_vector forward;
	t_vector right;
	t_vector up;
	t_matrix m;

	forward = subtraction(eye, target);
	//forward = k_mult(forward, -1);
	forward = normalization(forward);
	ft_putendl("forward vector");
	print_vector(forward);
	right  = cross_production(up_dir, forward);
	right = normalization(right);
	ft_putendl("right vector");
    print_vector(right);
	up = cross_production(forward, right);
	up = normalization(up);
    ft_putendl("up vector");
	print_vector(up);
	m = get_look_matrix(eye, forward, right, up);
	return (m);
}
