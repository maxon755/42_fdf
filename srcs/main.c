/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:10:16 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/14 19:21:08 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		expose_hook(t_env *env)
{
	t_matrix temp;

	mlx_clear_window(env->mlx, env->win);
	temp = env->world.vert;
	env->world.vert = mult_matrix(env->obj.vert, env->world.morph);	
	free_matrix(temp);
	temp = env->camera.vert;
	env->camera.vert = mult_matrix(env->world.vert, env->camera.look);
	free_matrix(temp);
	temp = env->clip.vert;
	env->clip.vert = mult_matrix(env->camera.vert, env->clip.clip_mat);
	free_matrix(temp);
	normalize(env);
	temp = env->view_port.vert;
	env->view_port.vert = mult_matrix(env->clip.vert, env->view_port.morph);
	free_matrix(temp);
	print_notations(env);
	draw_figure(env);
	return (0);
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		system("leaks fdf");
		exit(1);
	}
	if ((keycode >= LEFT_ARROW_KEY && keycode <= UP_ARROW_KEY) ||
		(keycode == PLUS_NUM_KEY || keycode == MINUS_NUM_KEY))
		cam_trans(keycode, env);
	if ((keycode >= A_KEY && keycode <= D_KEY) ||
		(keycode >= Q_KEY && keycode <= E_KEY))
		cam_rotate(keycode, env);
	if (keycode >= ONE_KEY && keycode <= FOUR_KEY)
		colors(keycode, env);
	if (keycode == P_KEY || keycode == O_KEY || keycode == I_KEY)
		deformations(keycode, env);
	expose_hook(env);
	return (0);
}

void	set_object_in_world(t_env *env)
{
	t_vector c;
	t_matrix mirr;

	env->world.morph.rows = 4;
	env->world.morph.cols = 4;
	env->world.morph.values = get_identity_matrix(env->world.morph.rows,
										env->world.morph.cols);
	c = get_center(env->obj.vert);
	env->world.morph = translate(env->world.morph, -c.x, -c.y, -c.z);
	mirr.rows = 4;
	mirr.cols = 4;
	mirr.values = get_identity_matrix(mirr.rows, mirr.cols);
	mirr.values[0][0] = -1;
	env->world.morph = mult_matrix_f(env->world.morph, mirr);
	env->world.vert = mult_matrix(env->obj.vert, env->world.morph);
	free_matrix(mirr);
}

void	init_view_port(t_env *env)
{
	env->view_port.morph.rows = 4;
	env->view_port.morph.cols = 4;
	env->view_port.morph.values = get_identity_matrix(env->view_port.morph.rows,
												env->view_port.morph.cols);
	env->view_port.morph.values[0][0] = (SCREEN_WIDTH - 1) / 2;
	env->view_port.morph.values[1][1] = -(SCREEN_HEIGHT - 1) / 2;
	env->view_port.morph.values[3][0] = (SCREEN_WIDTH - 1) / 2;
	env->view_port.morph.values[3][1] = (SCREEN_HEIGHT - 1) / 2;
	env->view_port.vert = mult_matrix(env->clip.vert, env->view_port.morph);
}

int		main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [file name]");
		return (0);
	}
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
						ft_strjoin("FdF mgayduk", argv[1]));
	env.obj = parse_content(get_content(argv[1]));
	env.obj.amp = get_amp(env.obj.vert);
	set_object_in_world(&env);
	init_camera(&env);
	init_clip(&env);
	init_view_port(&env);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_hook(env.win, 2, 5, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
