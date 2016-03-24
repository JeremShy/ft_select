/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:14:58 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/24 15:35:59 by jcamhi           ###   ########.fr       */
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

struct termios	*def_term;
struct s_elem	*list;

typedef struct	termios t_termios;
typedef struct	s_elem
{
	char			*name;
	int				vid_inv;
	int				underline;
	int				pos_x;
	int				pos_y;
	int				id;
	int				i;
	struct s_elem	*next;
	struct s_elem	*prec;
}				t_elem;

void 			add_new_elem(t_elem **list, char *name);
void			print_list(t_elem *list);
int				find_pos(t_elem *list);
int				my_putchar(int c);
void			print_select(t_elem *list);
t_elem			*find_elem(t_elem *list, int index);
t_elem			*delete_elem(t_elem *list, t_elem **modif);
t_elem			*list_end(t_elem *list);
void			delete_list(t_elem *list);
void			signal_handler(void);
void			end_prog_without_output(int sig);
t_termios		*init_term(void);
int				is_not_last(t_elem *list);
#endif
