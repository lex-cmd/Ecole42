#include "ps.h"

int	found_min(t_swap **swap)
{
	t_swap	*tmp_min;
	int		max;

	max = 2147483647;
	tmp_min = *swap;
	while (tmp_min)
	{
		if (tmp_min->value < max && tmp_min->index < 0)
			max = tmp_min->value;
		tmp_min = tmp_min->next;
	}
	return (max);
}

void	sorting_max_to_min(t_swap **swap, t_opt *opt, t_swap *elem)
{
	t_swap	*max;
	t_swap	*min;

	max = found_maxindex(swap, opt);
	min = found_mindex(swap, opt);
	if (second_lstsize(*swap) > 2)
	{
		if (elem->index > max->index)
		{
			while (*swap != min)
				rb(swap);
		}
	}
}

t_swap	*found_maxindex(t_swap **swap, t_opt *opt)
{
	t_swap	*tmp_min;
	t_swap	*tmp_max;
	int		min;

	min = -10;
	tmp_min = *swap;
	while (tmp_min)
	{
		if (tmp_min->index > min)
		{
			min = tmp_min->index;
			tmp_max = tmp_min;
			opt->step_max = tmp_min->step;
		}
		tmp_min = tmp_min->next;
	}
	return (tmp_max);
}

t_swap	*found_mindex(t_swap **swap, t_opt *opt)
{
	t_swap	*tmp_max;
	t_swap	*tmp_min;
	int		max;

	max = 10000;
	tmp_max = *swap;
	while (tmp_max)
	{
		if (tmp_max->index < max)
		{
			max = tmp_max->index;
			tmp_min = tmp_max;
		}
		tmp_max = tmp_max->next;
	}
	return (tmp_min);
}

int	found_max(t_swap **swap)
{
	t_swap	*tmp_min;
	int		min;

	min = -2147483648;
	tmp_min = *swap;
	while (tmp_min)
	{
		if (tmp_min->value > min)
			min = tmp_min->value;
		tmp_min = tmp_min->next;
	}
	return (min);
}
