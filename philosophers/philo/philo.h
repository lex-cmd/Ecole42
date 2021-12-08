/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:16:28 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/19 15:09:32 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	pthread_t		deaths_is_here;
	pthread_t		philo;
	int				actual_ph;
	int				eat_flag;
	int				eating;
	int				num;
}				t_philo;

typedef struct s_fork
{
	pthread_mutex_t	*fork;
}				t_fork;

typedef struct s_opt
{
	t_philo			*philos;
	t_fork			mutex;
	struct timeval	tm;
	pthread_mutex_t	*died;
	pthread_mutex_t	*think;
	pthread_mutex_t	*sleep;
	pthread_mutex_t	*eat;
	int				error;
	int				lives;
	int				*has_eaten;
	int				*flag_eaten;
	int				flag;
	int				all_eat;
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
}				t_opt;

int			checking_eat(t_opt *opt, int i, int *len);
int			mutexerror(t_opt *opt);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *str);
void		memory_add(t_opt *opt);
int			checking_death(t_opt *opt, int i);
void		checker_eat(t_opt *opt, int i);
void		philo_life_even(t_opt *opt, int i);
void		philo_life_odd(t_opt *opt, int i);
void		philo_life(t_opt *opt, int act);
void		op_mutex(t_opt *opt);
void		sleeping(t_opt *opt, int i);
void		thinking(t_opt *opt, int i);
void		eating_odd(t_opt *opt, int i);
void		eating(t_opt *opt, int i);
void		usleeper(long time, struct timeval now);
long long	get_ms(struct timeval old);
void		put_error(char *line);
int			fillopt(t_opt *opt, char **argv, int argc);
void		search_problems(int argc, char **argv);
void		freeder(t_opt *opt);

#endif