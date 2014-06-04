/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:12:09 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/17 23:01:49 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				ft_render(t_win *win)
{
	int			x;
	int			y1;
	int			y2;

	ft_move_cam(win);
	ft_get_wall(win);
	x = 0;
	while (x < win->width)
	{
		y1 = win->heigth / 2 + M_LOOK_MOD - P_WALL[x]->heigth / 2;
		y2 = win->heigth / 2 + M_LOOK_MOD + P_WALL[x]->heigth / 2;
		ft_draw_h(win, x, y1, y2);
		++x;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->pic->pic, 0, 0);
	return (1);
}

void			ft_get_wall(t_win *win)
{
	int			x;
	t_pix		*shorter;

	x = 0;
	while (x < win->width)
	{
		shorter = ft_get_shorter_inter(win, x);
		ft_set_column(win, shorter, x);
		++x;
	}
}

void			ft_set_column(t_win *win, t_pix *pix, int x)
{
	int			texture;

	texture = 0;
	if (!pix)
		ft_ferror(ERR_UNDEF);
	else if (pix->axe == HORIZONTAL)
		P_WALL[x]->tex_x = (int)pix->x % CASE_SIZE;
	else
		P_WALL[x]->tex_x = (int)pix->y % CASE_SIZE;
	P_WALL[x]->heigth = (CASE_SIZE / pix->dist) * win->d_proj;
	texture = ft_get_case_type(win, pix);
	if (texture > win->tex_count || texture < 1)
		ft_ferror(ERR_TEXTURE_NOT_EXIST);
	P_WALL[x]->texture = win->textures[texture - 1];
	P_WALL[x]->pix = pix;
}

void			ft_draw_h(t_win *win, int x, int y1, int y2)
{
	int			y;
	int			tex_y;

	y = 0;
	while (y < y2 && y < win->heigth)
	{
		if (y < y1)
			ft_put_pix_to_pic(win, x, y, COLOR_SKY);
		else if (y < y2)
		{
			tex_y = (double)(y - y1) / (double)(y2 - y1) * CASE_SIZE;
			ft_put_pix_to_pic(win, x, y, ft_get_texel(P_WALL[x], tex_y));
		}
		++y;
	}
	ft_floor_casting(win, x, y2);
	if (P_WALL[x]->pix)
		free(P_WALL[x]->pix);
}
