#include "ps.h"

void	three_elems_sort_2(t_swap **swap)
{
	if ((*swap)->index < (*swap)->next->index
		&& (*swap)->index < (*swap)->next->next->index
		&& (*swap)->next->index > (*swap)->next->next->index)
	{
		sa(swap);
		ra(swap);
	}
	if ((*swap)->index < (*swap)->next->index
		&& (*swap)->index > (*swap)->next->next->index
		&& (*swap)->next->index > (*swap)->next->next->index)
		rra(swap);
}

void	three_elems_sort(t_swap **swap, t_opt *opt)
{
	if ((*swap)->index > (*swap)->next->index
		&& (*swap)->index < (*swap)->next->next->index
		&& (*swap)->next->index < (*swap)->next->next->index)
		sa(swap);
	if ((*swap)->index > (*swap)->next->index
		&& (*swap)->index > (*swap)->next->next->index
		&& (*swap)->next->index > (*swap)->next->next->index)
	{
		sa(swap);
		rra(swap);
	}
	if ((*swap)->index > (*swap)->next->index
		&& (*swap)->index > (*swap)->next->next->index
		&& (*swap)->next->index < (*swap)->next->next->index)
		ra(swap);
	three_elems_sort_2(swap);
}

void	five_elems_sort_2(t_swap **swap_a, t_swap **swap_b, t_opt *opt)
{
	three_elems_sort(swap_a, opt);
	pa(swap_a, swap_b, opt);
	pa(swap_a, swap_b, opt);
}

void	five_elems_sort(t_swap **swap_a, t_swap **swap_b, t_opt *opt)
{
	t_swap	*tmp_min;
	t_swap	*tmp_max;

	tmp_min = found_mindex(swap_a, opt);
	tmp_max = found_maxindex(swap_a, opt);
	if ((second_lstsize(*swap_a) == 5))
	{
		while ((second_lstsize(*swap_b) < 2))
		{
			if ((*swap_a)->index == tmp_min->index
				|| (*swap_a)->index == tmp_max->index)
				pb(swap_a, swap_b, opt);
			else
				ra(swap_a);
		}
		five_elems_sort_2(swap_a, swap_b, opt);
		if ((*swap_a)->index == tmp_max->index)
			ra(swap_a);
		else
		{
			sa(swap_a);
			ra(swap_a);
		}
	}
}

void	four_two_elems_sort(t_swap **swap_a, t_swap **swap_b, t_opt *opt)
{
	if (second_lstsize(*swap_a) == 4)
	{
		pb(swap_a, swap_b, opt);
		three_elems_sort(swap_a, opt);
		pa(swap_a, swap_b, opt);
	}
	else if (second_lstsize(*swap_a) == 2)
		sa(swap_a);
	sorting_final(swap_a, opt);
	exit(0);
}
