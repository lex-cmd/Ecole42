/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:35:26 by fcarl             #+#    #+#             */
/*   Updated: 2021/06/01 11:47:03 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*beg;

	if (!lst || !new)
		return ;
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			beg = ft_lstlast(*(lst));
			beg -> next = new;
		}
	}
}
