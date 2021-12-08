#include "ps.h"

void	index_nullation(t_swap **swap)
{
	t_swap	*tmp;

	tmp = *swap;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

void	step_by_step(t_swap **swap, t_opt *opt)
{
	t_swap	*tmp;
	int		steps;
	int		count;

	tmp = *swap;
	steps = 0;
	count = second_lstsize(*swap);
	while (tmp)
	{
		tmp->step = steps;
		tmp = tmp->next;
		if (count / 2 == steps && count % 2 == 1)
			break ;
		steps++;
		if ((count + 1) / 2 == steps && count % 2 == 0)
			break ;
		tmp->flag = -1;
	}
	while (tmp)
	{
		tmp->step = steps;
		tmp->flag = 1;
		steps--;
		tmp = tmp->next;
	}
}

void	indexation(t_swap **swap_a, t_opt *opt)
{
	t_swap	*temp;
	int		min;
	int		i;

	i = 0;
	while (i != opt->count_lst)
	{
		min = found_min(swap_a);
		temp = *swap_a;
		while (temp)
		{
			if (temp->value == min)
			{
				temp->index = i;
				i++;
				break ;
			}
			temp = temp->next;
		}
	}
}

void	second_lstaddfront(t_swap **lst, t_swap *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	second_lstsize(t_swap *lst)
{
	int		i;
	t_swap	*rst;

	i = 0;
	if (!lst)
		return (0);
	rst = lst;
	while (rst)
	{
		rst = rst -> next;
		i++;
	}
	return (i);
}
