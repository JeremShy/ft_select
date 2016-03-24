/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singelton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 19:18:04 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/24 19:34:40 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_elem			*singelton_list(t_elem *list)
{
	static t_elem *e = NULL;

	if (list)
		e = list;
	return (e);
}

struct termios	*singelton_termios(struct termios *termios)
{
	static struct termios *e = NULL;

	if (termios)
		e = termios;
	return (e);
}
