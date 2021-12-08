/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:18:44 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/01 10:18:45 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_op *op)
{
	mlx_put_image_to_window(op->mlx, op->win, op->ig_g, op->x, op->y);
	mlx_put_image_to_window(op->mlx, op->win, op->ig_w, op->x, op->y);
	op->sp_walx[op->wax] = op->x;
	op->sp_waly[op->wax] = op->y;
	op->wax++;
}

void	draw_playa(t_op *op)
{
	mlx_put_image_to_window(op->mlx, op->win, op->ig_g, op->x, op->y);
	mlx_put_image_to_window(op->mlx, op->win, op->ig_b, op->x, op->y);
	op->flag = 0;
	op->md = op->x;
	op->mw = op->y;
}

void	draw_collect(t_op *op)
{
	mlx_put_image_to_window(op->mlx, op->win, op->ig_g, op->x, op->y);
	mlx_put_image_to_window(op->mlx, op->win, op->ig_cl,
		op->x + 15, op->y + 15);
	op->col_x[op->colx] = op->x;
	op->col_y[op->colx] = op->y;
	op->colx++;
}

void	draw_grass(t_op *op)
{
	mlx_put_image_to_window(op->mlx, op->win, op->ig_g, op->x, op->y);
	mlx_put_image_to_window(op->mlx, op->win, op->ig_c, op->x, op->y);
	op->exit_x = op->x;
	op->exit_y = op->y;
}

void	all_draw(t_op *op, char *line, int *len)
{
	if (line[*len] == '1')
		draw_wall(op);
	if (line[*len] == 'P' && op->flag != 0)
		draw_playa(op);
	else if (line[*len] == 'P' && op->flag == 0)
		mlx_put_image_to_window(op->mlx, op->win, op->ig_g, op->x, op->y);
	if (line[*len] == 'C')
		draw_collect(op);
	if (line[*len] == '0')
		mlx_put_image_to_window(op->mlx, op->win, op->ig_g, op->x, op->y);
	if (line[*len] == 'E')
		draw_grass(op);
	(*len)++;
	op->x += 64;
}
