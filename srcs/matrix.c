/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:50:31 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/09 12:11:09 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"

float		**create_matrix(size_t rows, size_t cols)
{
	size_t		i;
	size_t		j;
	float		**m;

	m = (float **)malloc(sizeof(float *) * (rows + 1));
	i = 0;
	while (i < rows)
	{
		m[i] = (float *)malloc(sizeof(float) * cols);
		j = 0;
		while (j < cols)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
	}
	m[i] = NULL;
	return (m);
}

void		free_matrix(t_matrix m)
{
	size_t i;

	i = 0;
	while (i < m.rows)
	{
		free(m.values[i]);
		m.values[i] = NULL;
		i++;
	}
	free(m.values);
	m.values = NULL;
}

t_matrix	dup_matrix(t_matrix src)
{
	t_matrix	dest;
	size_t		i;
	size_t		j;

	dest.rows = src.rows;
	dest.cols = src.cols;
	dest.values = create_matrix(dest.rows, dest.cols);
	i = 0;
	while (i < dest.rows)
	{
		j = 0;
		while (j < dest.cols)
		{
			dest.values[i][j] = src.values[i][j];
			j++;
		}
		i++;
	}
	return (dest);
}

t_matrix	mult_matrix(t_matrix a, t_matrix b)
{
	t_matrix	c;
	size_t		i;
	size_t		j;
	size_t		k;

	c.rows = a.rows;
	c.cols = b.cols;
	c.values = create_matrix(c.rows, c.cols);
	i = -1;
	while (++i < a.rows)
	{
		j = -1;
		while (++j < b.cols)
		{
			k = -1;
			while (++k < a.cols)
				c.values[i][j] += a.values[i][k] * b.values[k][j];
		}
	}
	return (c);
}

t_matrix	mult_matrix_f(t_matrix a, t_matrix b)
{
	t_matrix c;
	t_matrix temp;

	temp = a;
	c = mult_matrix(a, b);
	free_matrix(temp);
	return (c);
}

