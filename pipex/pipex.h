/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:07:59 by fcarl             #+#    #+#             */
/*   Updated: 2021/07/29 12:14:35 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_opt
{
	char	*cmd;
	char	*path;
	char	*path1;
	char	*path2;
	int		rem;
	int		len;
}				t_opt;

void	fill_opt(t_opt *opt);
void	closed(int fd[2]);
void	freeder(char **line, char **line2);
void	put_error(char *line);

#endif 