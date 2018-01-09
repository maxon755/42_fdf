/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:19:08 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/11 16:29:21 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_front(t_list **alst)
{
	t_list *temp;

	if (alst && *alst)
	{
		temp = (*alst)->next;
		if ((*alst)->content)
		{
			free((*alst)->content);
			(*alst)->content = NULL;
		}
		(*alst)->content_size = 0;
		free(*alst);
		*alst = temp;
	}
}
