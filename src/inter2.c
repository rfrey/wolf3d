/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 23:53:50 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/12 18:47:50 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trigo.h"

double		ft_dist_corr(t_win *win, double dist, int x)
{
	double	alpha;
	double	ray_ang;

	ray_ang = (double)CAM_FOV / (double)win->width;
	alpha = ray_ang * (x - ((double)win->width / 2));
	return (ABS(dist * ft_cos(alpha)));
}

double		ft_get_alpha(t_win *win, int x)
{
	double	ray_ang;
	double	alpha;

	ray_ang = (double)CAM_FOV / (double)win->width;
	alpha = CAM_ANG - (double)CAM_FOV / 2 + ray_ang * x;
	return (ft_report_angle(alpha));
}

int			ft_get_case_type(t_win *win, t_pix *pix)
{
	int		x;
	int		y;

	x = pix->x / CASE_SIZE;
	y = pix->y / CASE_SIZE;
	if (x < 0)
		x = 0;
	if (x > win->map->width - 1)
		x = win->map->width - 1;
	if (y < 0)
		y = 0;
	if (y > win->map->heigth - 1)
		y = win->map->heigth - 1;
	return (win->map->grid[y][x]->type);
}
