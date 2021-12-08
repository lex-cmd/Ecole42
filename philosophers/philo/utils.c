/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:12 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/19 14:58:46 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checker_eat(t_opt *opt, int i)
{
	if (opt->ph_num_act > 0)
	{
		if (opt->has_eaten[i] != opt->ph_num_act)
			opt->has_eaten[i]++;
		else
			opt->flag_eaten[i] = 1;
	}
}

void	put_error(char *line)
{
	ft_putstr_fd(line, 1);
}

void	init_forks(t_opt *opt)
{
	int				i;

	i = 0;
	while (opt->ph_num + 2 > i)
	{
		pthread_mutex_init(&opt->mutex.fork[i], NULL);
		i++;
	}
	pthread_mutex_init(opt->died, NULL);
	printf("%p\n", opt->died);
}

void	op_mutex(t_opt *opt)
{
	int	len;

	memory_add(opt);
	init_forks(opt);
	len = 0;
	while (opt->ph_num > len)
	{
		if (opt->ph_num_act > 0)
		{
			opt->has_eaten[len] = 0;
			opt->flag_eaten[len] = 0;
		}
		opt->philos[len].fork_l = &opt->mutex.fork[len];
		opt->philos[len].actual_ph = 0;
		opt->philos[len].num = len + 1;
		opt->philos[len].eat_flag = 0;
		opt->philos[len].eating = get_ms(opt->tm) + opt->ph_time_to_die;
		if (opt->ph_num == len - 1)
			break ;
		opt->philos[len].fork_r = &opt->mutex.fork[len + 1];
		len++;
	}
	opt->philos[len].num = 1;
	opt->philos[--len].fork_r = &opt->mutex.fork[0];
	len = 0;
}

void	freeder(t_opt *opt)
{
	usleep(5000);
	if (opt->ph_num_act > 0)
	{
		free(opt->has_eaten);
		free(opt->flag_eaten);
	}
	free(opt->philos);
	free(opt->mutex.fork);
}
