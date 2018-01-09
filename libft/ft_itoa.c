/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:53:34 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/09 15:45:48 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fill_str(int n, char **s)
{
	if (n < 0)
	{
		n = -n;
		**s = '-';
		(*s)++;
	}
	if (n <= 9)
	{
		**s = n + '0';
		(*s)++;
		return ;
	}
	ft_fill_str(n / 10, s);
	**s = n % 10 + '0';
	(*s)++;
}

static size_t	ft_get_len(int n)
{
	size_t len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	char	*min_int;

	min_int = "-2147483648";
	if (n == -2147483648)
	{
		str = ft_strnew(11);
		while ((*str++ = *min_int++))
			;
		return (str - 12);
	}
	len = ft_get_len(n);
	str = ft_strnew(len);
	if (str)
	{
		ft_fill_str(n, &str);
		return (str - len);
	}
	return (NULL);
}
