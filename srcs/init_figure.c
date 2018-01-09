/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:00:16 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/06 14:35:50 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_scale(t_env *env)
{
	t_vector v;
	t_vector amp;

	amp = get_amp(env->map);
	v.x = (WORK_WIDTH - 500) / amp.x;
	v.y = v.x;
	v.z = (SCREEN_HEIGHT - 700) / amp.z;
	v.w = 1;
	scale(env, v.x, v.y, v.z);
	env->position.scale_x *= v.x;
	env->position.scale_y *= v.y;
	env->position.scale_z *= v.z;
}

void	init_position(t_env *env)
{
	t_vector v;

	env->center = get_center(env->map);
	v.x = (WORK_WIDTH) / 2 + N_WIDTH - env->center.x;
	v.y = SCREEN_HEIGHT / 2 + 50 - env->center.y;
	v.z = 0;
	v.w = 1;
	translate(env, v.x, v.y, v.z);
	env->position.x += v.x;
	env->position.y += v.y;
}

void	init_figure(t_env *env)
{
	init_scale(env);
	rotate(env, DEG(-40), DEG(-30), DEG(-30));
	init_position(env);
}
