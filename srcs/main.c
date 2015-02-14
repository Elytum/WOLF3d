#include "wolf3d.h"

static int 	expose_hook(t_env *e)
{
	ft_update_img(e, ft_raycaster);
	return (0);
}

static void ft_init_env(t_env *e)
{
	e->posx = 2.5;
	e->posy = 2.5;
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->background = ft_getimg(e, "bgtest.xpm");
	e->bgx = 0;
	e->bgy = 0;
}

int		main(void)
{
	t_env			*e;

	if ((e = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		return (0);
	get_map(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Wolf-3D");
  	e->text = (t_text *)malloc(sizeof(t_text));
	ft_init_env(e);
  	*(e->text) = ft_getimg(e, "briques.xpm");
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, ft_click, e);
	mlx_hook(e->win, 2, 3, ft_updatekey, e);
	mlx_loop_hook(e->mlx, ft_refresh, e);
	mlx_loop(e->mlx);
	return (0);
}