#include "ps.h"

/* временная переменная для первого листа
 временная переменная для первого листа
 временная переменная для первого листа
переменная №1 = 7. Позиция №1
переменная №2 = 8. Позиция №2
переменная №3 = 3. Позиция №3
переменная №1 = 7 входит в позицию 1
переменная №3 = 3 входит в позицию 2
переменная №2 = 8 позиция №1*/

void	sa(t_swap **swap_a)
{
	t_swap	*per1;
	t_swap	*per2;
	t_swap	*per3;

	per1 = *swap_a;
	per2 = (*swap_a)->next;
	per3 = per2->next;
	per2->next = per1;
	per1->next = per3;
	*swap_a = per2;
	write(1, "sa\n", 3);
}

void	sb(t_swap **swap_a)
{
	t_swap	*per1;
	t_swap	*per2;
	t_swap	*per3;

	per1 = *swap_a;
	per2 = (*swap_a)->next;
	per3 = per2->next;
	per2->next = per1;
	per1->next = per3;
	*swap_a = per2;
	write(1, "sa\n", 3);
}

void	ss(t_swap **swap_a, t_swap **swap_b)
{
	sa(swap_a);
	sb(swap_b);
	write(1, "ss\n", 3);
}
