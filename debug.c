/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:18:27 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/21 15:17:16 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	print_list(t_elem *list)
{
	ft_putchar('\n');
	while (list)
	{
		ft_printf("name : %s - id : %d - x : %d - y : %d\n", list->name, list->id, list->pos_x, list->pos_y);
		list = list->next;
	}
	ft_putchar('\n');
}