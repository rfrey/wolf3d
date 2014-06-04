/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:15:15 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/14 18:33:04 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"
#include "trigo.h"

t_pix		*ft_get_shorter_inter(t_win *win, int x)
{
	t_pix	*inter_h;
	t_pix	*inter_v;
	t_pix	*shorter;

	shorter = NULL;
	inter_h = ft_get_h_inter(win, x);
	inter_v = ft_get_v_inter(win, x);
	if (inter_v && (!inter_h || inter_h->dist > inter_v->dist))
	{
		shorter = inter_v;
		shorter->axe = VERTICAL;
		if (inter_h)
			free(inter_h);
	}
	else if (inter_h && (!inter_v || inter_v->dist > inter_h->dist))
	{
		shorter = inter_h;
		shorter->axe = HORIZONTAL;
		if (inter_v)
			free(inter_v);
	}
	return (shorter);
}

t_pix		*ft_get_v_inter(t_win *win, int x)
{
	t_pix	*pix;

	if ((!(pix = (t_pix*)malloc(sizeof(t_pix)))))
		ft_ferror(ERR_MALLOC);
	pix->ang = ft_get_alpha(win, x);
	if (pix->ang == 90 || pix->ang == 270)
		return (NULL);
	ft_set_v_inter(win, pix);
	pix->dist = ft_dist_corr(win, (CAM_X - pix->x) / ft_cos(pix->ang), x);
	return (pix);
}

t_pix		*ft_get_h_inter(t_win *win, int x)
{
	t_pix	*pix;

	if ((!(pix = (t_pix*)malloc(sizeof(t_pix)))))
		ft_ferror(ERR_MALLOC);
	pix->ang = ft_get_alpha(win, x);
	if (pix->ang == 0 || pix->ang == 180)
		return (NULL);
	ft_set_h_inter(win, pix);
	pix->dist = ft_dist_corr(win, (CAM_Y - pix->y) / ft_sin(pix->ang), x);
	return (pix);
}

void		ft_set_v_inter(t_win *win, t_pix *pix)
{
	double	dx;
	double	dy;

	if (pix->ang > 90 && pix->ang < 270)
		pix->x = ((int)CAM_X / CASE_SIZE * CASE_SIZE) - 1e-10;
	else
		pix->x = ((int)CAM_X / CASE_SIZE * CASE_SIZE + CASE_SIZE);
	if (pix->ang == 0 || pix->ang == 180)
	{
		pix->y = CAM_Y;
		dy = 0;
	}
	else
	{
		pix->y = CAM_Y + (CAM_X - pix->x) * ft_tan(-pix->ang);
		dy = CASE_SIZE * ft_tan(pix->ang);
		if (pix->ang > 90 && pix->ang < 270)
			dy = -dy;
	}
	dx = (pix->ang >= 90 && pix->ang < 270 ? -CASE_SIZE : CASE_SIZE);
	while (ft_get_case_type(win, pix) == 0)
	{
		pix->x += dx;
		pix->y += dy;
	}
}

void		ft_set_h_inter(t_win *win, t_pix *pix)
{
	double	dx;
	double	dy;

	if (pix->ang > 180)
		pix->y = (int)CAM_Y / CASE_SIZE * CASE_SIZE - 1e-10;
	else
		pix->y = (int)CAM_Y / CASE_SIZE * CASE_SIZE + CASE_SIZE;
	if (pix->ang == 90 || pix->ang == 270)
	{
		pix->x = CAM_X;
		dx = 0;
	}
	else
	{
		pix->x = CAM_X - ((CAM_Y - pix->y) * ft_tan(90 - pix->ang));
		dx = CASE_SIZE / ft_tan(pix->ang);
		if (pix->ang > 180)
			dx = -dx;
	}
	dy = (pix->ang >= 180 ? -CASE_SIZE : CASE_SIZE);
	while (ft_get_case_type(win, pix) == 0)
	{
		pix->x += dx;
		pix->y += dy;
	}
}
