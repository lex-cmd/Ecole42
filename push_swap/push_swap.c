#include "ps.h"

void	continue_pars(t_swap **swap_a, t_swap **swap_b, t_opt *opt)
{
	t_swap	*tmp_a;
	t_swap	*tmp_b;

	tmp_a = *swap_a;
	opt->count_lst = second_lstsize(*swap_a);
	search_problems(tmp_a);
	if (allsort(tmp_a))
		exit(0);
}

void	pars_number(char **line, t_opt *opt, t_swap *tmp, t_swap **swap_a)
{
	int		i;

	i = 0;
	while (line[i])
	{
		tmp = second_lstnew(ft_atoi(line[i]));
		tmp->index = -1;
		tmp->flag = -1;
		second_lstaddback(swap_a, tmp);
		opt->count_lst++;
		i++;
	}
}

void	pars_string(char *line, t_opt *opt, t_swap *tmp, t_swap **swap_a)
{
	int		i;
	char	**split_line;

	i = 0;
	split_line = ft_split(line, ' ');
	while (split_line[i])
	{
		tmp = second_lstnew(ft_atoi(split_line[i]));
		free(split_line[i]);
		tmp->index = -1;
		tmp->flag = -1;
		second_lstaddback(swap_a, tmp);
		opt->count_lst++;
		i++;
	}
	free(split_line);
}

void	push_swap(char **line)
{
	t_swap	**swap_a;
	t_swap	**swap_b;
	t_swap	*tmp;
	t_opt	opt;

	fill_opt(&opt);
	swap_a = malloc(sizeof(t_swap *));
	*swap_a = NULL;
	swap_b = malloc(sizeof(t_swap *));
	*swap_b = NULL;
	if (ft_strrchr(line[1], ' '))
		pars_string(line[1], &opt, tmp, swap_a);
	else
	{
		while (line[opt.count_lst])
		{
			tmp = second_lstnew(ft_atoi(line[opt.count_lst++]));
			tmp->index = -1;
			tmp->flag = -1;
			second_lstaddback(swap_a, tmp);
		}
	}
	continue_pars(swap_a, swap_b, &opt);
	start_swap(swap_a, swap_b, &opt);
	free_swap(swap_a, swap_b);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		exit (0);
	}
	else
	{
		string_on_digit(argv);
		push_swap(argv);
	}
}
