/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:38:15 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/10 12:08:07 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/vector.h"
#include "../includes/fdf.h"

t_vector	get_vector(float x, float y, float z)
{
	t_vector v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 0;
	return (v);
}

t_vector	subtraction(t_vector a, t_vector b)
{
	t_vector c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vector	cross_production(t_vector a, t_vector b)
{
	t_vector c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;

	return (c);
}

t_vector	k_mult(t_vector a, float k)
{
	t_vector b;

	b.x = a.x * k;
	b.y = a.y * k;
	b.z = a.z * k;
	return (b);
}
float		vector_len(t_vector a)
{
	return (pow(a.x * a.x + a.y * a.y + a.z * a.z, 0.5));
}

t_vector	normalization(t_vector a)
{
	t_vector n;
	float len;

	len = vector_len(a);;
	n.x = a.x / len;
	n.y = a.y / len;
	n.z = a.z / len;
	return (n);
}

void		print_vector(t_vector a)
{
	printf("Vector\nx: %.3f\ny: %.3f\nz: %.3f\nw: %.3f\n", a.x, a.y, a.z, a.w);
}
