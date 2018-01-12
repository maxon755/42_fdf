/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:10:16 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/12 09:17:57 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>


void	draw_f(t_env *env)
{
	size_t i;

	i = 0;
	while (i < env->view_port.vert.rows)
	{
		mlx_pixel_put(env->mlx, env->win, env->view_port.vert.values[i][0],
					  env->view_port.vert.values[i][1], 0xffffff);
		i++;
	}
}

int				expose_hook(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	//print_notations(env);
	//env->center = get_center(env->map);
	draw_figure(env);
	return (0);
}

int				key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(1);
/*	if (keycode >= 123 && keycode <= 126)
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
	restore_view(env);*/
	expose_hook(env);
	return (0);
}

void			set_object_in_world(t_env *env)
{
	t_vector c;

	env->world.morph.rows = 4;
    env->world.morph.cols = 4;
    env->world.morph.values = get_identity_matrix(env->world.morph.rows,
												  env->world.morph.cols);
	c = get_center(env->obj.vert);
	env->world.morph = rotate_about_y_center(env->world.morph, DEG(0));

	env->world.morph = translate(env->world.morph, -c.x, -c.y, -c.z);
	
    ft_putendl("Morph world matrix 1");
    print_matrix(env->world.morph);
    ft_putstr("\n");

	t_matrix mirr;
	mirr.rows = 4;
	mirr.cols = 4;
	mirr.values = get_identity_matrix(mirr.rows, mirr.cols);
	mirr.values[0][0] = -1;

	env->world.morph = mult_matrix(env->world.morph, mirr);
	
	env->world.vert = mult_matrix(env->obj.vert, env->world.morph);

	//free_matrix(t);
	ft_putendl("model in the world");
	print_matrix(env->world.vert);
	ft_putstr("\n");
}

void		init_view_port(t_env *env)
{
	env->view_port.morph.rows = 4;
	env->view_port.morph.cols = 4;
	env->view_port.morph.values = get_identity_matrix(env->view_port.morph.rows,
												env->view_port.morph.cols);
	env->view_port.morph.values[0][0] = (SCREEN_WIDTH - 1) / 2;
	env->view_port.morph.values[1][1] = - (SCREEN_HEIGHT - 1) / 2;
	env->view_port.morph.values[3][0] = (SCREEN_WIDTH - 1) / 2;
	env->view_port.morph.values[3][1] = (SCREEN_HEIGHT - 1) / 2;
	env->view_port.vert = mult_matrix(env->clip.vert, env->view_port.morph);
	ft_putendl("view port matrix");
	print_matrix(env->view_port.vert);
	ft_putstr("\n");

}

int			main(int argc, char **argv)
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

	ft_putendl("origin model");
	print_matrix(env.obj.vert);
	ft_putstr("\n");

	set_object_in_world(&env);
	init_camera(&env);

	init_clip(&env);
	init_view_port(&env);

	//system("leaks fdf");
	/*set_zero_pos(env);
	env->map = dup_matrix(env->init_map);
	env->center = get_center(env->map);
	init_figure(env);*/
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
