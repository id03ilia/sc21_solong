#include "so_long.h"

void	analize_map(t_list	*base, int x, int y)
{
	while (base->map[y])
	{
		x = 0;
		while (base->map[y][x])
		{
			if (base->map[y][x] == 'C')
				base->onecoin++;
			if (base->map[y][x] == 'P')
			{
				base->indiana++;
				base->posI_y = y;
				base->posI_x = x;
			}
			if (base->map[y][x] != '0' && base->map[y][x] != '1'
			&& base->map[y][x] != 'E' && base->map[y][x] != 'C'
			&& base->map[y][x] != 'P')
				game_over(base, 1);
			if (base->map[y][x] == 'E')
				base->exitg++;
			x++;
		}
		y++;
	}
	base->map_y = y;
	base->map_x = x;
}

static void	check_empty_line2(int y, t_list *base)
{
	if (y != base->height)
		game_over(base, 8);
}

void	proverka(t_list *base, int max_x, int max_y)
{
	int	x;
	int	y;

	if ((max_x > 327) || (max_y > 327))
		game_over(base, 1);
	if (base->exitg < 1 || base->indiana != 1 || base->onecoin < 1)
		game_over(base, 7);
	y = 0;
	while (y < max_y)
	{
		if (ft_strlen(base->map[0]) != ft_strlen(base->map[y]))
			game_over(base, 4);
		x = 0;
		while (x < max_x)
		{
			if ((base->map[0][x] != '1') || (base->map[max_y - 1][x] != '1'))
				game_over(base, 1);
			if ((base->map[y][0] != '1') || (base->map[y][max_x - 1] != '1'))
				game_over(base, 1);
			x++;
		}
		y++;
	}
	check_empty_line2(y, base);
}
