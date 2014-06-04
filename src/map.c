/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 22:18:11 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/14 19:20:50 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "wolf3d.h"
#include "ft_get_next_line.h"

t_map		*ft_init_map(char *path)
{
	t_list	*list;
	t_map	*map;

	if ((!(list = ft_load_map(path))))
		ft_ferror(ERR_FREAD);
	if ((!(map = (t_map*)malloc(sizeof(t_map)))))
		ft_ferror(ERR_MALLOC);
	map->heigth = ft_listcnt(list);
	map->width = -1;
	map->start_pos_x = START_POS_X;
	map->start_pos_y = START_POS_Y;
	map->start_angle = START_ANGLE;
	if ((!(map->grid = (t_case***)malloc(sizeof(t_case**) * map->heigth))))
		ft_ferror(ERR_MALLOC);
	ft_gen_map(&list, map);
	return (map);
}

void		ft_check_map(t_win *win)
{
	int		x;
	int		y;
	int		type;

	y = 0;
	while (y < win->map->heigth)
	{
		x = 0;
		while (x < win->map->width)
		{
			type = win->map->grid[y][x]->type;
			if (type < 0 || type > win->tex_count)
				ft_ferror(ERR_MAP);
			if ((y == 0 || y == win->map->heigth - 1) && type == 0)
				ft_ferror(ERR_MAP);
			if ((x == 0 || x == win->map->width - 1) && type == 0)
				ft_ferror(ERR_MAP);
			++x;
		}
		++y;
	}
}

void		ft_gen_map(t_list **list, t_map *map)
{
	char	**tab;
	int		w;
	int		h;

	h = 0;
	while (h < map->heigth)
	{
		tab = ft_strsplit((char*)ft_listpop(list), ' ');
		if (map->width == -1)
			map->width = ft_strtabsize(tab);
		else if (map->width != ft_strtabsize(tab))
			ft_ferror(ERR_MAP);
		if ((!(map->grid[h] = (t_case**)malloc(sizeof(t_case*) * map->width))))
			ft_ferror(ERR_MALLOC);
		w = 0;
		while (w < map->width)
		{
			if ((!(map->grid[h][w] = (t_case*)malloc(sizeof(t_case)))))
				ft_ferror(ERR_MALLOC);
			map->grid[h][w]->type = ft_atoi(tab[w]);
			++w;
		}
		++h;
	}
}

t_list		*ft_load_map(char *path)
{
	int		fd;
	t_list	*list;
	char	*line;
	int		ret;

	if ((!(fd = open(path, O_RDONLY))))
		return (NULL);
	list = NULL;
	while ((ret = ft_get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			ft_listclear(&list);
			ft_ferror(ERR_FREAD);
		}
		ft_listpushback(&list, line);
	}
	close(fd);
	return (list);
}

void		ft_free_map(t_win *win)
{
	int		w;
	int		h;

	h = 0;
	while (h < win->map->heigth)
	{
		w = 0;
		while (w < win->map->width)
		{
			free(win->map->grid[h][w]);
			++w;
		}
		free(win->map->grid[h]);
		++h;
	}
	free(win->map->grid);
	free(win->map);
}
