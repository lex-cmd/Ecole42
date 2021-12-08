/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:05 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/20 11:48:09 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutexerror(t_opt *opt)
{
	if (opt->error != 0)
	{
		pthread_mutex_lock(opt->died);
		printf("mutex error\n");
		return (1);
	}
	return (0);
}

void	search_problems(int argc, char **argv)
{
	int	len_y;
	int	len_x;

	if (argc <= 4 || argc >= 7)
		put_error("./philo 5 800 200 200 7");
	len_y = 1;
	len_x = 0;
	while (argv[len_y])
	{
		while (argv[len_y][len_x])
		{
			if (argv[len_y][len_x] < '0' || argv[len_y][len_x] > '9')
				put_error("Wrong symbol in argument!");
			len_x++;
		}
		len_x = 0;
		len_y++;
	}
}

int	checking_death(t_opt *opt, int i)
{
	if (get_ms(opt->tm) >= opt->philos[i].eating)
	{
		pthread_mutex_lock(opt->died), opt->flag_ph_dead = 1;
		opt->lives++;
		printf("%-6lld ms philo %-3d died\n", get_ms(opt->tm),
			opt->philos[i].num);
		return (1);
	}
	return (0);
}

void	memory_add(t_opt *opt)
{
	opt->mutex.fork = malloc(sizeof(pthread_mutex_t) * (opt->ph_num + 2));
	if (!opt->mutex.fork)
		put_error("Error memory malloc");
	opt->died = malloc(sizeof(pthread_mutex_t));
	if (opt->ph_num_act > 0)
	{
		opt->has_eaten = malloc(sizeof(int) * opt->ph_num);
		if (!opt->has_eaten)
			put_error("Error memory malloc");
		opt->flag_eaten = malloc(sizeof(int) * opt->ph_num);
		if (!opt->flag_eaten)
			put_error("Error memory malloc");
	}	
}

int	fillopt(t_opt *opt, char **argv, int argc)
{
	if (argc == 6)
		opt->ph_num_act = ft_atoi(argv[5]);
	else
		opt->ph_num_act = 0;
	opt->error = 0;
	opt->lives = 0;
	opt->len = 0;
	opt->all_eat = 0;
	opt->good_bad_dead = 0;
	opt->flag_ph_dead = 0;
	opt->flag = 0;
	opt->save_time = 0;
	opt->ph_num = ft_atoi(argv[1]);
	if (opt->ph_num < 1)
		return (1);
	opt->ph_time_to_die = ft_atoi(argv[2]);
	if (opt->ph_time_to_die < 60)
		return (1);
	opt->ph_time_to_eat = ft_atoi(argv[3]);
	if (opt->ph_time_to_eat < 60)
		return (1);
	opt->ph_time_to_sleep = ft_atoi(argv[4]);
	if (opt->ph_time_to_sleep < 60)
		return (1);
	return (0);
}
