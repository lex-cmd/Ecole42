/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:55:04 by fcarl             #+#    #+#             */
/*   Updated: 2021/06/08 20:07:33 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeclean(char **str, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		free(str[k]);
		str[k] = NULL;
		k++;
	}
	free(str);
	return (NULL);
}

char	**ft_fullarr(char const *s, char c, char **str)
{
	int	l;
	int	i;
	int	p;

	p = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		l = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > l)
			str[p++] = ft_substr(s + l, 0, i - l);
		if (!str)
			return (ft_freeclean(str, p - 1));
	}
	str[p] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (numstr(s, c) + 1));
	if (str == NULL)
		return (NULL);
	ft_fullarr(s, c, str);
	return (str);
}
