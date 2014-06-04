/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 23:59:24 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/14 18:19:35 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_free_data(t_win **win)
{
	int		i;

	ft_free_textures(*win);
	free((*win)->cam->move);
	free((*win)->cam);
	mlx_destroy_image((*win)->mlx, (*win)->pic->pic);
	i = 0;
	while (i < (*win)->width)
	{
		free((*win)->pic->wall[i]);
		++i;
	}
	free((*win)->pic->wall);
	free((*win)->pic);
	ft_free_map(*win);
	mlx_destroy_window((*win)->mlx, (*win)->win);
	free(*win);
}
