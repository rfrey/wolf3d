/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 00:01:05 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/15 23:38:35 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "texture.h"

void	ft_load_textures(t_win *win)
{
	int		i;
	int		*width;
	int		*heigth;
	void	**tex;
	char	*path;

	win->tex_count = TEX_COUNT;
	if ((!(win->textures = (t_tex**)malloc(sizeof(t_tex*) * win->tex_count))))
		ft_ferror(ERR_MALLOC);
	i = 0;
	while (i < win->tex_count)
	{
		if ((!(win->textures[i] = (t_tex*)malloc(sizeof(t_tex)))))
			ft_ferror(ERR_MALLOC);
		width = &win->textures[i]->width;
		heigth = &win->textures[i]->heigth;
		tex = &win->textures[i]->tex;
		path = ft_get_tex_path(i);
		*tex = mlx_xpm_file_to_image(win->mlx, path, width, heigth);
		if (!(*tex))
			ft_ferror(ERR_TEXTURE_LOAD);
		++i;
	}
}

int		ft_get_texel(t_column *column, int tex_y)
{
	return (ft_get_pix_color(column->texture->tex, column->tex_x, tex_y));
}

char	*ft_get_tex_path(int i)
{
	if (i == 0)
		return (TEX_WALL);
	else if (i == 1)
		return (TEX_BRICK);
	else if (i == 2)
		return (TEX_STONEWALL);
	else if (i == 3)
		return (TEX_SHIPHULL);
	else if (i == 4)
		return (TEX_FLOOR);
	else
		return (TEX_DEFAULT);
}

void	ft_free_textures(t_win *win)
{
	int		i;

	i = 0;
	while (i < win->tex_count)
	{
		mlx_destroy_image(win->mlx, win->textures[i]->tex);
		free(win->textures[i]);
		++i;
	}
	free(win->textures);
	win->tex_count = 0;
}
