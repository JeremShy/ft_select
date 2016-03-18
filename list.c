/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:05:05 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/18 15:24:29 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static t_elem	*create_elem(char *name)
{
	t_elem						*ret;
	static unsigned long long	id = 0;

	ret = (t_elem*)malloc(sizeof(t_elem));
	ret->name = ft_strdup(name);
	ret->pos_x = 0;
	ret->pos_y = 0;
	ret->underline = 0;
	ret->vid_inv = 0;
	ret->id = id;
	id++;
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
		*list = create_elem(name);
		return ;
	}
	ptr = *list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = create_elem(name);
}