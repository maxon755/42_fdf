/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_deformation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:26:26 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/14 19:26:22 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	push_z(t_env *env)
{
	size_t i;

	i = 0;
	while (i < env->obj.vert.rows)
	{
		if (env->obj.vert.values[i][2] != 0)
			env->obj.vert.values[i][2] += env->obj.amp.z / 5;
		i++;
	}
}

static void	pull_z(t_env *env)
{
	size_t i;

	i = 0;
	while (i < env->obj.vert.rows)
	{
		if (env->obj.vert.values[i][2] != 0)
			env->obj.vert.values[i][2] -= env->obj.amp.z / 5;
		i++;
	}
}

static void	bend_up(t_env *env)
{
	size_t i;
	ft_putendl("pressed");

	i = 0;
	while (i < env->obj.vert.rows)
	{
			env->obj.vert.values[i][2] += env->obj.vert.values[i][0] * env->obj.vert.values[i][0] * 0.002;
		i++;
	}
}

int		deformations(int keycode, t_env *env)
{
	if (keycode == P_KEY)
		push_z(env);
	if (keycode == O_KEY)
		pull_z(env);
	if (keycode == I_KEY)
		bend_up(env);
	print_matrix(env->obj.vert);
	return (0);
}
