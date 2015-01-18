#include "wolf3d.h"

void	left(t_env *e)
{
	static double		olddirx;
	static double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(RS) - e->diry * sin(RS);
	e->diry = olddirx * sin(RS) + e->diry * cos(RS);
	oldplanex = e->planex;
	e->planex = e->planex * cos(RS) - e->planey * sin(RS);
	e->planey = oldplanex * sin(RS) + e->planey * cos(RS);
	e->bgx -= e->background.width * RS / 6.2;
}

void	right(t_env *e)
{
	static double		olddirx;
	static double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(-RS) - e->diry * sin(-RS);
	e->diry = olddirx * sin(-RS) + e->diry * cos(-RS);
	oldplanex = e->planex;
	e->planex = e->planex * cos(-RS) - e->planey * sin(-RS);
	e->planey = oldplanex * sin(-RS) + e->planey * cos(-RS);
	e->bgx += e->background.width * RS / 6.2;
}

void	down(t_env *e)
{
	if (e->map[(int)(e->posy - e->diry * MS)][(int)(e->posx)] == '0')
		e->posy -= e->diry * MS;
	if (e->map[(int)(e->posy)][(int)(e->posx - e->dirx * MS)] == '0')
		e->posx -= e->dirx * MS;
}

void	up(t_env *e)
{
	if (e->map[(int)(e->posy + e->diry * MS)][(int)(e->posx)] == '0')
		e->posy += e->diry * MS;
	if (e->map[(int)(e->posy)][(int)(e->posx + e->dirx * MS)] == '0')
		e->posx += e->dirx * MS;
}

void	strafe_left(t_env *e)
{
	if (e->map[(int)(e->posy - e->planey * MS)][(int)(e->posx)] == '0')
		e->posy -= e->planey * MS;
	if (e->map[(int)(e->posy)][(int)(e->posx - e->planex * MS)] == '0')
		e->posx -= e->planex * MS;
}

void	strafe_right(t_env *e)
{
	if (e->map[(int)(e->posy + e->planey * MS)][(int)(e->posx)] == '0')
		e->posy += e->planey * MS;
	if (e->map[(int)(e->posy)][(int)(e->posx + e->planex * MS)] == '0')
		e->posx += e->planex * MS;
}

int			ft_updatekey(int key, t_env *e)
{
	if (key == 65307) // esc
	{
		ft_putendl("We hope to see you once again very soon.\nPS : The cake is a lie");
		exit (0);
	}
	if (key == W)
		up(e);
	if (key == S)
		down(e);
	if (key == A)
		strafe_left(e);
	if (key == D)
		strafe_right(e);
	if (key == LEFT)
		left(e);
	if (key == RIGHT)
		right(e);
	//ft_update_img(e, ft_raycaster);
	return (0);
}

int			ft_click(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->x = x;
		e->rayposx = e->posx;
		e->rayposy = e->posy;
		e->camerax = 2 * (double)e->x / (double)WIDTH - 1;
		e->raydirx = e->dirx + e->planex * e->camerax;
		e->raydiry = e->diry + e->planey * e->camerax;
		e->mapx = (int)e->rayposx;
		e->mapy = (int)e->rayposy;
		e->deltadistx = sqrt(1 + (e->raydiry * e->raydiry) / (e->raydirx * e->raydirx));
		e->deltadisty = sqrt(1 + (e->raydirx * e->raydirx) / (e->raydiry * e->raydiry));
		e->hit = 0;
		ft_init_step(e);
		ft_loop_hit(e);
		ft_raylen(e);
		if (e->map[e->mapy][e->mapx] > '1' && y < e->drawend && y > e->drawstart)
			e->map[e->mapy][e->mapx] = '0';
		//ft_update_img(e, ft_raycaster);
	}
	return (0);
}