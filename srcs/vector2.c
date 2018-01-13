/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:14:42 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/13 15:17:39 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	t_vector	n;
	float		len;

	len = vector_len(a);
	n.x = a.x / len;
	n.y = a.y / len;
	n.z = a.z / len;
	return (n);
}
