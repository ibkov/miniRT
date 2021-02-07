# include <mlx.h>
# include "includes/miniRT.h"
# include <math.h>
# include <stdio.h> 

#define mapWidth 24
#define mapHeight 24
// int worldMap[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1},
//   {1,0,0,2,0,1},
//   {1,0,0,0,0,1},
//   {1,0,0,0,0,1},
//   {1,0,1,1,0,1},
//   {1,1,1,1,1,1},
// };


int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void verLine(int x, int drawStart, int drawEnd, int color, t_mlx mlx)
{
    while (drawStart < drawEnd)
    {
        mlx.img.data[drawStart * WIN_WIDTH + x] = color;
        drawStart++;
    }
}

int draw_ray_casting(pos_gamer *pos, t_mlx mlx)
{
  for(int x = 0; x < WIN_WIDTH; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)WIN_WIDTH - 1; //x-coordinate in camera space
      double rayDirX = pos->dirX + pos->planeX * cameraX;
      double rayDirY = pos->dirY + pos->planeY * cameraX;
      //which box of the map we're in
      int mapX = (int)(pos->posX);
      int mapY = (int)(pos->posY);

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = fabs(1 / rayDirX);
      double deltaDistY = fabs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (pos->posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - pos->posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (pos->posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - pos->posY) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(worldMap[mapX][mapY] > 0) hit = 1;
      }
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if(side == 0) perpWallDist = (mapX - pos->posX + (1 - stepX) / 2) / rayDirX;
      else          perpWallDist = (mapY - pos->posY + (1 - stepY) / 2) / rayDirY;

      //Calculate height of line to draw on screen
      int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
      if(drawEnd >= WIN_HEIGHT)drawEnd = WIN_HEIGHT - 1;

      //choose wall color
      int color = 0xFFFFFF;
      int red_color = 0xff3333;
      int green_color = 0x339933;
      int blue_color = 0x3366cc;
      int yellow_color = 0xffff55;
      if (worldMap[mapX][mapY] == 1)
        color = red_color;
      if (worldMap[mapX][mapY] == 2)
        color = green_color;
      if (worldMap[mapX][mapY] == 3)
        color = blue_color;
      if (worldMap[mapX][mapY] == 4)
        color = 0xFFFFFF; 
      if (worldMap[mapX][mapY] == 4)
        color = yellow_color; 
    //   switch(worldMap[mapX][mapY])
    //   {
    //     case 1:  color = RGB_Red;    break; //red
    //     case 2:  color = RGB_Green;  break; //green
    //     case 3:  color = RGB_Blue;   break; //blue
    //     case 4:  color = RGB_White;  break; //white
    //     default: color = RGB_Yellow; break; //yellow
    //   }

      //give x and y sides different brightness
      if(side == 1) {color = red_color / 2;}
      if(side == 2) {color = green_color / 1.2;}
      if(side == 3) {color = blue_color / 1.2;}
      if(side == 4) {color = 0xFFFFFF / 1.2;}
      if(side == 5) {color = yellow_color / 1.2;}

      //draw the pixels of the stripe as a vertical line
      verLine(x, drawStart, drawEnd, color, mlx);
    }
    return (0);
}

int close(int keycode, pos_gamer *pos)
{
    if (keycode == 126)
    {
      pos->posX++;
      // mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
    }
    return(0);
}

void init_position(pos_gamer *pos)
{
  pos->posX = 22;
  pos->posY = 12;  //x and y start position
  pos->dirX = -1;
  pos->dirY = 0; //initial direction vector
  pos->planeX = 0; 
  pos->planeY = 0.66; //the 2d raycaster version of camera plane
}

int main()
{
pos_gamer pos;
t_mlx	mlx;
init_position(&pos);
// double time = 0; //time of current frame
// double oldTime = 0; //time of previous frame

mlx.mlx_ptr = mlx_init();
	//Now do the same with mlx_new_window
mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	//One more time with mlx_new_image
mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);

mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);
while(1){
draw_ray_casting(&pos, mlx);
mlx_hook(mlx.win, 2, 1L<<0, close, &pos);
mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
mlx_clear_window(mlx.mlx_ptr, mlx.win);
// mlx_hook(mlx.win, 2, 1L<<0, close, &posX);
mlx_loop(mlx.mlx_ptr);
}
return (0);
}