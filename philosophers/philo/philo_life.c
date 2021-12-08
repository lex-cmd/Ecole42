/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:17:02 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/19 15:12:31 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checking_eat(t_opt *opt, int i, int *len)
{
	if (opt->flag_eaten[i] == 1)
		(*len)++;
	if (*len == opt->ph_num)
	{
		pthread_mutex_lock(opt->died), opt->all_eat = 1;
		return (1);
	}
	return (0);
}

void	philo_life_odd(t_opt *opt, int i)
{
	if (opt->ph_num % 2)
		usleep(50);
	eating_odd(opt, i);
	sleeping(opt, i);
	thinking(opt, i);
}

void	philo_life_even(t_opt *opt, int i)
{
	eating(opt, i);
	sleeping(opt, i);
	thinking(opt, i);
}
