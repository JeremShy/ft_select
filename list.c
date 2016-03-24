/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:05:05 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/24 15:25:34 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int		find_max(t_elem *list, int l_index, int index)
{
	int max;

	max = -1;
	while (list && list->id != l_index)
		list = list->next;
	if (!list)
	{
		ft_printf("first index not found\n");
		return (-1);
	}
	while (list && list->id != index)
	{
		if ((int)ft_strlen(list->name) > max)
			max = ft_strlen(list->name);
		list = list->next;		
	}
	return (max);
}

int			ft_verif(t_elem *list, int col)
{
	while (list)
	{
		if ((int)ft_strlen(list->name) + list->pos_x > col)
			return (0);
		list = list->next;
	}
	return (1);
}

int			find_pos(t_elem *list)
{
	int				current_x;
	int				current_y;
	struct winsize	w;
	int				l_index;
	t_elem			*save;

	ioctl(0, TIOCGWINSZ, &w);
	save = list;
	current_x = 0;
	current_y = 0;
	l_index = 0;
	while (list)
	{
		l_index = list->id;
		while (list && current_y < w.ws_row - 1)
		{
			list->pos_x = current_x;
			list->pos_y = current_y;
			current_y++;
			list = list->next;
		}
		if (!list)
			return (ft_verif(save, w.ws_col));
		current_x = current_x + find_max(save, l_index, list->id) + 2;
		if (current_x > w.ws_col - 1)
			return (0);
		current_y = 0;
	}
	return (ft_verif(save, w.ws_col));
}

static t_elem	*create_elem(char *name, t_elem *prec)
{
	t_elem		*ret;
	static int	id = 0;

	ret = (t_elem*)malloc(sizeof(t_elem));
	ret->name = ft_strdup(name);
	ret->pos_x = 0;
	ret->pos_y = 0;
	ret->underline = 0;
	ret->vid_inv = 0;
	ret->id = id;
	id++;
	ret->prec = prec;
	ret->next = NULL;
	return (ret);
}

void 			add_new_elem(t_elem **list, char *name)
{
	t_elem	*ptr;

	if (!list)
		return ;
	if (!*list)
	{
		*list = create_elem(name, NULL);
		return ;
	}
	ptr = *list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = create_elem(name, ptr);
}