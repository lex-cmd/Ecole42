/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_usleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:23 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/19 16:01:26 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_ms(struct timeval old)
{
	struct timeval	new;

	gettimeofday(&new, NULL);
	new.tv_sec -= old.tv_sec;
	new.tv_usec -= old.tv_usec;
	if (new.tv_usec < 0)
	{
		--new.tv_sec;
		new.tv_usec += 1000000;
	}
	return ((new.tv_sec * 1000) + (new.tv_usec * 0.001));
}

void	usleeper(long time, struct timeval now)
{
	long long	cur_time;

	cur_time = get_ms(now);
	usleep((time - 15) * 1000);
	while (1)
	{
		usleep(50);
		if (get_ms(now) >= cur_time + time)
			break ;
	}
}
