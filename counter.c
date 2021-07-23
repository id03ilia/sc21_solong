#include "so_long.h"

static void	ft_putchar(char	c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr(-214748364, fd);
		ft_putchar('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar('-', fd);
		ft_putnbr(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, fd);
		ft_putchar(48 + n % 10, fd);
	}
}

void	wrt_counter(t_list *base)
{
	write(1, "counter:", 8);
	ft_putnbr(base->counter, 1);
	write(1, "\n", 1);
}
