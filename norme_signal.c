/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 20:15:49 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/24 20:33:35 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	sig_ttou(int sig)
{
	t_termios	*def_term;
	t_elem		*list;

	def_term = singelton_termios(NULL);
	list = singelton_list(NULL);
	sig = 0;
	tcsetattr(0, TCSADRAIN, def_term);
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	delete_list(list);
	exit(EXIT_FAILURE);
}
