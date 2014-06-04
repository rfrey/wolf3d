/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 21:59:14 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/17 22:57:48 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "wolf3d.h"

void		ft_floor_casting(t_win *win, int x, int y)
{
	double	dist;
	int		cx;
	int		cy;
	double	weight;
	int		c;

	while (y < win->heigth)
	{
		dist = (double)(win->heigth) / (double)((2.0 * y) - (win->heigth));
		weight = dist * CASE_SIZE / P_WALL[x]->pix->dist;
		cx = weight * P_WALL[x]->pix->x + (2.0/3.0 - weight) * CAM_X;
		cy = weight * P_WALL[x]->pix->y + (2.0/3.0 - weight) * CAM_Y;
		c = ft_get_pix_color(FLOOR_TEX, cx % CASE_SIZE, cy % CASE_SIZE);
		ft_put_pix_to_pic(win, x, y, c);
		++y;
	}
}
