#include "wolf3d.h"

void	ft_put_pixel_to_image(t_text *img, int x, int y, int color)
{
	static int i;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	i = x * ((*img).bpp / 8) + y * (*img).size_line;
	(*img).ptr[i]++;
	(*img).ptr[i] = (color & 0xFF);
	(*img).ptr[i + 1] = (color & 0xFF00) >> 8;
	(*img).ptr[i + 2] = (color & 0xFF0000) >> 16;
}	

void	ft_put_pixel_to_screen(t_env *e, int x, int y, int color)
{
	static int i;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	i = x * (e->bpp / 8) + y * e->size_line;
	e->pimg[i] = (color & 0xFF);
	e->pimg[i + 1] = (color & 0xFF00) >> 8;
	e->pimg[i + 2] = (color & 0xFF0000) >> 16;
}

int		ft_refresh(t_env *e)
{
	ft_update_img(e, ft_raycaster);
	return (0);
}

int 	ft_update_img(t_env *e, void f(t_env *e))
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->pimg = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), &(e->endian));
	f(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

t_text ft_getimg(t_env *e, char *path)
{
	t_text image;

	image.img = mlx_xpm_file_to_image(e->mlx, path, &(image.width), &(image.height));
	image.ptr = mlx_get_data_addr (image.img, &(image.bpp), &(image.size_line), &(image.endian));
	return (image);
}