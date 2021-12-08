/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:01:06 by fcarl             #+#    #+#             */
/*   Updated: 2021/04/25 16:05:45 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	c;
	char	*str1;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	c = ft_strlen(s1 + i);
	if (c)
		while (s1[c + i - 1] != 0 && ft_strchr(set, s1[c + i - 1]) != 0)
			c--;
	str1 = (char *)malloc(sizeof(char) * c + 1);
	if (!str1)
		return (NULL);
	ft_strncpy(str1, s1 + i, c);
	str1[c] = '\0';
	return (str1);
}
