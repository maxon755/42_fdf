/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:59:44 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/06 14:37:36 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		translations(int keycode, t_env *env)
{
	if (keycode == 126)
		translate(env, 0, -T_STEP, 0);
	if (keycode == 125)
		translate(env, 0, T_STEP, 0);
	if (keycode == 124)
		translate(env, T_STEP, 0, 0);
	if (keycode == 123)
		translate(env, -T_STEP, 0, 0);
	return (0);
}

int		scalings(int keycode, t_env *env)
{
	if (keycode == 69 || keycode == 24)
		scale(env, S_FACTOR, S_FACTOR, S_FACTOR);
	if (keycode == 78 || keycode == 27)
		scale(env, 1 / S_FACTOR, 1 / S_FACTOR, 1 / S_FACTOR);
	return (0);
}

int		rotations(int keycode, t_env *env)
{
	if (keycode == 13)
		rotate(env, -ALPHA, 0, 0);
	if (keycode == 1)
		rotate(env, ALPHA, 0, 0);
	if (keycode == 12)
		rotate(env, 0, ALPHA, 0);
	if (keycode == 14)
		rotate(env, 0, -ALPHA, 0);
	if (keycode == 0)
		rotate(env, 0, 0, -ALPHA);
	if (keycode == 2)
		rotate(env, 0, 0, ALPHA);
	return (0);
}
