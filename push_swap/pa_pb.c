#include "ps.h"

void	pb(t_swap **swap_a, t_swap **swap_b, t_opt *opt)
{
	t_swap	*tmp;

	tmp = *swap_a;
	*swap_a = (*swap_a)->next;
	tmp->next = *swap_b;
	*swap_b = tmp;
	opt->count_lst--;
	opt->count_b++;
	write(1, "pb\n", 3);
}

void	pa(t_swap **swap_a, t_swap **swap_b, t_opt *opt)
{
	t_swap	*tmp;

	tmp = *swap_b;
	*swap_b = (*swap_b)->next;
	tmp->next = *swap_a;
	*swap_a = tmp;
	opt->count_b--;
	opt->count_lst++;
	write(1, "pa\n", 3);
}
