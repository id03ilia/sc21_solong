#include "so_long.h"

void	initialization(t_list *base)
{
	base->fd = -1;
	base->onecoin = 0;
	base->indiana = 0;
	base->exitg = 0;
	base->in = 50;
	base->counter = 0;
	base->posI_y = 0;
	base->posI_x = 0;
}

void	init_img(t_list *base)
{
	int		w;
	int		h;

	base->img_indi = mlx_xpm_file_to_image(base->mlx, "./indi.xpm", &w, &h);
	base->img_fon = mlx_xpm_file_to_image(base->mlx, "./fon2.xpm", &w, &h);
	base->img_wall = mlx_xpm_file_to_image(base->mlx, "./wall.xpm", &w, &h);
	base->img_coin = mlx_xpm_file_to_image(base->mlx, "./coin.xpm", &w, &h);
	base->img_exit = mlx_xpm_file_to_image(base->mlx, "./exit1.xpm", &w, &h);
}

int	map_write(t_list *base, int	x, int y)
{
	while (base->map[y])
	{
		x = 0;
		while (base->map[y][x])
		{
			if (base->map[y][x] == 'C')
				mlx_put_image_to_window(base->mlx,
					base->win, base->img_coin, x * base->in, y * base->in);
			if (base->map[y][x] == 'P')
				mlx_put_image_to_window(base->mlx,
					base->win, base->img_indi, x * base->in, y * base->in);
			if (base->map[y][x] == 'E')
				mlx_put_image_to_window(base->mlx,
					base->win, base->img_exit, x * base->in, y * base->in);
			if (base->map[y][x] == '0')
				mlx_put_image_to_window(base->mlx,
					base->win, base->img_fon, x * base->in, y * base->in);
			if (base->map[y][x] == '1')
				mlx_put_image_to_window(base->mlx,
					base->win, base->img_wall, x * base->in, y * base->in);
			x++;
		}
		y++;
	}
	return (0);
}
