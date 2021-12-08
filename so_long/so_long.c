/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:18:46 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/01 10:18:47 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closed(void)
{
	exit(0);
}

void	set_image(t_op *op)
{
	op->ig_cl = mlx_xpm_file_to_image(op->mlx, op->ph_cl, &op->wh, &op->ht);
	op->ig_g = mlx_xpm_file_to_image(op->mlx, op->ph_g, &op->wh, &op->ht);
	op->ig_c = mlx_xpm_file_to_image(op->mlx, op->ph_c, &op->wh, &op->ht);
	op->ig_w = mlx_xpm_file_to_image(op->mlx, op->ph_w, &op->wh, &op->ht);
	op->img = mlx_xpm_file_to_image(op->mlx, op->ph_s, &op->wh, &op->ht);
	op->ig_b = mlx_xpm_file_to_image(op->mlx, op->ph_s, &op->wh, &op->ht);
	op->ig_t = mlx_xpm_file_to_image(op->mlx, op->ph_t, &op->wh, &op->ht);
	op->ig_l = mlx_xpm_file_to_image(op->mlx, op->ph_b, &op->wh, &op->ht);
	op->ig_r = mlx_xpm_file_to_image(op->mlx, op->ph_l, &op->wh, &op->ht);
}

void	prepare_draw(t_op *op, t_list **data)
{
	t_list	*lst;
	char	*line;
	t_list	**tmp_data;
	int		len;

	len = 0;
	tmp_data = data;
	fill_option2(op);
	lst = *data;
	while (lst)
	{
		line = lst->content;
		while (line[len])
		{
			all_draw(op, line, &len);
		}
		op->y += 64;
		op->x = 0;
		len = 0;
		lst = lst->next;
	}
	data = tmp_data;
}

void	mlx_functions(t_op *op, t_list **data)
{
	op->mlx = mlx_init();
	op->win = mlx_new_window(op->mlx, op->res_x, op->res_y, "so_long");
	set_image(op);
	mlx_key_hook(op->win, movehook, op);
	prepare_draw(op, data);
	mlx_hook(op->win, 17, 0l, closed, op);
	mlx_loop(op->mlx);
}

int	main(int argc, char **argv)
{
	t_list	**data;
	t_op	op;

	op.wax = 0;
	op.way = 0;
	if (argc != 2)
		puterror("wrong argument | ./so_long map.ber\n");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == argv[1])
		puterror("wrong argument | ./so_long map.ber\n");
	data = malloc(sizeof(t_list *));
	read_file(argv[1], data);
	fill_op(&op, data);
	stop_wall(&op, data);
	mlx_functions(&op, data);
}
