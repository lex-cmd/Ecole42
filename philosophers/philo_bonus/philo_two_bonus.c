/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:08 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/20 11:54:09 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sleeping(t_opt *opt)
{
	sem_wait(opt->sem_write);
	printf("%-6lld ms philo %-3d is sleeping\n", get_ms(opt->tm),
		opt->philos->num);
	sem_post(opt->sem_write);
	usleeper(opt->ph_time_to_eat, opt->tm);
}

void	thinking(t_opt *opt)
{
	sem_wait(opt->sem_write);
	printf("%-6lld ms philo %-3d is thinking\n", get_ms(opt->tm),
		opt->philos->num);
	sem_post(opt->sem_write);
}

void	eating(t_opt *opt)
{
	if (opt->philos->num % 2)
		usleep(1);
	sem_wait(opt->sem_fork);
	sem_wait(opt->sem_write);
	printf("%-6lld ms philo %-3d has taken a fork\n", get_ms(opt->tm),
		opt->philos->num);
	sem_post(opt->sem_write);
	sem_wait(opt->sem_fork);
	sem_wait(opt->sem_write);
	printf("%-6lld ms philo %-3d has taken a fork\n",
		get_ms(opt->tm), opt->philos->num);
	sem_post(opt->sem_write);
	sem_wait(opt->sem_write);
	printf("%-6lld ms philo %-3d is eating\n",
		get_ms(opt->tm), opt->philos->num);
	sem_post(opt->sem_write);
	opt->philos->eating = opt->ph_time_to_die + get_ms(opt->tm);
	opt->philos->eat_flag = 1;
	usleeper(opt->ph_time_to_eat, opt->tm);
	sem_post(opt->sem_fork);
	sem_post(opt->sem_fork);
	checker_eat(opt);
	opt->philos->eat_flag = 0;
}
