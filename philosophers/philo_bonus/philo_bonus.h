/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:28 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/17 12:46:35 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <signal.h>

typedef struct s_philo
{
	pthread_t		deaths_is_here;
	pthread_t		philo;
	int				actual_ph;
	int				eat_flag;
	int				eating;
	int				num;
}				t_philo;

typedef struct s_opt
{
	t_philo			*philos;
	sem_t			*sem_eat;
	sem_t			*sem_write;
	sem_t			*sem_fork;
	pid_t			*pid;
	pthread_t		waiter;
	struct timeval	tm;
	int				has_eaten;
	int				flag_eaten;
	int				flag;
	int				flag_all_eats;
	int				eats;
	int				save_time;
	int				flag_ph_dead;
	int				good_bad_dead;
	int				ph_num;
	int				ph_time_to_die;
	int				ph_time_to_eat;
	int				ph_time_to_sleep;
	int				ph_num_act;
	int				len;
	int				act;
}				t_opt;

void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *str);
void		memory_add(t_opt *opt);
int			checking_death(t_opt *opt);
void		checker_eat(t_opt *opt);
void		philo_life(t_opt *opt, int act);
void		op_sem(t_opt *opt);
void		sleeping(t_opt *opt);
void		thinking(t_opt *opt);
void		eating_odd(t_opt *opt);
void		eating(t_opt *opt);
void		usleeper(long time, struct timeval now);
long long	get_ms(struct timeval old);
void		put_error(char *line);
void		fillopt(t_opt *opt, char **argv, int argc);
void		search_problems(int argc, char **argv);
void		freeder(t_opt *opt);

#endif