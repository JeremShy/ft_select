/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:19:31 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/23 19:12:07 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	my_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		my_putchar(str[i]);
		i++;
	}
}

void	print_select(t_elem *list)
{
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	while (list)
	{
		tputs(tgoto(tgetstr("cm", NULL), list->pos_x, list->pos_y), 1, my_putchar);
		if (list->underline)
			tputs(tgetstr("us", NULL), 1, my_putchar);
		if (list->vid_inv)
			tputs(tgetstr("mr", NULL), 1, my_putchar);
		my_putstr(list->name);
		if (list->vid_inv)
			tputs(tgetstr("me", NULL), 1, my_putchar);
		if (list->underline)
			tputs(tgetstr("ue", NULL), 1, my_putchar);
		if (list->next)
			my_putchar('\n');
		list = list->next;
	}
}

//tputs(tgoto(tgetstr("cm", NULL), 20, 30), 1, my_putchar);