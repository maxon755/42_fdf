/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 08:52:55 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/16 12:55:30 by mgayduk          ###   ########.fr       */
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

static t_matrix	look_at(t_env *env, t_vector eye,
						t_vector target, t_vector up_dir)
{
	t_matrix m;

	env->camera.forward = subtraction(eye, target);
	env->camera.forward = normalization(env->camera.forward);
	env->camera.right = cross_production_left(up_dir, env->camera.forward);
	env->camera.right = normalization(env->camera.right);
	env->camera.up = cross_production_left(env->camera.forward,
									env->camera.right);
	env->camera.up = normalization(env->camera.up);
	m = get_look_matrix(eye, env->camera.forward,
						env->camera.right, env->camera.up);
	return (m);
}

static void		init_steps(t_env *env)
{
	env->camera.xy_step = env->obj.amp.x / 10;
	env->camera.z_step = env->camera.far / 50;
}

void			init_camera(t_env *env)
{
	float		c;

	env->camera.near = 1;
	env->camera.fov_h = DEG(90);
	env->camera.fov_v = env->camera.fov_h * SCREEN_HEIGHT / SCREEN_WIDTH;
	env->camera.target = get_center(env->world.vert);
	if (env->obj.amp.x >= env->obj.amp.y && env->obj.amp.x >= env->obj.amp.z)
		c = 1 / tan(env->camera.fov_h / 2) * env->obj.amp.x + 5;
	else if (env->obj.amp.y >= env->obj.amp.x &&
		env->obj.amp.y >= env->obj.amp.z)
		c = 1 / tan(env->camera.fov_v / 2) * env->obj.amp.y + 5;
	else
		c = env->obj.amp.z + 10;
	env->camera.eye = get_vector(0, 0, c);
	env->camera.far = 2 * c;
	init_steps(env);
	env->camera.up_dir = get_vector(0, -1, 0);
	env->camera.look = look_at(env, env->camera.eye, env->camera.target,
						env->camera.up_dir);
	env->camera.vert = mult_matrix(env->world.vert, env->camera.look);
}
