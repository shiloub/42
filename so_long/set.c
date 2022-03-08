#include "so_long.h"

t_game	*set_game(char *map_path)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->map = set_map(map_path);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map_width(game->map), map_height(game->map), "slt l'equipe");
	game->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &game->img_width, &game->img_height);
	game->door = mlx_xpm_file_to_image(game->mlx, "door.xpm", &game->img_width, &game->img_height);
	game->robot = mlx_xpm_file_to_image(game->mlx, "robot.xpm", &game->img_width, &game->img_height);
	game->ground = mlx_xpm_file_to_image(game->mlx, "ground.xpm", &game->img_width, &game->img_height);
	game->fruit = mlx_xpm_file_to_image(game->mlx, "fruit.xpm", &game->img_width, &game->img_height);
	game->door_open = mlx_xpm_file_to_image(game->mlx, "door_open.xpm", &game->img_width, &game->img_height);

	game->x = malloc(sizeof(int));
	game->y = malloc(sizeof(int));
	*game->x = 0;
	*game->y = 0;
	return (game);
}

int	map_width(char **map)
{
	int	i;

	i = 0;
	if (!map[0])
		return 0;
	while (map[0][i])
		i++;
	return (i * 24);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i * 24);
}