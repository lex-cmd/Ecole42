/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:37:44 by fcarl             #+#    #+#             */
/*   Updated: 2021/04/25 14:40:00 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (dst[i] && i < size)
		i++;
	while (src[l] && (i + l + 1) < size)
	{
		dst[i + l] = src[l];
		l++;
	}
	if (i < size)
		dst[i + l] = '\0';
	return (i + ft_strlen(src));
}
