#include "mlx_linux/mlx.h"
#include <stdio.h>

int print_key(int key)
{
    printf("key = %d\n", key);
    return (0);
}

int main(void)
{
    void    *mlx;
    void    *window;
    int     x;
    int     y;

    x = 100;
    mlx = mlx_init();
    window = mlx_new_window(mlx, 650, 650, "so_long");
    while (x < 200)
    {
        y = 100;
        while (y < 500)
        {
            if (x < 125 || x > 175 || y < 125 || y > 475)
            mlx_pixel_put(mlx, window, x, y, 0xAAAAAA);
            y++;
        }
        x++;
    }
    mlx_key_hook(window, print_key, NULL);
	mlx_loop(mlx);
}