/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:33:07 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/13 08:59:31 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	cam_trans(int keycode, t_env *env)
{
	if (keycode == UP_ARROR_KEY)
		env->camera.vert = translate(env->camera.vert, 0, -1, 0);
	if (keycode == DOWN_ARROR_KEY)
		env->camera.vert = translate(env->camera.vert, 0, 1, 0);
	if (keycode == LEFT_ARROR_KEY)
		env->camera.vert = translate(env->camera.vert, 1, 0, 0);
	if (keycode == RIGHT_ARROR_KEY)
		env->camera.vert = translate(env->camera.vert, -1, 0, 0);
	if (keycode == PLUS_NUM_KEY)
		env->camera.vert = translate(env->camera.vert, 0, 0, -1);
	if (keycode == MINUS_NUM_KEY)
		env->camera.vert = translate(env->camera.vert, 0, 0, 1);
	return (0);
}

int	cam_rotate(int keycode, t_env *env)
{
	if (keycode == W_KEY)
		env->camera.vert = rotate_about_x_center(env->camera.vert, DEG(10));
	if (keycode == S_KEY)
		env->camera.vert = rotate_about_x_center(env->camera.vert, DEG(-10));
	if (keycode == A_KEY)
		env->camera.vert = rotate_about_y_center(env->camera.vert, DEG(10));
	if (keycode == D_KEY)
		env->camera.vert = rotate_about_y_center(env->camera.vert, DEG(-10));
	if (keycode == Q_KEY)
		env->camera.vert = rotate_about_z_center(env->camera.vert, DEG(10));
	if (keycode == E_KEY)
		env->camera.vert = rotate_about_z_center(env->camera.vert, DEG(-10));
	return (0);
}
