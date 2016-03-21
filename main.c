/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:20:07 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/21 15:34:41 by jcamhi           ###   ########.fr       */
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
	print_list(list);
	print_select(list);
	while (1);
}

//tputs(tgoto(tgetstr("cm", NULL), 20, 30), 1, my_putchar);

































