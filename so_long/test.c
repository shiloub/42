#include "mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_texture
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_height;
	int		img_width;
	int		x;
	int		y;
}	t_texture;

int print_key(int key, t_texture *wall)
{
	t_texture	ground;

	ground.img = mlx_xpm_file_to_image(wall->mlx, "ground.xpm", &wall->img_width, &wall->img_height);
	mlx_put_image_to_window(wall->mlx, wall->win, ground.img, wall->x, wall->y);

	if (key ==	65362 || key == 65364 || key == 65361 || key == 65363)
	{
		if (key == 65363)
			wall->x = wall->x + wall->img_width;
		else if (key == 65361)
			wall->x = wall->x - wall->img_width;
		else if (key == 65362)
			wall->y = wall->y - wall->img_height;
		else if (key == 65364)
			wall->y = wall->y + wall->img_height;
		mlx_put_image_to_window(wall->mlx, wall->win, wall->img, wall->x, wall->y);
	}
	return (0);
}

int main(void)
{
	t_texture	ground;

	ground.mlx = mlx_init();
	mlx_destroy_display(ground.mlx);
	free(ground.mlx);
	
}