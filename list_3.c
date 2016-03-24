/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:58:03 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/24 18:45:54 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_elem	*get_right_cursor(t_elem *cursor, t_elem *list)
{
	int y;

	y = cursor->pos_y;
	cursor = cursor->next;
	while (cursor)
	{
		if (cursor->pos_y == y)
			return (cursor);
		cursor = cursor->next;
	}
	while (list)
	{
		if (list->pos_y == y)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_elem	*get_left_cursor(t_elem *cursor, t_elem *list)
{
	int y;

	y = cursor->pos_y;
	cursor = cursor->prec;
	while (cursor)
	{
		if (cursor->pos_y == y)
			return (cursor);
		cursor = cursor->prec;
	}
	while (list->next)
		list = list->next;
	while (list)
	{
		if (list->pos_y == y)
			return (list);
		list = list->prec;
	}
	return (NULL);
}
