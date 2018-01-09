/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:41:24 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/04 14:27:29 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# include "fdf.h"

t_list	*get_content(char *filename);

#endif
