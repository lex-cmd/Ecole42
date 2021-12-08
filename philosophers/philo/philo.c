/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:02 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/19 15:59:50 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_start(void *arg)
{
	t_opt	*opt;
	int		act;

	opt = (t_opt *)arg;
	act = opt->len;
	opt->len++;
	while (1 && opt->error == 0)
	{
		usleep(1);
		if (opt->philos[act].num % 2)
			philo_life_odd(opt, act);
		else
			philo_life_even(opt, act);
	}
	return (NULL);
}

void	*one_philo(void *opt)
{
	t_opt			topt;
	pthread_mutex_t	one_ph;

	topt = *(t_opt *)opt;
	pthread_mutex_init(&one_ph, NULL);
	pthread_mutex_lock(&one_ph);
	printf("%-6d ms philo 1 has taken a fork\n", topt.save_time);
	gettimeofday(&topt.tm, NULL);
	usleeper(topt.ph_time_to_die, topt.tm);
	printf("%-6lld ms philo 1 died\n", get_ms(topt.tm));
	topt.flag_ph_dead = 1;
	pthread_mutex_unlock(&one_ph);
	return (opt);
}

void	*death_is_here(void *arg)
{
	t_opt	*opt;
	int		len;
	int		i;

	opt = (t_opt *)arg;
	while (1)
	{
		usleep(50);
		i = 0;
		len = 0;
		if (mutexerror(opt))
			return (arg);
		while (i < opt->ph_num)
		{
			if (checking_death(opt, i))
				return (arg);
			if (checking_eat(opt, i, &len))
				return (arg);
			i++;
		}
	}
	return (arg);
}

void	gogo_threads(t_opt *opt)
{
	int				i;
	pthread_t		monitor;

	i = 0;
	while (i < opt->ph_num)
	{
		opt->philos[i].actual_ph = i;
		opt->philos[i].eating = get_ms(opt->tm) + opt->ph_time_to_die;
		if (pthread_create(&opt->philos[i].philo, NULL, philo_start, opt))
			put_error("pthread_create error");
		pthread_detach(opt->philos[i].philo), i++;
	}
	i = 0;
	while (i < opt->ph_num)
	{
		pthread_join(opt->philos[i].philo, NULL);
		i++;
	}
	pthread_create(&monitor, NULL, death_is_here, opt);
	pthread_join(monitor, NULL), pthread_detach(monitor);
}

int	main(int argc, char **argv)
{	
	t_opt		opt;
	pthread_t	one;

	gettimeofday(&opt.tm, NULL);
	search_problems(argc, argv);
	if (fillopt(&opt, argv, argc))
		return (0);
	if (opt.ph_num == 1)
	{
		pthread_create(&one, NULL, one_philo, &opt);
		pthread_join(one, NULL);
		pthread_detach(one);
	}
	else
	{
		opt.philos = malloc(sizeof(t_philo) * opt.ph_num);
		if (!opt.philos)
			return (0);
		op_mutex(&opt);
		gogo_threads(&opt);
		if (opt.flag_ph_dead == 1 || opt.all_eat == 1 || opt.error != 0)
			freeder(&opt);
	}
	return (0);
}
