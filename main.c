/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:20:07 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/23 20:29:47 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			my_putchar(int c)
{
	static int fd = 0;

	if (!fd)
		fd = open("/dev/tty", O_RDWR);
	if (c == -1)
		close(fd);
	write(fd, &c, 1);
	return (c);
}

void		fnc(int truc)
{
	truc = 2;
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
 
	ft_printf ("lines %d\n", w.ws_row);
	ft_printf ("columns %d\n", w.ws_col);
}

t_termios	*init_term(void)
{
	t_termios	term;
	t_termios	*ret;
	char		*name_term;

	ret = (t_termios*)malloc(sizeof(t_termios));
	tcgetattr(0, &term);
	tcgetattr(0, ret);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (NULL);
	if ((name_term = getenv("TERM")) == NULL)
		return (NULL);
	tgetent(NULL, name_term);
	return (ret);
}

int			main(int ac, char **av)
{
	t_termios	*def_term;
	t_elem		*list;
	int			i;
	char		buf[4];
	int			r;
	t_elem		*cursor;

	if ((def_term = init_term()) == NULL)
		return (0);
	i = 1;
	while(i < ac)
		add_new_elem(&list, av[i++]);
	if (find_pos(list) == 0)
	{
		ft_putstr("taille trop petite\n");
		return (0);
	}
	cursor = list;
	if (cursor)
		cursor->underline = 1;
	print_list(list);
	print_select(list);
	while ((r = read(0, buf, 3)))
	{
		buf[r] = '\0';
		if (buf[0] == 27 && buf[1] == '\0')
		{
			tputs(tgetstr("cl", NULL), 1, my_putchar);
			return (0);
		}
		if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
		{
			cursor->underline = 0;
			cursor = (cursor->next ? cursor->next : list);
			cursor->underline = 1;
		}
		if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
		{
			cursor->underline = 0;
			cursor = cursor->prec;
			cursor->underline = 1;
		}
		if (buf[0] == 127 && buf[1] == 0)
		{
			cursor = delete_elem(cursor, &list);
			if (!cursor)
				return (0);
			print_list(list);
			find_pos(list);
			print_list(list);
			cursor->underline = 1;
		}
		if (buf[0] == 32 && buf[1] == 0)
		{
			cursor->vid_inv = (cursor->vid_inv ? 0 : 1);
			cursor->underline = 0;
			cursor = (cursor->next ? cursor->next : list);
			cursor->underline = 1;
		}
		//print_select(list);
		ft_printf("%d - %d - %d\n", buf[0], buf[1], buf[2]);
	}
}

































