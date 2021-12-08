/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:47:30 by fcarl             #+#    #+#             */
/*   Updated: 2021/04/25 18:13:03 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*led;

	if (lst)
	{
		while (*lst)
		{
			led = (*lst)-> next;
			ft_lstdelone(*lst, del);
			(*lst) = led;
		}
	}
}
