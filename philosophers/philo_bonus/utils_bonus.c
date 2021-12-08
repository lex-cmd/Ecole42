/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:12 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/17 13:46:00 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	checker_eat(t_opt *opt)
{
	if (opt->ph_num_act > 0)
	{
		if (opt->has_eaten <= opt->ph_num_act)
			opt->has_eaten++;
		else
			opt->flag_eaten = 1;
	}
}

void	put_error(char *line)
{
	ft_putstr_fd(line, 1);
	exit(0);
}

void	semaphore_init(t_opt *opt)
{
	sem_unlink("/write");
	sem_unlink("/forks");
	sem_unlink("/eats");
	opt->sem_eat = sem_open("/eats", O_CREAT, 0666, opt->ph_num_act);
	if (opt->sem_eat == SEM_FAILED)
		put_error("semaphore error\n");
	opt->sem_fork = sem_open("/forks", O_CREAT, 0666, opt->ph_num);
	if (opt->sem_fork == SEM_FAILED)
		put_error("semaphore error\n");
	opt->sem_write = sem_open("/write", O_CREAT, 0666, 1);
	if (opt->sem_write == SEM_FAILED)
		put_error("semaphore error\n");
}

void	op_sem(t_opt *opt)
{
	int	len;

	len = 0;
	semaphore_init(opt);
	opt->philos->num = 0;
	opt->philos->actual_ph = 0;
	opt->philos->eat_flag = 0;
	opt->philos->eating = opt->ph_time_to_die;
	if (opt->ph_num_act > 0)
	{
		opt->has_eaten = 0;
		opt->flag_eaten = 0;
	}
}
