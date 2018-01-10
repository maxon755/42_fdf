/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:10:16 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/10 11:47:17 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>
/*
int				expose_hook(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	print_notations(env);
	env->center = get_center(env->map);
	draw_figure(env);
	return (0);
}

int				key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(1);
	if (keycode >= 123 && keycode <= 126)
		translations(keycode, env);
	if (keycode == 69 || keycode == 78 ||
		keycode == 24 || keycode == 27)
		scalings(keycode, env);
	if ((keycode >= 0 && keycode <= 2) ||
		(keycode >= 12 && keycode <= 14))
		rotations(keycode, env);
	if (keycode >= 18 && keycode <= 21)
		colors(keycode, env);
	if (keycode == 6)
		restore_view(env);
	expose_hook(env);
	return (0);
}

void			set_zero_pos(t_env *env)
{
	env->position.x = 0;
	env->position.y = 0;
	env->position.about_x = 0;
	env->position.about_y = 0;
	env->position.about_z = 0;
	env->position.scale_x = 1;
	env->position.scale_y = 1;
	env->position.scale_z = 1;
	}*/

void		set_object_in_world(t_env *env)
{
	t_matrix t;
	t_vector c;

	env->world.morph.rows = 4;
    env->world.morph.cols = 4;
    env->world.morph.values = get_identity_matrix(env->world.morph.rows,
												  env->world.morph.cols);
	c = get_center(env->obj.vert);
	t = get_translation_matrix(-c.x, -c.y, -c.z);
	env->world.morph = mult_matrix_f(env->world.morph, t);
	env->world.vert = mult_matrix(env->obj.vert, env->world.morph);
	free_matrix(t);
}

int				main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [file name]");
		return (0);
	}
	//env.mlx = mlx_init();
	//env.win = mlx_new_window(env.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
	//						ft_strjoin("FdF mgayduk - ", argv[1]));
	env.obj = parse_content(get_content(argv[1]));

	set_object_in_world(&env);
	print_matrix(env.world.vert);

	t_vector target = get_center(env.world.vert);
	print_vector(target);
	t_vector eye = get_vector(0, 0, 5);
	print_vector(eye);
	t_vector up_dir = get_vector(0, 5, 0);

	env.camera.look = look_at(eye, target, up_dir);
	print_matrix(env.camera.look);
	ft_putendl("Result camera matrix");
	env.camera.vert = mult_matrix(env.world.vert, env.camera.look);
	print_matrix(env.camera.vert);

	system("leaks fdf");
	/*set_zero_pos(env);
	env->map = dup_matrix(env->init_map);
	env->center = get_center(env->map);
	init_figure(env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);*/
	return (0);
}
