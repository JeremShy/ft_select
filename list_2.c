/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:01:53 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/21 21:12:49 by jcamhi           ###   ########.fr       */
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