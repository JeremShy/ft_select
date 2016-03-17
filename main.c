/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:20:07 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/17 20:48:12 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int				my_putchar(int c)
{
	static int fd = 0;

	if (!fd)
		fd = open("/dev/tty", O_RDWR);
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

int              main()
{
	struct termios	term;
	char			*name_term;
	//	char			buff[4];
	//	int				r;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	tgetent(NULL, name_term);
	fnc(0);
	signal(28, fnc);
	//	char	*cl_n = tgetstr("cl", NULL);
	tputs(tgoto(tgetstr("cm", NULL), 20, 30), 1, my_putchar);
	tputs(tgetstr("us", NULL), 1, my_putchar);
	tputs(tgetstr("mr", NULL), 1, my_putchar);
	ft_printf("caca\n");
	tputs(tgetstr("ue", NULL), 1, my_putchar);
	tputs(tgetstr("me", NULL), 1, my_putchar);
	ft_printf("caca\n");
	// 	tputs(cl_n, 0, my_putchar);
	/*	while((r = read(0, buff, 3)))
		{
		ft_printf("buff[0] : %d\n", buff[0]);
		if (buff[0] == 27)
		{
		ft_printf("buff[1] : %d\n", buff[1]);
		ft_printf("buff[2] : %d\n", buff[2]);
		}
		ft_putchar('\n');
		}*/
	return (0);
}










































