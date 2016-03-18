/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:14:58 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/18 15:27:35 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <ft_printf.h>
# include <curses.h>
# include <term.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <signal.h>

typedef struct	termios t_termios;
typedef struct	s_elem
{
	char			*name;
	int				vid_inv;
	int				underline;
	int				pos_x;
	int				pos_y;
	int				id;
	struct s_elem	*next;
}				t_elem;

void 			add_new_elem(t_elem **list, char *name);
void			print_list(t_elem *list);

#endif
