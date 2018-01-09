/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:10:16 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/09 11:24:12 by mgayduk          ###   ########.fr       */
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

int				main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [file name]");
		return (0);
	}
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
								ft_strjoin("FdF mgayduk - ", argv[1]));
	env.obj = parse_content(get_content(argv[1]));
	print_matrix(env.obj.vert);

	//env.obj.vert = translate(env.obj.vert, 50, 50, 10);
	env.obj.vert = scale(env.obj.vert, 2, 2, 0);
	ft_putendl("transformed");
	//print_matrix(env.obj.vert);

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
