/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:41:58 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/24 20:33:52 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		end_prog_without_output(int sig)
{
	t_termios	*def_term;
	t_elem		*list;

	def_term = singelton_termios(NULL);
	list = singelton_list(NULL);
	sig = 0;
	tcsetattr(0, TCSADRAIN, def_term);
	free(def_term);
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	delete_list(list);
	exit(EXIT_FAILURE);
}

void		handle_winch(int sig)
{
	t_elem *list;

	list = singelton_list(NULL);
	sig = 0;
	list->i = find_pos(list);
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	print_select(list);
}

void		sig_pause(int sig)
{
	t_termios	*def_term;

	def_term = singelton_termios(NULL);
	sig = 0;
	tcsetattr(0, TCSADRAIN, def_term);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, "\032");
}

void		sig_cont(int sig)
{
	t_elem		*list;
	t_termios	*truc;

	sig = 0;
	list = singelton_list(NULL);
	signal(SIGTSTP, sig_pause);
	free(singelton_termios(NULL));
	truc = init_term();
	if (truc == NULL)
		exit(0);
	singelton_termios(truc);
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	find_pos(list);
	print_select(list);
}

void		signal_handler(void)
{
	int	i;

	i = 1;
	while (i < 28)
	{
		if (i != SIGKILL && i != SIGSTOP && i != SIGCONT &&
			i != SIGCHLD && i != SIGTSTP && i != SIGWINCH && i != SIGTTOU)
			signal(i, end_prog_without_output);
		else if (i == SIGTSTP)
			signal(i, sig_pause);
		else if (i == SIGCONT)
			signal(i, sig_cont);
		else if (i == SIGTTOU)
			signal(i, sig_ttou);
		i++;
	}
	signal(SIGWINCH, handle_winch);
}
