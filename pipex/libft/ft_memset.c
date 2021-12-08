/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:44:49 by fcarl             #+#    #+#             */
/*   Updated: 2021/04/23 20:21:22 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int cor, size_t sh)
{
	while (sh--)
	{
		((unsigned char *)dst)[sh] = (unsigned char)cor;
	}
	return (dst);
}
