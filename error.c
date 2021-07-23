#include "so_long.h"

void	error(int i)
{
	if (i == 1)
		write(1, "Error\n-map error\n", 17);
	if (i == 2)
		write(1, "Error\n-count argument\n", 22);
	if (i == 3)
		write(1, "Error\n-memory fail\n", 19);
	if (i == 4)
		write(1, "Error\n-the map is not even\n", 28);
	if (i == 5)
		write(1, "You WIN!\n", 9);
	if (i == 6)
		write(1, "Error\n-read fail\n", 17);
	if (i == 7)
		write(1, "Error\n-map not rule\n", 20);
	if (i == 8)
		write(1, "Error\n-empty line\n", 18);
	if (i == 9)
		write(1, "Error\n-not .ber\n", 16);
}

int	game_over(t_list *base, int i)
{
	int	y;

	if (i)
		error(i);
	if (base->mlx)
	{
		if (base->win)
			mlx_destroy_window(base->mlx, base->win);
	}
	y = 0;
	if (base->map && i != 9 && i != 2 && i != 6)
	{
		while (base->map[y])
		{
			free(base->map[y]);
			base->map[y] = NULL;
			y++;
		}
		free(base->map);
		base->map = NULL;
	}
	exit(0);
}
