/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:20:07 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/24 20:00:30 by jcamhi           ###   ########.fr       */
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

void		end_prog_with_output(t_elem *list)
{
	char				*buff;
	t_termios			*def_term;
	t_elem				*save;

	save = list;
	def_term = singelton_termios(NULL);
	tcsetattr(0, TCSADRAIN, def_term);
	free(def_term);
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	buff = ft_strdup("");
	while (list)
	{
		if (list->vid_inv)
		{
			buff = ft_strjoinaf1(buff, list->name);
			if (is_not_last(list->next))
				buff = ft_strjoinaf1(buff, " ");
		}
		list = list->next;
	}
	ft_putstr(buff);
	delete_list(save);
	free(buff);
	exit(EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
	t_elem				*list;
	int					i;
	t_elem				*cursor;

	if (singelton_termios(init_term()) == NULL)
		return (0);
	i = 1;
	if (ac == 1)
		ft_printf("Wrong usage : %s file [...]\n", av[0]);
	while (i < ac)
		add_new_elem(&list, av[i++]);
	if (ac != 1 && !list)
		ft_printf("Error while creating list.\n");
	if (!list || ac == 1)
		return (0);
	list->i = find_pos(list);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	signal_handler();
	cursor = list;
	cursor->underline = 1;
	print_select(list);
	singelton_list(list);
	boucle(list, cursor);
}
