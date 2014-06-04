/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 21:32:12 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/15 18:56:15 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "X.h"

int			main(int argc, char **argv)
{
	t_map	*map;
	t_win	*win;

	if (argc != 2)
		ft_ferror("wold3d: usage: ./wol3d file.w3d");
	map = ft_init_map(argv[1]);
	win = ft_init_window(map);
	ft_check_map(win);
	mlx_do_key_autorepeatoff(win->mlx);
	mlx_hook(win->win, KeyPress, KeyPressMask, ft_handle_key_press, win);
	mlx_hook(win->win, KeyRelease, KeyReleaseMask, ft_handle_key_release, win);
	mlx_expose_hook(win->win, ft_render, win);
	mlx_loop_hook(win->mlx, ft_render, win);
	mlx_loop(win->mlx);
	return (0);
}

void		ft_ferror(char *message)
{
	if (!message)
		message = ERR_UNDEF;
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

t_win		*ft_init_window(t_map *map)
{
	t_win	*win;

	if (!((win = (t_win*)malloc(sizeof(t_win)))))
		ft_ferror(ERR_MALLOC);
	if (!((win->mlx = mlx_init())))
		ft_ferror(ERR_MLX_INIT);
	win->title = WIN_TITLE;
	win->width = WIN_WIDTH;
	win->heigth = WIN_HEIGTH;
	win->win = mlx_new_window(win->mlx, win->width, win->heigth, win->title);
	if (!win->win)
		ft_ferror(ERR_MLX_WIN);
	win->map = map;
	if ((!(win->pic = (t_pic*)malloc(sizeof(t_pic)))))
		ft_ferror(ERR_MALLOC);
	if ((!(win->pic->pic = mlx_new_image(win->mlx, win->width, win->heigth))))
		ft_ferror(ERR_MLX_IMG);
	P_ADDR = mlx_get_data_addr(P_PIC, &(P_BPP), &(P_SLINE), &(P_END));
	ft_init_wall(win);
	ft_init_cam(win);
	ft_load_textures(win);
	return (win);
}

void		ft_init_cam(t_win *win)
{
	if (!((win->cam = (t_cam*)malloc(sizeof(t_cam)))))
		ft_ferror(ERR_MALLOC);
	if (!((win->cam->move = (t_move*)malloc(sizeof(t_move)))))
		ft_ferror(ERR_MALLOC);
	win->cam->move->run_state = 0;
	win->cam->move->run_speed = SPEED_RUN;
	win->cam->move->rot_state = 0;
	win->cam->move->rot_speed = SPEED_ROT;
	win->cam->move->look_state = 0;
	win->cam->move->look_speed = SPEED_LOOK;
	win->cam->move->look_mod = 0;
	win->cam->fov = FOV;
	win->cam->pos_h = 0;
	win->cam->pos_x = win->map->start_pos_x * CASE_SIZE + CASE_SIZE / 2;
	win->cam->pos_y = win->map->start_pos_y * CASE_SIZE + CASE_SIZE / 2;
	win->cam->angle = START_ANGLE;
	win->d_proj = ((win->width / 2) / (ft_tan(win->cam->fov / 2)));
}

void		ft_init_wall(t_win *win)
{
	int		i;

	if ((!(P_WALL = (t_column**)malloc(sizeof(t_column*) * win->width))))
		ft_ferror(ERR_MALLOC);
	i = 0;
	while (i < win->width)
	{
		if ((!(P_WALL[i] = (t_column*)malloc(sizeof(t_column)))))
			ft_ferror(ERR_MALLOC);
		++i;
	}
}
