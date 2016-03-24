/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:33:41 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/24 19:04:32 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_elem	*norme_pos(t_elem *list, int *current_x, int *current_y, int *l_index)
{
	*current_x = 0;
	*current_y = 0;
	*l_index = 0;
	return (list);
}

t_elem	*norme_pos_2(t_elem *list, int current_x, int *current_y)
{
	list->pos_x = current_x;
	list->pos_y = *current_y;
	*current_y = *current_y + 1;
	return (list->next);
}
