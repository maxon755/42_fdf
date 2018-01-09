/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:54:57 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/06 14:43:46 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <math.h>

typedef struct	s_matrix
{
	float		**values;
	size_t		rows;
	size_t		cols;
}				t_matrix;

float			**create_matrix(size_t rows, size_t cols);
void			print_matrix(t_matrix m);
void			free_matrix(t_matrix m);
t_matrix		dup_matrix(t_matrix src);
t_matrix		mult_matrix(t_matrix a, t_matrix b);
t_matrix		get_translation_matrix(float x, float y, float z);
t_matrix		get_scale_matrix(float x, float y, float z);
t_matrix		get_x_rot_matrix(float x_angle);
t_matrix		get_y_rot_matrix(float y_angle);
t_matrix		get_z_rot_matrix(float z_angle);

#endif
