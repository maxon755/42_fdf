/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:38:51 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/09 16:18:20 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "fdf.h"


typedef struct  s_vector
{
    float       x;
    float       y;
    float       z;
    float       w;
}               t_vector;

t_vector	cross_production(t_vector a, t_vector b);
t_vector	normalization(t_vector a);
void		print_vector(t_vector a);

#endif
