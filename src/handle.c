/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 22:09:24 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/15 19:35:57 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"
#include "key.h"

int			ft_handle_key_press(int key, t_win *win)
{
	if (key == KEY_RIGHT || key == KEY_D)
		M_ROT_STATE = ROT_RIGHT;
	else if (key == KEY_LEFT || key == KEY_A)
		M_ROT_STATE = ROT_LEFT;
	else if (key == KEY_UP || key == KEY_W)
		M_RUN_STATE = MOVE_FORWARD;
	else if (key == KEY_DOWN || key == KEY_S)
		M_RUN_STATE = MOVE_BACKWARD;
	else if (key == KEY_PAGEDOWN)
		M_LOOK_STATE = LOOKING_DOWN;
	else if (key == KEY_PAGEUP)
		M_LOOK_STATE = LOOKING_UP;
	return (0);
}

int			ft_handle_key_release(int key, t_win *win)
{
	if (key == KEY_ESC)
	{
		ft_free_data(&win);
		exit(EXIT_SUCCESS);
	}
	else if ((key == KEY_RIGHT || key == KEY_D ) && M_ROT_STATE == ROT_RIGHT)
		M_ROT_STATE = 0;
	else if ((key == KEY_LEFT || key == KEY_A) && M_ROT_STATE == ROT_LEFT)
		M_ROT_STATE = 0;
	else if ((key == KEY_UP || key == KEY_W) && M_RUN_STATE == MOVE_FORWARD)
		M_RUN_STATE = 0;
	else if ((key == KEY_DOWN || key == KEY_S) && M_RUN_STATE == MOVE_BACKWARD)
		M_RUN_STATE = 0;
	else if (key == KEY_PAGEUP && M_LOOK_STATE == LOOKING_UP)
		M_LOOK_STATE = 0;
	else if (key == KEY_PAGEDOWN && M_LOOK_STATE == LOOKING_DOWN)
		M_LOOK_STATE = 0;
	return (0);
}
