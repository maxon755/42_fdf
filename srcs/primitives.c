/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:34:40 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/06 09:01:42 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>

static void			init_vars(t_point *delta, t_point *sign,
								t_point s, t_point e)
{
	delta->x = abs(e.x - s.x);
	delta->y = abs(e.y - s.y);
	sign->x = s.x < e.x ? 1 : -1;
	sign->y = s.y < e.y ? 1 : -1;
}

static long long	get_color(t_env *env, size_t start, size_t end, float t)
{
	long long color;
	long long red;
	long long green;
	long long blue;

	red = ((env->colors[start] & 0xff0000) +
	(((env->colors[end] & 0xff0000) -
	(env->colors[start] & 0xff0000)) * t));
	green = ((env->colors[start] & 0x00ff00) +
	(((env->colors[end] & 0x00ff00) -
	(env->colors[start] & 0x00ff00)) * t));
	blue = (env->colors[start] & 0x0000ff) +
		((env->colors[end] & 0x0000ff) -
		(env->colors[start] & 0x0000ff)) * t;
	color = (red & 0xff0000) + (green & 0x00ff00) + (blue & 0x0000ff);
	return (color);
}

static float		get_param(t_env *env, size_t start,
								t_point s, t_point delta)
{
	float t;
	float numer;
	float denom;

	numer = pow(pow(s.x - env->map.values[start][0], 2) +
				pow(s.y - env->map.values[start][1], 2), 0.5);
	denom = pow(pow(delta.x, 2) + pow(delta.y, 2), 0.5);
	t = numer / denom;
	return (t);
}

static void			compute(t_point *s, t_point *error,
							t_point delta, t_point sign)
{
	if (error->y > -delta.y)
	{
		error->x -= delta.y;
		s->x += sign.x;
	}
	if (error->y < delta.x)
	{
		error->x += delta.x;
		s->y += sign.y;
	}
}

int					draw_line(t_env *env, size_t start, size_t end)
{
	t_point delta;
	t_point sign;
	t_point error;
	t_point s;
	t_point e;

	s.x = env->map.values[start][0];
	s.y = env->map.values[start][1];
	e.x = env->map.values[end][0];
	e.y = env->map.values[end][1];
	init_vars(&delta, &sign, s, e);
	error.x = delta.x - delta.y;
	while (s.x != e.x || s.y != e.y)
	{
		mlx_pixel_put(env->mlx, env->win, s.x, s.y,
						get_color(env, start, end,
						get_param(env, start, s, delta)));
		error.y = error.x * 2;
		compute(&s, &error, delta, sign);
	}
	return (0);
}
