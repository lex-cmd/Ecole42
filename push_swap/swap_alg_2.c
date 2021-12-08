#include "ps.h"

void	free_swap(t_swap **swap, t_swap **swap_b)
{
	t_swap	*tmp;

	while (*swap)
	{
		tmp = *swap;
		(*swap) = (*swap)->next;
		free(tmp);
	}
	free(swap);
	free(swap_b);
}

void	count_check(t_swap **swap_a, t_opt *opt)
{
	if (second_lstsize(*swap_a) > 5 && second_lstsize(*swap_a) <= 100)
		opt->count_check = 5;
	else if (second_lstsize(*swap_a) > 100)
		opt->count_check = 11;
}

void	sa_sort(t_swap **swap_a)
{
	t_swap	*tmp;
	t_swap	*visual;
	int		save;

	tmp = *swap_a;
	save = tmp->index;
	if ((save - 1) == tmp->next->index)
	{
		tmp = tmp->next->next;
		if (allsort(tmp))
		{
			sa(swap_a);
		}
	}
}

void	pushing_full(t_swap **swap_a, t_swap **swap_b, t_opt *opt)
{
	t_swap	*max;
	int		flag;
	int		step;

	while (second_lstsize(*swap_b) > 1)
	{
		step_by_step(swap_b, opt);
		max = found_maxindex(swap_b, opt);
		step = max->step;
		flag = max->flag;
		while (step)
		{
			if (flag == -1)
				rb(swap_b);
			else if (flag == 1)
				rrb(swap_b);
			step--;
		}
		pa(swap_a, swap_b, opt);
	}
	while (second_lstsize(*swap_b))
		pa(swap_a, swap_b, opt);
}
