

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include "./mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

/*
 Here I built a struct of the MLX image :
 It contains everything you need.
 - img_ptr to store the return value of mlx_new_image
 - data to store the return value of mlx_get_data_addr
 - the 3 other variables are pretty much useless, but you'll need
 them in the prototype of mlx_get_data_addr (see the man page for that)
 */
typedef struct	s_img
{
	void		*img_ptr;
	int			*data; 
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	p_gmr
{
	double 		posX;
	double 		posY;
	double		dirX;
	double      dirY;
	double		planeX;
	double		planeY;
	
}				pos_gamer;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	pos_gamer	pos;
}				t_mlx;


#endif
