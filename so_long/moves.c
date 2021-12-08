/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:18:38 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/01 10:18:39 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_top(int keycode, t_op *op)
{
	if (keycode == 13)
	{
		op->mw -= 64;
		if (wall_stoping(op))
		{
			op->mw -= 64;
			op->cw = op->mw - 64;
			op->mw += 64;
			op->ct_s++;
		}
		else
		{
			op->mw += 64;
		}
		op->img = op->ig_t;
	}
}

void	move_bot(int keycode, t_op *op)
{
	if (keycode == 1)
	{
		op->mw += 64;
		if (wall_stoping(op))
		{
			op->mw += 64;
			op->cw = op->mw - 64;
			op->mw -= 64;
			op->ct_s++;
		}
		else
		{
			op->mw -= 64;
		}
		op->img = op->ig_b;
	}
}

void	move_right(int keycode, t_op *op)
{
	if (keycode == 2)
	{
		op->md += 64;
		if (wall_stoping(op))
		{
			op->md += 64;
			op->cd = op->md - 64;
			op->md -= 64;
			op->ct_s++;
		}
		else
		{
			op->md -= 64;
		}
		op->img = op->ig_r;
	}
}

void	move_left(int keycode, t_op *op)
{
	if (keycode == 0)
	{
		op->md -= 64;
		if (wall_stoping(op))
		{
			op->md -= 64;
			op->cd = op->md + 64;
			op->md += 64;
			op->ct_s++;
		}
		else
			op->md += 64;
		op->img = op->ig_l;
	}
}

int	movehook(int keycode, t_op *op)
{
	mlx_clear_window(op->mlx, op->win);
	prepare_draw(op, op->data);
	keyhook(keycode);
	move_top(keycode, op);
	move_bot(keycode, op);
	move_right(keycode, op);
	move_left(keycode, op);
	eat_some_col(op);
	if (op->md == op->exit_x && op->mw == op->exit_y && op->gocha == op->lencx)
		exit(0);
	mlx_put_image_to_window(op->mlx, op->win, op->img, op->md, op->mw);
	op->ct_n = ft_itoa(op->ct_s);
	mlx_string_put(op->mlx, op->win, 15, 15, 1000000, op->ct_n);
	free(op->ct_n);
	return (0);
}
