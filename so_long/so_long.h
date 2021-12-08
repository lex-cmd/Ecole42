/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:18:49 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/01 10:18:50 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "miniLibX/mlx.h"

typedef struct s_op
{
	int		fl_c;
	char	*ct_n;
	int		ct_s;
	int		*tmp_x;
	int		*tmp_y;
	int		gocha;
	int		colx;
	int		lencx;
	int		lency;
	int		*col_y;
	int		*col_x;
	int		save_x;
	int		save_y;
	int		size_x;
	int		size_y;
	t_list	**data;
	int		*sp_walx;
	int		*sp_waly;
	int		wax;
	int		way;
	int		stx;
	int		sty;
	int		flag;
	int		len_x;
	int		len_y;
	char	*ph_s;
	char	*ph_t;
	char	*ph_b;
	char	*ph_l;
	char	*ph_r;
	char	*ph_w;
	char	*ph_g;
	char	*ph_c;
	char	*ph_cl;
	int		mw;
	int		md;
	int		cw;
	int		cd;
	int		exit_x;
	int		exit_y;
	int		x;
	int		y;
	int		wh;
	int		ht;
	void	*mlx;
	void	*win;
	void	*img;
	void	*ig_g;
	void	*ig_cl;
	void	*ig_c;
	void	*ig_w;
	void	*ig_t;
	void	*ig_b;
	void	*ig_l;
	void	*ig_r;
	int		res_x;
	int		res_y;
}				t_op;

void	fill_option2(t_op *op);
void	all_draw(t_op *op, char *line, int *len);
void	draw_grass(t_op *op);
void	draw_collect(t_op *op);
void	draw_playa(t_op *op);
void	draw_wall(t_op *op);
void	eat_some_col(t_op *op);
void	fill_op(t_op *op, t_list **data);
void	keyhook(int	keycode);
int		wall_stoping(t_op *op);
void	stop_wall(t_op *op, t_list **data);
void	prepare_draw(t_op *op, t_list **data);
int		movehook(int keycode, t_op *op);
void	read_file(char *file_name, t_list **data);
void	parsing_map(t_list **data);
void	search_wrongsymb(char *line);
void	puterror(char *line);

#endif