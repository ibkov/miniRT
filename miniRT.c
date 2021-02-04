# include <mlx.h>
# include "includes/miniRT.h"


void fg_rectangle(int x, int y, int pos_x, int pos_y, t_mlx mlx)
{
	int temp;

	temp = pos_y;
	while (pos_x++ < pos_x + x)
{
	pos_y = temp;
	while (pos_y++ < pos_y + x)
	{
		mlx.img.data[y * WIN_WIDTH + x] = 0xFFFFFF;
	}
}
}

int main()
{
int x = 400;
int y = 300;
t_mlx	mlx;

mlx.mlx_ptr = mlx_init();
	//Now do the same with mlx_new_window
mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	//One more time with mlx_new_image
mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);

mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);
fg_rectangle(100,100,100,100, mlx);


mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
mlx_loop(mlx.mlx_ptr);
return (0);
}