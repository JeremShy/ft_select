/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:01:53 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/23 19:03:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_elem	*find_elem(t_elem *list, int index)
{
	while (list)
	{
		if (list->id == index)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_elem *delete_elem(t_elem *list, t_elem **modif)
{
	t_elem *next;

	next = list->next;
	if (!list->prec)
	{
		if(next)
			*modif = next;
		else
			return (NULL);
	}
	if (list->prec)
		(list->prec)->next = list->next;
	if (list->next)
		(list->next)->prec = list->prec;
	free(list->name);
	free(list);
	return (next);
}