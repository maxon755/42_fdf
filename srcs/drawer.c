/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 18:29:23 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/16 12:52:10 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	not_clipped(float *p)
{
	if (fabs(p[0]) <= 1 &&
		fabs(p[1]) <= 1 &&
		fabs(p[2]) <= 1)
		return (1);
	return (0);
}

static void	init_counters(size_t *i, size_t *j, size_t *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

void		draw_figure(t_env *env)
{
	size_t i;
	size_t j;
	size_t k;

	init_counters(&i, &j, &k);
	while (i + 1 < env->obj.vert.rows)
	{
		if (k == env->obj.p_in_row[j])
		{
			k = 0;
			j++;
		}
		if (env->obj.vert.values[i][1] == env->obj.vert.values[i + 1][1])
			if (not_clipped(env->clip.vert.values[i]) ||
				not_clipped(env->clip.vert.values[i + 1]))
				draw_line(env, i, i + 1);
		if (i + env->obj.p_in_row[j] < env->obj.vert.rows &&
			env->obj.vert.values[i][0] ==
			env->obj.vert.values[i + env->obj.p_in_row[j]][0])
			if (not_clipped(env->clip.vert.values[i]) ||
				not_clipped(env->clip.vert.values[i + env->obj.p_in_row[j]]))
				draw_line(env, i, i + env->obj.p_in_row[j]);
		i++;
		k++;
	}
}
