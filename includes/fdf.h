/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:01:01 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/09 10:08:54 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "matrix.h"
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "reader.h"

# define SCREEN_WIDTH	1024
# define SCREEN_HEIGHT	768
# define WORK_WIDTH		SCREEN_WIDTH - N_WIDTH
# define N_COLOR		0x00cc00
# define N_WIDTH		100
# define NX_P			20
# define NY_P			20
# define T_STEP			50
# define S_FACTOR 		1.2
# define ALPHA 			DEG(10)

# define DEG(x)			(x * 3.14) / 180

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_node
{
	int			x;
	int			y;
	int			z;
	long long	color;
}				t_node;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vector;

typedef struct	s_object
{
	t_matrix	vert;
	long long	*colors;
	size_t		*p_in_row;
}				t_object;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_object	obj;
}				t_env;

t_vector		get_mean(t_matrix m);
t_vector		get_center(t_matrix m);
t_vector		get_amp(t_matrix m);
int				restore_view(t_env *env);
void			init_figure(t_env *env);
t_object		parse_content(t_list *head);
void			draw_figure(t_env *env);
void			print_notations(t_env *env);
int				draw_line(t_env *env, size_t start, size_t end);

t_matrix		translate(t_matrix a, float x, float y, float z);
int				scale(t_env *env, float x, float y, float z);
int				rotate(t_env *env, float x_angle, float y_angle, float z_angle);

int				translations(int keycode, t_env *env);
int				scalings(int keycode, t_env *env);
int				rotations(int keycode, t_env *env);

int				colors(int keycode, t_env *env);

#endif
