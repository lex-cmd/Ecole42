#include "ps.h"

void	look_same(t_swap *swap_a, int value)
{
	while (second_lstsize(swap_a))
	{
		if (swap_a->value == value)
		{
			printf("Error\n");
			exit (0);
		}
		swap_a = swap_a->next;
	}
}

void	fill_opt(t_opt *opt)
{
	opt->step_2 = 0;
	opt->flag = 0;
	opt->count_lst = 1;
	opt->count_b = 0;
	opt->true = 0;
	opt->false = 0;
	opt->step = 0;
	opt->hold_first = 0;
}

void	search_problems(t_swap *swap_a)
{
	t_swap	*tmp;
	t_swap	*tmp1;

	tmp = swap_a;
	while (tmp)
	{
		look_same(tmp->next, tmp->value);
		tmp = tmp->next;
	}
}

int	allsort(t_swap *swap_a)
{
	t_swap	*tmp_a;
	int		nextnum;
	int		i;

	i = 0;
	tmp_a = swap_a;
	nextnum = tmp_a->value;
	while (tmp_a)
	{
		if (tmp_a->next == NULL)
			i = 1;
		else
			nextnum = tmp_a->next->value;
		if (nextnum < tmp_a->value && !i)
			return (0);
		else if (i && nextnum >= tmp_a->value)
			return (1);
		tmp_a = tmp_a->next;
	}
	tmp_a = NULL;
	return (0);
}

void	sorting_final(t_swap **swap_a, t_opt *opt)
{
	t_swap	*tmp;
	t_swap	*last;

	tmp = *swap_a;
	sa_sort(swap_a);
	while (!allsort(*swap_a))
	{
		last = second_lstlast(*swap_a);
		if (last->index < (*swap_a)->index)
		{
			ra(swap_a);
		}
		else if (last->index > (*swap_a)->index)
		{
			rra(swap_a);
			sa(swap_a);
		}
		else
		{
			rra(swap_a);
		}
	}
}
