/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_deformation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:26:26 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/14 15:44:29 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	push_z(t_env *env)
{
	size_t i;

	i = 0;
	while (i < env->obj.vert.rows)
	{
		if (env->obj.vert.values[i][2] > 0.1)
			env->obj.vert.values[i][2] += 1;
		i++;
	}
}

int		deformations(int keycode, t_env *env)
{
	if (keycode == P_KEY)
	{
		ft_putendl("p pressed");
		push_z(env);
	}
	print_matrix(env->obj.vert);
	return (0);
}
