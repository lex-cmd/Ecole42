/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:00:42 by fcarl             #+#    #+#             */
/*   Updated: 2021/04/19 19:12:21 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	if ((!dst && !src) || (len == 0))
		return (dst);
	while (len--)
		((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return ((void *)dst);
}
