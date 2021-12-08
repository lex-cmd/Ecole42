#ifndef PS_H
# define PS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_swap
{
	int				value;
	int				step;
	int				index;
	int				flag;
	int				true;
	int				mark;
	struct s_swap	*next;
}				t_swap;

typedef struct s_opt
{
	int		count_check;
	int		tmp_count;
	int		now_chunk;
	int		count_chunk;
	int		hold_first;
	int		hold_second;
	int		step_max;
	int		step_2;
	int		step;
	int		value;
	int		flag;
	int		head;
	int		count_lst;
	int		count_b;
	int		true;
	int		false;
	char	*array;
}			t_opt;

long long	ft_atoll(const char *str);
void		string_on_digit(char **str);
void		continue_pars(t_swap **swap_a, t_swap **swap_b, t_opt *opt);
void		free_swap(t_swap **swap, t_swap **swap_b);
void		look_same(t_swap *swap_a, int value);
void		search_problems(t_swap *swap_a);
void		four_two_elems_sort(t_swap **swap_a, t_swap **swap_b, t_opt *opt);
void		five_elems_sort(t_swap **swap_a, t_swap **swap_b, t_opt *opt);
void		five_elems_sort_2(t_swap **swap_a, t_swap **swap_b, t_opt *opt);
void		three_elems_sort(t_swap **swap, t_opt *opt);
void		three_elems_sort_2(t_swap **swap);
void		indexation(t_swap **swap_a, t_opt *opt);
void		step_by_step(t_swap **swap, t_opt *opt);
void		index_nullation(t_swap **swap);
void		sorting_final(t_swap **swap_a, t_opt *opt);
int			found_max(t_swap **swap);
t_swap		*found_mindex(t_swap **swap, t_opt *opt);
t_swap		*found_maxindex(t_swap **swap, t_opt *opt);
void		sorting_max_to_min(t_swap **swap, t_opt *opt, t_swap *elem);
int			found_min(t_swap **swap);
void		count_check(t_swap **swap_a, t_opt *opt);
void		sa_sort(t_swap **swap_a);
void		pushing_full(t_swap **swap_a, t_swap **swap_b, t_opt *opt);
void		fill_opt(t_opt *opt);
t_swap		*second_lstnew(int value);
t_swap		*second_lstlast(t_swap *lst);
void		second_lstaddback(t_swap **swap, t_swap *new);
void		second_lstaddfront(t_swap **lst, t_swap *new);
int			second_lstsize(t_swap *lst);
void		start_swap(t_swap **swap_a, t_swap **swap_b, t_opt *opt);
void		push_swap(char **line);
void		start_swap(t_swap **swap_a, t_swap **swap_b, t_opt *opt);
void		three_elems_sort(t_swap **swap, t_opt *opt);
void		five_elems_sort(t_swap **swap_a, t_swap **swap_b, t_opt *opt);
void		step_by_step(t_swap **swap, t_opt *opt);
int			allsort(t_swap *swap_a);
void		sa(t_swap **swap_a);
void		sb(t_swap **swap_a);
void		ss(t_swap **swap_a, t_swap **swap_b);
void		ra(t_swap **swap);
void		rb(t_swap **swap);
void		rr(t_swap **swap_a, t_swap **swap_b);
void		rra(t_swap **swap);
void		rrb(t_swap **swap);
void		rrr(t_swap **swap_a, t_swap **swap_b);
void		pb(t_swap **swap_a, t_swap **swap_b, t_opt *opt);
void		pa(t_swap **swap_a, t_swap **swap_b, t_opt *opt);

#endif