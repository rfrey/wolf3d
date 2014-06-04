/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 15:27:00 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/17 23:04:58 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_key_pageup(t_win *win)
{
	if ((M_LOOK_MOD) < WIN_HEIGTH * MAX_LOOK_FACTOR)
		M_LOOK_MOD += M_LOOK_SPD;
}

void		ft_key_pagedown(t_win *win)
{
	if (ABS(M_LOOK_MOD) < WIN_HEIGTH * MAX_LOOK_FACTOR)
		M_LOOK_MOD -= M_LOOK_SPD;
}

void		ft_look_reset(t_win *win)
{
	if (M_LOOK_MOD > M_LOOK_SPD * 2)
		M_LOOK_MOD -= M_LOOK_SPD * 2;
	else if (M_LOOK_MOD < -M_LOOK_SPD * 2)
		M_LOOK_MOD += M_LOOK_SPD * 2;
	else
		M_LOOK_MOD = 0;
}
