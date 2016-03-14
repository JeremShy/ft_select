/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:20:07 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/14 09:20:09 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int main(void)
{
	struct termios	term;

	tgetent(NULL, getenv("TERM"));
	tcgetattr(0, &term);
	
	term.c_cc[VTIME] = 0;
	term.c_cc[VMIN] = 1;
	term.c_lflag &= ~ (ICANON);
	tcsetattr(0, TCSANOW, &term);
	return (0);
}