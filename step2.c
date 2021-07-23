#include "so_long.h"

static void	step2(t_list *base, int x, int y)
{
	base->map[(base->posI_y + y)][(base->posI_x + x)] = 'P';
	base->map[base->posI_y][base->posI_x] = '0';
	base->posI_x = base->posI_x + x;
	base->posI_y = base->posI_y + y;
	base->counter++;
	wrt_counter(base);
}

void	step(t_list *base, int x, int y)
{
	int		img_width;
	int		img_height;

	if (base->map[(base->posI_y + y)][(base->posI_x + x)] != '1')
	{
		if (base->map[(base->posI_y + y)][(base->posI_x + x)] == 'C')
		{
			base->onecoin--;
			step2(base, x, y);
		}
		if ((base->map[(base->posI_y + y)][(base->posI_x + x)] == 'E')
			&& (base->onecoin == 0))
		{
			base->counter++;
			wrt_counter(base);
			game_over(base, 5);
		}
		if (base->map[(base->posI_y + y)][(base->posI_x + x)] == '0')
			step2(base, x, y);
		if (base->onecoin == 0)
			base->img_exit = mlx_xpm_file_to_image(base->mlx,
					"./exit.xpm", &img_width, &img_height);
		map_write(base, 0, 0);
	}
}

int	key(int button, t_list *base)
{
	if (button == 13)
		step(base, 0, -1);
	else if (button == 1)
		step(base, 0, 1);
	else if (button == 2)
		step(base, 1, 0);
	else if (button == 0)
		step(base, -1, 0);
	else if (button == 53)
		game_over(base, 0);
	return (0);
}
