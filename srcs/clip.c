/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:05:00 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/13 14:46:07 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_corners(t_env *env)
{
    env->clip.right = tan(env->camera.fov_h / 2) * env->camera.near;
    env->clip.left = -env->clip.right;
    env->clip.top = tan(env->camera.fov_v / 2) * env->camera.near;
    env->clip.bottom = -env->clip.top;
}

static void	init_clip_mat(t_env *env)
{
    t_clip c;
    float n;
    float f;

    c = env->clip;
    n = env->camera.near;
    f = env->camera.far;
    env->clip.clip_mat.rows = 4;
    env->clip.clip_mat.cols = 4;
    env->clip.clip_mat.values = create_matrix(env->clip.clip_mat.rows,
                                              env->clip.clip_mat.cols);
    env->clip.clip_mat.values[0][0] = 2 / (c.right - c.left);
    env->clip.clip_mat.values[1][1] = 2 / (c.top - c.bottom);
    env->clip.clip_mat.values[2][0] = (c.left + c.right) / (c.left - c.right);
    env->clip.clip_mat.values[2][1] = (c.bottom + c.top) / (c.bottom - c.top);
    env->clip.clip_mat.values[2][2] = (f + n) / (f - n);
    env->clip.clip_mat.values[3][2] = - (2 * n * f) / (f - n);
    env->clip.clip_mat.values[2][3] = 1;
}

void	normalize(t_env *env)
{
	size_t i;

    i = 0;
    while (i < env->clip.vert.rows)
    {
		env->clip.vert.values[i][0] /= env->clip.vert.values[i][3];
		env->clip.vert.values[i][1] /= env->clip.vert.values[i][3];
		env->clip.vert.values[i][2] /= env->clip.vert.values[i][3];
		env->clip.vert.values[i][3] /= env->clip.vert.values[i][3];
		i++;
    }
}

void		init_clip(t_env *env)
{
    init_corners(env);
    init_clip_mat(env);

    env->clip.vert = mult_matrix(env->camera.vert, env->clip.clip_mat);
	normalize(env);
}
