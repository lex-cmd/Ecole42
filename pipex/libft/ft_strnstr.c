/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:49:08 by fcarl             #+#    #+#             */
/*   Updated: 2021/04/27 15:16:43 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static size_t	ft_strnlen(char *str, size_t max_size)
{
	if (ft_strlen(str) > max_size)
		return (max_size);
	else
		return (ft_strlen(str));
}

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	lit_len;
	char	check;

	i = 0;
	if (ft_strlen(big) < ft_strlen(lit))
		return (0);
	if (!big)
		check = *big;
	lit_len = ft_strnlen((char *)lit, len);
	if ((lit_len == 0 && len != 0) || lit[0] == 0)
		return ((char *)big);
	while (i <= len - lit_len)
	{
		if (big[0] == lit[0] && ft_strncmp(big, lit, lit_len) == 0)
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
