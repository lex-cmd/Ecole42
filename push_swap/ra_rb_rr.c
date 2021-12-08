#include "ps.h"

void	ra(t_swap **swap)
{
	t_swap	*tmp_last;
	t_swap	*tmp_rotate;
	t_swap	*tmp_first;

	tmp_rotate = *swap;
	tmp_last = *swap;
	tmp_first = (*swap)->next;
	while (tmp_last->next)
		tmp_last = tmp_last->next;
	tmp_rotate->next = NULL;
	tmp_last->next = tmp_rotate;
	*swap = tmp_first;
	write(1, "ra\n", 3);
}

void	rb(t_swap **swap)
{
	t_swap	*tmp_last;
	t_swap	*tmp_rotate;
	t_swap	*tmp_first;

	tmp_rotate = *swap;
	tmp_last = *swap;
	tmp_first = (*swap)->next;
	while (tmp_last->next)
		tmp_last = tmp_last->next;
	tmp_rotate->next = NULL;
	tmp_last->next = tmp_rotate;
	*swap = tmp_first;
	write(1, "rb\n", 3);
}

void	rr(t_swap **swap_a, t_swap **swap_b)
{
	ra(swap_a);
	rb(swap_b);
	write(1, "rr\n", 3);
}
