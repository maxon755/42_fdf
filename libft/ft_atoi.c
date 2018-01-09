/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:54:54 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/13 17:11:07 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int		num;
	short	mult;

	while (ft_iswhite(*str))
		str++;
	mult = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mult = -1;
		str++;
	}
	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + mult * (*str - '0');
		str++;
	}
	return (num);
}
