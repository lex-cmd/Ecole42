#include "ps.h"

void	rra(t_swap **swap)
{
	t_swap	*tmp_last;
	t_swap	*tmp_rotate;
	t_swap	*tmp_first;

	tmp_last = *swap;
	tmp_first = *swap;
	while (tmp_last->next->next)
		tmp_last = tmp_last->next;
	tmp_rotate = tmp_last->next;
	tmp_last->next = NULL;
	tmp_rotate->next = tmp_first;
	*swap = tmp_rotate;
	write(1, "rra\n", 4);
}

void	rrb(t_swap **swap)
{
	t_swap	*tmp_last;
	t_swap	*tmp_rotate;
	t_swap	*tmp_first;

	tmp_last = *swap;
	tmp_first = *swap;
	while (tmp_last->next->next)
		tmp_last = tmp_last->next;
	tmp_rotate = tmp_last->next;
	tmp_last->next = NULL;
	tmp_rotate->next = tmp_first;
	*swap = tmp_rotate;
	write(1, "rrb\n", 4);
}

void	rrr(t_swap **swap_a, t_swap **swap_b)
{
	rra(swap_a);
	rra(swap_b);
	write(1, "rrr\n", 4);
}
