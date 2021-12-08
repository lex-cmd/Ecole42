/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:02 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/20 18:09:30 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*grind(void *arg)
{
	t_opt	*opt;

	opt = (t_opt *)arg;
	gettimeofday(&opt->tm, NULL);
	while (1)
	{
		usleep(10);
		if (checking_death(opt))
			return (arg);
		if (opt->flag_eaten == 1)
			exit(0);
	}
	return (arg);
}

void	philo_start(t_opt *opt, int act)
{
	pthread_t	philo;

	opt->philos->num = act + 1;
	pthread_create(&philo, NULL, grind, opt);
	pthread_detach(philo);
	while (1)
	{
		eating(opt);
		sleeping(opt);
		thinking(opt);
	}
	return ;
}

void	*one_philo(void *opt)
{
	t_opt	topt;

	topt = *(t_opt *)opt;
	printf("%-6dms philo 1 has taken a fork\n", topt.save_time);
	gettimeofday(&topt.tm, NULL);
	usleeper(topt.ph_time_to_die, topt.tm);
	printf("%-6lldms philo 1 died\n", get_ms(topt.tm));
	topt.flag_ph_dead = 1;
	return (opt);
}

void	allclose(t_opt *opt)
{
	int	len;

	len = 0;
	waitpid(-1, NULL, 0);
	while (len < opt->ph_num)
	{
		kill(opt->pid[len], 9);
		len++;
	}
	wait(NULL);
	sem_close(opt->sem_eat);
	sem_close(opt->sem_fork);
	sem_close(opt->sem_write);
	free(opt->philos);
	free(opt->pid);
	exit(0);
}

int	main(int argc, char **argv)
{	
	t_opt		opt;
	int			len;
	int			act;

	len = 0;
	act = 0;
	search_problems(argc, argv);
	fillopt(&opt, argv, argc);
	op_sem(&opt);
	gettimeofday(&opt.tm, NULL);
	while (len < opt.ph_num)
	{
		opt.pid[len] = fork();
		if (opt.pid[len] == 0)
			philo_start(&opt, act);
		else
			act++;
		len++;
	}
	allclose(&opt);
	return (0);
}
