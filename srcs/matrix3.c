/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:05:03 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/16 13:00:08 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"

float		**get_identity_matrix(size_t rows, size_t cols)
{
	size_t	i;
	size_t	j;
	float	**m;

	if (rows != cols)
		return (NULL);
	m = (float **)malloc(sizeof(float *) * (rows + 1));
	i = 0;
	while (i < rows)
	{
		m[i] = (float *)malloc(sizeof(float) * cols);
		j = 0;
		while (j < cols)
		{
			if (i == j)
				m[i][j] = 1;
			else
				m[i][j] = 0;
			j++;
		}
		i++;
	}
	m[i] = NULL;
	return (m);
}

void		print_matrix(t_matrix m)
{
	size_t i;
	size_t j;

	if (!(m.values))
	{
		ft_putendl("The matrix doesn`t exist");
		return ;
	}
	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			ft_putnbr(m.values[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
