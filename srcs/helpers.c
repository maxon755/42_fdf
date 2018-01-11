/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:15:50 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/11 16:18:38 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector	get_center(t_matrix m)
{
	size_t		i;
	t_vector	mid;

	i = 0;
	mid.x = 0;
	mid.y = 0;
	mid.z = 0;
	while (i < m.rows)
	{
		mid.x += m.values[i][0];
		mid.y += m.values[i][1];
		mid.z += m.values[i][2];
		i++;
	}
	mid.x /= m.rows;
	mid.y /= m.rows;
	mid.z /= m.rows;
	mid.w = 1;
	return (mid);
}

t_vector	get_amp(t_matrix m)
{
	size_t		i;
	int			temp;
	int			min_z;
	int			max_z;
	t_vector	amp;

	amp.x = fabs(m.values[m.rows - 1][0] - m.values[0][0]);
	amp.y = fabs(m.values[m.rows - 1][1] - m.values[0][1]);
	min_z = m.values[0][2];
	max_z = min_z;
	i = 1;
	while (i < m.rows)
	{
		temp = m.values[i][2];
		if (max_z < temp)
			max_z = temp;
		if (min_z > temp)
			min_z = temp;
		i++;
	}
	amp.z = abs(max_z - min_z);
	amp.w = min_z;
	return (amp);
}
/*
int			restore_view(t_env *env)
{
	free_matrix(env->map);
	env->map = dup_matrix(env->init_map);
	init_figure(env);
	return (0);
}*/
/*
void		print_notations(t_env *env)
{
	mlx_string_put(env->mlx, env->win, NX_P, NY_P, N_COLOR,
			"move       : arrows");
	mlx_string_put(env->mlx, env->win, NX_P, 3 * NY_P, N_COLOR,
			"zoom in    : +");
	mlx_string_put(env->mlx, env->win, NX_P, 4 * NY_P, N_COLOR,
			"zoom out   : -");
	mlx_string_put(env->mlx, env->win, NX_P, 6 * NY_P, N_COLOR,
			"z rotation : a, d");
	mlx_string_put(env->mlx, env->win, NX_P, 7 * NY_P, N_COLOR,
			"y rotation : q, e");
	mlx_string_put(env->mlx, env->win, NX_P, 8 * NY_P, N_COLOR,
			"x rotation : w, s");
	mlx_string_put(env->mlx, env->win, NX_P, 10 * NY_P, N_COLOR,
			"restore view : z");
	mlx_string_put(env->mlx, env->win, NX_P, 12 * NY_P, N_COLOR,
			"change color : 1 - 4");
}
*/
