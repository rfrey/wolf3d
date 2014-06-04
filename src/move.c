/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:57:42 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/15 19:35:56 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_move_cam(t_win *win)
{
	if (M_ROT_STATE == ROT_LEFT)
		ft_key_left(win);
	else if (M_ROT_STATE == ROT_RIGHT)
		ft_key_right(win);
	if (M_RUN_STATE == MOVE_FORWARD)
		ft_key_up(win);
	else if (M_RUN_STATE == MOVE_BACKWARD)
		ft_key_down(win);
	if (M_LOOK_STATE == LOOKING_UP)
		ft_key_pageup(win);
	else if (M_LOOK_STATE == LOOKING_DOWN)
		ft_key_pagedown(win);
	else if (M_LOOK_STATE == 0 && M_LOOK_MOD != 0)
		ft_look_reset(win);
}

void		ft_key_up(t_win *win)
{
	t_pix	pix;
	t_pix	*inter;

	inter = ft_get_shorter_inter(win, WIN_WIDTH / 2);
	pix.x = CAM_X + ft_cos(CAM_ANG) * M_RUN_SPD;
	pix.y = CAM_Y + ft_sin(CAM_ANG) * M_RUN_SPD;
	if (inter->dist > M_RUN_SPD)
	{
		CAM_X = pix.x;
		CAM_Y = pix.y;
	}
	free(inter);
}

void		ft_key_down(t_win *win)
{
	t_pix	pix;
	t_pix	*inter;

	CAM_ANG += 180;
	inter = ft_get_shorter_inter(win, WIN_WIDTH / 2);
	CAM_ANG -= 180;
	pix.x = CAM_X - ft_cos(CAM_ANG) * M_RUN_SPD;
	pix.y = CAM_Y - ft_sin(CAM_ANG) * M_RUN_SPD;
	if (inter->dist > M_RUN_SPD)
	{
		CAM_X = pix.x;
		CAM_Y = pix.y;
	}
	free(inter);
}

void		ft_key_right(t_win *win)
{
	CAM_ANG += M_ROT_SPD;
	CAM_ANG = ft_report_angle(CAM_ANG);
}

void		ft_key_left(t_win *win)
{
	CAM_ANG -= M_ROT_SPD;
	CAM_ANG = ft_report_angle(CAM_ANG);
}
