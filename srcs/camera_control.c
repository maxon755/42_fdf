/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:33:07 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/12 12:51:35 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		move_camera(t_env *env, float x, float y, float z)
{
	env->camera.eye.x += x;
	env->camera.eye.y += y;
	env->camera.eye.z += z;
	env->camera.target.x += x;
	env->camera.target.y += y;
	//env->camera.target.z += z;
	env->camera.look = look_at(env, env->camera.eye, env->camera.target, env->camera.up_dir);
}

int	cam_trans(int keycode, t_env *env)
{
	if (keycode == UP_ARROR_KEY)
		move_camera(env, 0, -1, 0);
	if (keycode == DOWN_ARROR_KEY)
		move_camera(env, 0, 1, 0);
	if (keycode == LEFT_ARROR_KEY)
		move_camera(env, 1, 0, 0);
	if (keycode == RIGHT_ARROR_KEY)
		move_camera(env, -1, 0, 0);
	if (keycode == PLUS_NUM_KEY)
		move_camera(env, 0, 0, -1);
	if (keycode == MINUS_NUM_KEY)
		move_camera(env, 0, 0, 1);
	return (0);
}
/*
int	cam_rotate(int keycode, t_env *env)
{
	
}
*/
