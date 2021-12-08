#include "ps.h"

void	options(t_swap **swap_a, t_opt *opt)
{
	if (opt->step >= opt->step_2)
	{
		while (opt->step_2)
		{
			rra(swap_a);
			opt->step_2--;
		}
	}
	else
	{
		while (opt->step)
		{
			ra(swap_a);
			opt->step--;
		}
	}
	opt->step_2 = 0;
	opt->step = 0;
	opt->count_chunk--;
	if (opt->count_chunk == 0)
	{
		opt->now_chunk += opt->tmp_count;
		opt->count_chunk = opt->tmp_count;
	}
}

void	holdfirst(t_swap *tmp, t_opt *opt)
{
	while (tmp)
	{
		if (tmp->index <= opt->now_chunk)
		{
			opt->hold_first = tmp->index;
			opt->step = tmp->step;
			break ;
		}
		tmp = tmp->next;
	}
}

void	holdsecond(t_swap *tmp, t_opt *opt)
{
	while (tmp)
	{
		if (tmp->index <= opt->now_chunk)
		{
			opt->hold_first = tmp->index;
			opt->step_2 = tmp->step;
		}
		tmp = tmp->next;
	}
	if (opt->hold_first == opt->hold_second)
		opt->step = opt->step_2;
}

void	onehundred_sort(t_swap **swap_a, t_swap **swap_b, t_opt *opt)
{
	t_swap	*tmp;
	t_swap	*elem;
	int		tmp_count;

	tmp = *swap_a;
	opt->tmp_count = second_lstsize(*swap_a) / opt->count_check;
	opt->count_chunk = opt->tmp_count;
	opt->now_chunk = opt->tmp_count - 1;
	while (second_lstsize(*swap_a))
	{
		step_by_step(swap_a, opt);
		opt->hold_second = 0;
		opt->hold_first = 0;
		holdfirst(tmp, opt);
		tmp = *swap_a;
		holdsecond(tmp, opt);
		options(swap_a, opt);
		elem = *swap_a;
		sorting_max_to_min(swap_b, opt, elem);
		pb(swap_a, swap_b, opt);
		step_by_step(swap_a, opt);
		tmp = *swap_a;
	}
	pushing_full(swap_a, swap_b, opt);
}

void	start_swap(t_swap **swap_a, t_swap **swap_b, t_opt *opt)
{
	count_check(swap_a, opt);
	indexation(swap_a, opt);
	step_by_step(swap_a, opt);
	if (second_lstsize(*swap_a) == 4 || second_lstsize(*swap_a) == 2)
		four_two_elems_sort(swap_a, swap_b, opt);
	if (second_lstsize(*swap_a) == 3)
		three_elems_sort(swap_a, opt);
	five_elems_sort(swap_a, swap_b, opt);
	if (second_lstsize(*swap_a) > 5)
		onehundred_sort(swap_a, swap_b, opt);
	sorting_final(swap_a, opt);
}
