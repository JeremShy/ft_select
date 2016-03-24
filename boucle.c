/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:46:17 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/24 19:35:57 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int	haut_bas(t_elem *list, t_elem **cursor, char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66 && buf[3] == 0)
	{
		(*cursor)->underline = 0;
		(*cursor) = ((*cursor)->next ? (*cursor)->next : list);
		(*cursor)->underline = 1;
		return (1);
	}
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65 && buf[3] == 0)
	{
		(*cursor)->underline = 0;
		(*cursor) = ((*cursor)->prec ? (*cursor)->prec : list_end(list));
		(*cursor)->underline = 1;
		return (1);
	}
	return (0);
}

static int	gauche_droite(t_elem *list, t_elem **cursor, char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0)
	{
		(*cursor)->underline = 0;
		(*cursor) = get_right_cursor(*cursor, list);
		(*cursor)->underline = 1;
		return (1);
	}
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0)
	{
		(*cursor)->underline = 0;
		(*cursor) = get_left_cursor(*cursor, list);
		(*cursor)->underline = 1;
		return (1);
	}
	return (0);
}

static int	select_elem(t_elem *list, t_elem **cursor, char *buf)
{
	if (buf[0] == 32 && buf[1] == 0)
	{
		(*cursor)->vid_inv = ((*cursor)->vid_inv ? 0 : 1);
		(*cursor)->underline = 0;
		(*cursor) = ((*cursor)->next ? (*cursor)->next : list);
		(*cursor)->underline = 1;
		return (1);
	}
	return (0);
}

void		boucle(t_elem *list, t_elem *cursor)
{
	int				r;
	char			buf[5];

	while ((r = read(0, buf, 4)))
	{
		buf[r] = '\0';
		if (buf[0] == 27 && buf[1] == '\0')
			end_prog_without_output(0);
		haut_bas(list, &cursor, buf);
		if ((buf[0] == 127 && buf[1] == 0) ||
				(buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126))
		{
			cursor = delete_elem(cursor, &list);
			if (!cursor)
				end_prog_without_output(0);
			list->i = find_pos(list);
			cursor->underline = 1;
		}
		select_elem(list, &cursor, buf);
		gauche_droite(list, &cursor, buf);
		if (buf[0] == 10 && buf[1] == 0)
			end_prog_with_output(list);
		print_select(list);
	}
}
