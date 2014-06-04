/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 21:32:57 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/17 23:02:20 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include <mlx.h>
# include "list.h"
# include "param.h"
# include "libft.h"
# include "error.h"
# include "trigo.h"
# define CASE_SIZE 512
# define HORIZONTAL 0
# define VERTICAL 1
# define ROT_RIGHT 1
# define ROT_LEFT -1
# define MOVE_FORWARD 1
# define MOVE_BACKWARD -1
# define MOVE_CROUNCHING -1
# define MOVE_UP 1
# define MOVE_DOWN -1
# define LOOKING_DOWN -1
# define LOOKING_UP 1
# define CAM_X win->cam->pos_x
# define CAM_Y win->cam->pos_y
# define CAM_H win->cam->pos_h
# define CAM_ANG win->cam->angle
# define CAM_FOV win->cam->fov
# define P_PIC win->pic->pic
# define P_ADDR win->pic->addr
# define P_BPP win->pic->bpp
# define P_SLINE win->pic->size_line
# define P_END win->pic->endian
# define P_WALL win->pic->wall
# define M_LOOK_SPD win->cam->move->look_speed
# define M_LOOK_MOD win->cam->move->look_mod
# define M_LOOK_STATE win->cam->move->look_state
# define M_RUN_SPD win->cam->move->run_speed
# define M_RUN_STATE win->cam->move->run_state
# define M_ROT_SPD win->cam->move->rot_speed
# define M_ROT_STATE win->cam->move->rot_state
# define FLOOR_TEX win->textures[4]->tex

typedef struct		s_texture
{
	void			*tex;
	int				width;
	int				heigth;
}					t_tex;

typedef struct		s_pix
{
	double			x;
	double			y;
	double			ang;
	double			dist;
	int				axe;
}					t_pix;

typedef struct		s_column
{
	t_pix			*pix;
	t_tex			*texture;
	int				tex_x;
	int				heigth;
}					t_column;

typedef struct		s_pic
{
	t_column		**wall;
	void			*pic;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_pic;

typedef struct		s_case
{
	int				type;
}					t_case;

typedef struct		s_map
{
	t_case			***grid;
	int				width;
	int				heigth;
	int				start_pos_x;
	int				start_pos_y;
	double			start_angle;
}					t_map;

typedef struct		s_move
{
	int				run_state;
	int				run_speed;
	int				rot_state;
	double			rot_speed;
	int				look_state;
	int				look_speed;
	int				look_mod;
}					t_move;

typedef struct		s_cam
{
	int				fov;
	int				pos_h;
	double			pos_x;
	double			pos_y;
	double			angle;
	t_move			*move;
}					t_cam;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	char			*title;
	int				width;
	int				heigth;
	int				d_proj;
	t_map			*map;
	t_cam			*cam;
	t_pic			*pic;
	t_tex			**textures;
	int				tex_count;
}					t_win;

void		ft_ferror(char *message);
t_win		*ft_init_window(t_map *map);
t_map		*ft_init_map(char *path);
t_list		*ft_load_map(char *path);
void		ft_gen_map(t_list **list, t_map *map);
void		ft_check_map(t_win *win);
void		ft_free_map(t_win *win);
void		ft_init_cam(t_win *win);
void		ft_init_wall(t_win *win);
void		ft_init_pic(t_win *win);
void		ft_free_data(t_win **win);
void		ft_free_textures(t_win *win);
int			ft_get_case_type(t_win *win, t_pix *pix);
double		ft_get_alpha(t_win *win, int x);
t_pix		*ft_get_shorter_inter(t_win *win, int x);
void		ft_set_column(t_win *win, t_pix *pix, int x);
void		ft_get_wall(t_win *win);
t_pix		*ft_get_h_inter(t_win *win, int x);
void		ft_set_h_inter(t_win *win, t_pix *pix);
t_pix		*ft_get_v_inter(t_win *win, int x);
void		ft_set_v_inter(t_win *win, t_pix *pix);
double		ft_dist_corr(t_win *win, double dist, int x);
void		ft_put_pix_to_pic(t_win *win, int x, int y, int color);
int			ft_render(t_win *win);
void		ft_draw_h(t_win *win, int x, int y1, int y2);
void		ft_key_up(t_win *win);
void		ft_key_down(t_win *win);
void		ft_key_right(t_win *win);
void		ft_key_left(t_win *win);
int			ft_handle_key_release(int key, t_win *win);
int			ft_handle_key_press(int key, t_win *win);
void		ft_move_cam(t_win *win);
void		ft_key_pageup(t_win *win);
void		ft_key_pagedown(t_win *win);
void		ft_look_reset(t_win *win);
void		ft_load_textures(t_win *win);
int			ft_get_texel(t_column *column, int tex_y);
int			ft_get_pix_color(void *pic, int x, int y);
char		*ft_get_tex_path(int i);
void		ft_floor_casting(t_win *win, int x, int y);

#endif /* !WOLF3D_H */
