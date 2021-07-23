#include "so_long.h"

static int	map_lengs(t_list *base)
{
	int		fd_res;
	int		len;
	char	buf;

	len = 0;
	fd_res = read(base->fd, &buf, 1);
	while (fd_res > 0)
	{
		len++;
		fd_res = read(base->fd, &buf, 1);
	}
	if (fd_res < 0 && len == 0)
		game_over(base, 6);
	close(base->fd);
	return (len);
}

static void	check_empty_line(char *tmp, t_list *base)
{
	base->height = 1;
	while (*tmp)
	{
		if (*tmp == '\n')
			base->height++;
		tmp++;
	}
}

static void	check_ber(char *str, t_list *base)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r')
			{
				i = -1;
				break ;
			}
			else
				game_over(base, 9);
		}
		i++;
	}
	if (i > 0)
		game_over(base, 9);
}

static void	pars(int argc, char **argv, t_list *base)
{
	char	*tmp_map;
	int		ret;
	int		len;

	if (argc == 2)
		base->fd = open(argv[1], O_RDONLY);
	else
		game_over(base, 2);
	check_ber(argv[1], base);
	len = map_lengs(base);
	tmp_map = malloc(len);
	if (tmp_map == NULL)
		error (3);
	base->fd = open(argv[1], O_RDONLY);
	ret = read(base->fd, tmp_map, len);
	if (ret < 0)
		game_over(base, 6);
	close (base->fd);
	tmp_map[len] = '\0';
	check_empty_line(tmp_map, base);
	base->map = ft_split(tmp_map, '\n');
	free(tmp_map);
	if (base->map == NULL)
		game_over(base, 3);
}

int	main(int argc, char **argv)
{
	t_list	base;

	base.fd = -1;
	initialization(&base);
	pars(argc, argv, &base);
	analize_map(&base, 0, 0);
	proverka(&base, base.map_x, base.map_y);
	base.mlx = mlx_init();
	base.win = mlx_new_window(base.mlx,
			base.map_x * base.in, base.map_y * base.in, "So long");
	init_img(&base);
	map_write(&base, 0, 0);
	mlx_key_hook(base.win, key, &base);
	mlx_hook(base.win, 17, 0, game_over, &base);
	mlx_loop(base.mlx);
	return (0);
}
