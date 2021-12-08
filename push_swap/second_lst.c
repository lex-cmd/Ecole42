#include "ps.h"

t_swap	*circleadd_lst(t_swap *swap, int number)
{
	t_swap	*tmp;
	t_swap	*p;

	tmp = malloc(sizeof(t_swap));
	p = swap->next;
	swap->next = tmp;
	tmp->value = number;
	tmp->next = p;
	return (tmp);
}

t_swap	*circle_init(int value)
{
	t_swap	*swap;

	swap = malloc(sizeof(t_swap));
	swap->value = value;
	swap->next = swap;
	return (swap);
}

t_swap	*second_lstlast(t_swap *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

t_swap	*second_lstnew(int value)
{
	t_swap	*swap;

	swap = malloc(sizeof(t_swap));
	swap->value = value;
	swap->next = NULL;
	return (swap);
}

void	second_lstaddback(t_swap **swap, t_swap *new)
{
	t_swap	*last;

	if (swap)
	{
		if (*swap)
		{
			last = second_lstlast(*swap);
			last->next = new;
		}
		else
			*swap = new;
	}
}
