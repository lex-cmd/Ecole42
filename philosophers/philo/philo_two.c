/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:08 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/19 15:47:25 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_opt *opt, int i)
{
	if (pthread_mutex_lock(opt->died))
		opt->error++;
	printf("%-6lld ms philo %-3d is sleeping\n", get_ms(opt->tm),
		opt->philos[i].num);
	if (pthread_mutex_unlock(opt->died))
		opt->error++;
	usleeper(opt->ph_time_to_sleep, opt->tm);
}

void	thinking(t_opt *opt, int i)
{
	if (pthread_mutex_lock(opt->died))
		opt->error++;
	printf("%-6lld ms philo %-3d is thinking\n", get_ms(opt->tm),
		opt->philos[i].num);
	if (pthread_mutex_unlock(opt->died))
		opt->error++;
}

void	eating(t_opt *opt, int i)
{
	if (pthread_mutex_lock(opt->philos[i].fork_l))
		opt->error++;
	if (pthread_mutex_lock(opt->philos[i].fork_r))
		opt->error++;
	opt->philos[i].eating = opt->ph_time_to_die + get_ms(opt->tm);
	pthread_mutex_lock(opt->died);
	printf("%-6lld ms philo %-3d has taken a fork\n", get_ms(opt->tm),
		opt->philos[i].num);
	pthread_mutex_unlock(opt->died);
	pthread_mutex_lock(opt->died);
	printf("%-6lld ms philo %-3d has taken a fork\n",
		get_ms(opt->tm), opt->philos[i].num);
	pthread_mutex_unlock(opt->died);
	if (opt->lives == 0)
	{
		pthread_mutex_lock(opt->died);
		printf("%-6lld ms philo %-3d is eating\n",
			get_ms(opt->tm), opt->philos[i].num);
		pthread_mutex_unlock(opt->died);
	}
	checker_eat(opt, i);
	usleeper(opt->ph_time_to_eat, opt->tm);
	pthread_mutex_unlock(opt->philos[i].fork_l);
	pthread_mutex_unlock(opt->philos[i].fork_r);
}

void	eating_odd(t_opt *opt, int i)
{
	if (pthread_mutex_lock(opt->philos[i].fork_r))
		opt->error++;
	if (pthread_mutex_lock(opt->philos[i].fork_l))
		opt->error++;
	opt->philos[i].eating = opt->ph_time_to_die + get_ms(opt->tm);
	pthread_mutex_lock(opt->died);
	printf("%-6lld ms philo %-3d has taken a fork\n", get_ms(opt->tm),
		opt->philos[i].num);
	pthread_mutex_unlock(opt->died);
	pthread_mutex_lock(opt->died);
	printf("%-6lld ms philo %-3d has taken a fork\n", get_ms(opt->tm),
		opt->philos[i].num);
	pthread_mutex_unlock(opt->died);
	if (opt->lives == 0)
	{
		pthread_mutex_lock(opt->died);
		printf("%-6lld ms philo %-3d is eating\n",
			get_ms(opt->tm), opt->philos[i].num);
		pthread_mutex_unlock(opt->died);
	}
	checker_eat(opt, i);
	usleeper(opt->ph_time_to_eat, opt->tm);
	pthread_mutex_unlock(opt->philos[i].fork_l);
	pthread_mutex_unlock(opt->philos[i].fork_r);
}
