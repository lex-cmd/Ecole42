/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:35:13 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/01 09:55:27 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	found_cmd(char *cmd1, t_opt *opt)
{
	char	**line;
	char	**line1;
	char	*cmd;
	char	*join;

	opt->len = 0;
	line1 = ft_split(cmd1, ' ');
	line = ft_split(opt->path, ':');
	while (line[opt->len])
	{
		join = ft_strjoin(line[opt->len], "/");
		cmd = ft_strjoin(join, line1[0]);
		if (access(cmd, 1) != -1 && opt->rem == 0)
		{
			opt->rem = 1;
			opt->path1 = cmd;
		}
		else if (access(cmd, 1) != -1 && opt->rem == 1)
			opt->path2 = cmd;
		else
			free(cmd);
		opt->len++;
		free(join);
	}
	freeder(line1, line);
}

void	found_path(char **envp, t_opt *opt, char **argv)
{
	int		i;

	i = 0;
	opt->path = NULL;
	while (envp[i])
	{
		if (envp[i] == ft_strnstr(envp[i], "PATH=", 5))
			opt->path = envp[i];
		i++;
	}
	if (opt->path == NULL)
		put_error("PATH not found");
	if (!ft_strchr(argv[2], '/'))
		found_cmd(argv[2], opt);
	else
		opt->path1 = argv[2];
	if (!ft_strchr(argv[3], '/'))
		found_cmd(argv[3], opt);
	else
		opt->path2 = argv[3];
}

void	daughter(char **argv, int fd[2], char **envp, t_opt *opt)
{
	int		tmp;
	char	**cmd1;

	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	tmp = open(argv[1], O_RDONLY, S_IRWXU);
	dup2(tmp, 0);
	cmd1 = ft_split(argv[2], ' ');
	if (execve(opt->path1, cmd1, envp) == -1)
	{
		put_error("cmd not found\n");
	}
	free(cmd1);
	free(opt->path1);
}

void	mother(char **argv, int fd[2], char **envp, t_opt *opt)
{
	int		tmp;
	char	**cmd2;

	tmp = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	dup2(tmp, 1);
	cmd2 = ft_split(argv[3], ' ');
	if (execve(opt->path2, cmd2, envp) == -1)
	{
		put_error("cmd not found\n");
	}
	free(cmd2);
	free(opt->path2);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	t_opt	opt;

	opt.rem = 0;
	if (argc != 5)
		put_error("./pipex file1 cmd1 cmd2 file2\n");
	if (pipe(fd) == -1)
		put_error("Error\n");
	found_path(envp, &opt, argv);
	pid1 = fork();
	if (pid1 < 0)
	{
		ft_putstr_fd("Fork error\n", 2);
		return (0);
	}
	if (pid1 != 0)
		daughter(argv, fd, envp, &opt);
	else
		mother(argv, fd, envp, &opt);
	closed(fd);
	waitpid(pid1, NULL, 0);
	return (0);
}
