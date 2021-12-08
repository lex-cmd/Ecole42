/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:18:41 by fcarl             #+#    #+#             */
/*   Updated: 2021/08/01 10:18:42 by fcarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_wrongsymb(char *line)
{
	int		len;
	int		i;
	char	*str;

	str = "234567890:;<=>?@ABDFGHIJKLMNOfghIJKLMNO";
	i = 0;
	len = 0;
	while (line[len])
	{
		if (line[len] < '0' || line[len] > 'P')
			puterror("Wrong symbol\n");
		while (str[i])
		{
			if (str[i] == line[len])
				puterror("Wrong symbol\n");
			i++;
		}
		len++;
	}
}

void	parsing_map(t_list **data)
{
	t_list	*tmp;

	tmp = *data;
	while (tmp)
	{
		search_wrongsymb(tmp->content);
		tmp = tmp->next;
	}
}

void	read_file(char *file_name, t_list **data)
{
	int		fd;
	char	*line;
	t_list	*temp;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	*data = ft_lstnew(line);
	while (get_next_line(fd, &line))
	{
		temp = ft_lstnew(line);
		ft_lstadd_back(data, temp);
	}
	free(line);
	parsing_map(data);
}
