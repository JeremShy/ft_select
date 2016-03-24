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


int main(int ac, char **av)
{
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	return (0);
}
