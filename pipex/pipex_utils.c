/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:35:10 by fcarl             #+#    #+#             */
/*   Updated: 2021/07/28 19:33:57 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closed(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

void	put_error(char *line)
{
	ft_putstr_fd(line, 2);
	exit(1);
}

void	freeder(char **line, char **line2)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	i = 0;
	while (line2[i])
	{
		free(line2[i]);
		i++;
	}
	free(line2);
	free(line);
}

void	fill_opt(t_opt *opt)
{
	opt->rem = 0;
	opt->len = 0;
}
