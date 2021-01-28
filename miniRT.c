# include <mlx.h>
# include "includes/miniRT.h"

int main()
{
int x = 20;
int y = 200;
t_mlx	mlx;

mlx.mlx_ptr = mlx_init();
	//Now do the same with mlx_new_window
mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	//One more time with mlx_new_image
mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);
while (x < 200)
{
    mlx.img.data[x * WIN_WIDTH + y] = 0xFFFFFF;
    x++;
}


mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
mlx_loop(mlx.mlx_ptr);
return (0);
}