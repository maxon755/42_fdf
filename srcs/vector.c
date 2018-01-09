/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:38:15 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/09 16:27:42 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/vector.h"
#include "../includes/fdf.h"

t_vector	cross_production(t_vector a, t_vector b)
{
	t_vector c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;

	return (c);
}

t_vector	normalization(t_vector a)
{
	t_vector n;
	float len;

	len = pow(a.x * a.x + a.y * a.y + a.z * a.z, 0.5);
	n.x = a.x / len;
	n.y = a.y / len;
	n.z = a.z / len;
	return (n);
}

void		print_vector(t_vector a)
{
	printf("Vector\nx: %.3f\ny: %.3f\nz: %.3f\nw: %.3f\n", a.x, a.y, a.z, a.w);
}
