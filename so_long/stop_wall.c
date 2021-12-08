/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:18:51 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/01 10:18:56 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	eat_some_col2(t_op *op, int *len, int *x, int *x1)
{
	int	flag;

	flag = 1;
	*len = 0;
	while (*len != op->gocha)
	{
		if (op->tmp_x[*len] == op->md
			&& op->tmp_y[*len] == op->mw)
			flag = 0;
		(*len)++;
	}
	if (op->md == op->col_x[*x]
		&& op->mw == op->col_y[*x] && flag == 1)
	{
		mlx_put_image_to_window(op->mlx, op->win,
			op->ig_g, op->md, op->mw);
		op->tmp_x[op->gocha] = op->md;
		op->tmp_y[op->gocha] = op->mw;
		op->gocha++;
	}
	(*x)++;
	(*x1)--;
}

void	eat_some_col(t_op *op)
{
	int	x;
	int	x1;
	int	len;

	x1 = op->lencx;
	x = 0;
	len = 0;
	while (x1)
		eat_some_col2(op, &len, &x, &x1);
	len = 0;
	if (op->gocha > op->lencx)
		op->gocha = op->lencx;
	while (len != op->gocha)
	{
		mlx_put_image_to_window(op->mlx, op->win, op->ig_g,
			op->tmp_x[len], op->tmp_y[len]);
		len++;
	}
}

void	memory_malocer(t_op *op, int len_x)
{
	op->sp_walx = malloc(sizeof(int) * (len_x));
	op->sp_waly = malloc(sizeof(int) * (len_x));
	op->col_x = malloc(sizeof(int) * (op->lencx));
	op->col_y = malloc(sizeof(int) * (op->lencx));
	op->tmp_x = malloc(sizeof(int) * (op->lencx));
	op->tmp_y = malloc(sizeof(int) * (op->lencx));
	op->save_x = len_x;
}

void	stop_wall(t_op *op, t_list **data)
{
	int		len_x;
	t_list	*tmp;
	char	*line;
	int		i;

	i = 0;
	len_x = 0;
	tmp = *data;
	op->lencx = 0;
	while (tmp)
	{
		line = tmp->content;
		while (line[i])
		{
			if (line[i] == '1')
				len_x++;
			if (line[i] == 'C')
				op->lencx++;
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
	memory_malocer(op, len_x);
}

int	wall_stoping(t_op *op)
{
	int	x;
	int	x1;

	x1 = op->save_x;
	x = 0;
	while (x1)
	{
		if (op->md == op->sp_walx[x] && op->mw == op->sp_waly[x])
			return (0);
		x++;
		x1--;
	}
	return (1);
}
