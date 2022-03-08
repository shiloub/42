#include "so_long.h"


int    fonction(int key, t_game *game)
{
	if (key ==	65362 || key == 65364 || key == 65361 || key == 65363)
	{
		if (key == 65363)
			go_right(game->map);
		else if (key == 65361)
			go_left(game->map);
		else if (key == 65362)
			go_down(game->map);
		else if (key == 65364)
			go_up(game->map);
	}
	open_door_if_necessary(game->map);
	if (no_door(game->map))
		exit_game(game);
	print_map(game);
	return (0);
}


int main(int ac, char **av)
{
	t_game *game;

	game = set_game(av[1]);
	print_map(game);
	mlx_key_hook(game->win, fonction, game);
	mlx_loop(game->mlx);
	return 0;
}