/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:18:54 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/01 10:18:57 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	puterror(char *line)
{
	ft_putstr_fd(line, 2);
	exit(0);
}

void	keyhook(int	keycode)
{
	if (keycode == 53)
		exit(0);
}

void	fill_option2(t_op *op)
{
	op->wax = 0;
	op->y = 0;
	op->x = 0;
	op->colx = 0;
}

void	fill_op(t_op *op, t_list **data)
{
	op->size_x = ft_strlen((*data)->content);
	op->size_y = ft_lstsize(*data);
	op->exit_x = 0;
	op->exit_y = 0;
	op->len_y = 0;
	op->ph_s = "./sprites/link_stand.xpm";
	op->ph_t = "./sprites/link_go_top.xpm";
	op->ph_b = "./sprites/link_go_left.xpm";
	op->ph_l = "./sprites/link_move_right.xpm";
	op->ph_w = "./sprites/wall.xpm";
	op->ph_c = "./sprites/castle.xpm";
	op->ph_g = "./sprites/grass.xpm";
	op->ph_cl = "./sprites/colect.xpm";
	op->x = 0;
	op->y = 0;
	op->res_x = op->size_x * 64;
	op->res_y = op->size_y * 64;
	op->wh = 64;
	op->ht = 64;
	op->cw = 0;
	op->cd = 0;
	op->data = data;
	op->flag = 1;
	op->ct_s = 0;
}
