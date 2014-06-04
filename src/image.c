/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 21:49:40 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/14 19:38:19 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_put_pix_to_pic(t_win *win, int x, int y, int color)
{
	char	*pix_addr;
	int		opp;
	int		i;

	opp = P_BPP / 8;
	i = opp;
	pix_addr = P_ADDR + y * P_SLINE + x * opp;
	color = mlx_get_color_value(win->mlx, color);
	while (i)
	{
		pix_addr[3] = (unsigned char)0x00;
		pix_addr[2] = (unsigned char)((color / 65536) % 256);
		pix_addr[1] = (unsigned char)((color / 256) % 256);
		pix_addr[0] = (unsigned char)(color % 256);
		--i;
	}
}

int			ft_get_pix_color(void *pic, int x, int y)
{
	char	*addr;
	int		bpp;
	int		sl;
	int		endian;
	int		color;

	addr = mlx_get_data_addr(pic, &bpp, &sl, &endian);
	addr += y * sl + x * (bpp / 8);
	color = 0;
	color += addr[2] * 65536;
	color += addr[1] * 256;
	color += *addr;
	return (color);
}
