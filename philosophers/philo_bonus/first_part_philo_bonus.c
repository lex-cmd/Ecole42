/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_philo_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:05 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/17 13:48:59 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int	checking_death(t_opt *opt)
{
	if (get_ms(opt->tm) > opt->philos->eating
		&& opt->philos->eat_flag == 0)
	{
		sem_wait(opt->sem_write), opt->flag_ph_dead = 1;
		printf("%-6lld ms philo %-3d died\n", get_ms(opt->tm) - 1,
			opt->philos->num);
		exit(0);
	}
	return (0);
}

void	fillopt_2(t_opt *opt)
{
	opt->philos = malloc(sizeof(t_philo) * opt->ph_num);
	if (!opt->philos)
		put_error("Erorr malloc");
	opt->pid = malloc(sizeof(t_philo) * opt->ph_num);
	if (!opt->pid)
		put_error("Erorr malloc");
}

void	fillopt(t_opt *opt, char **argv, int argc)
{
	if (argc == 6)
		opt->ph_num_act = ft_atoi(argv[5]);
	else
		opt->ph_num_act = 0;
	opt->len = 0;
	opt->flag_all_eats = 0;
	opt->good_bad_dead = 0;
	opt->flag_ph_dead = 0;
	opt->flag = 0;
	opt->save_time = 0;
	opt->ph_num = ft_atoi(argv[1]);
	if (opt->ph_num < 1)
		put_error("Parse error 2 130 60 60 min");
	opt->ph_time_to_die = ft_atoi(argv[2]);
	if (opt->ph_time_to_die < 60)
		put_error("Parse error 2 130 60 60 min");
	opt->ph_time_to_eat = ft_atoi(argv[3]);
	if (opt->ph_time_to_eat < 60)
		put_error("Parse error 2 130 60 60 min");
	opt->ph_time_to_sleep = ft_atoi(argv[4]);
	if (opt->ph_time_to_sleep < 60)
		put_error("Parse error 2 130 60 60 min");
	fillopt_2(opt);
}
