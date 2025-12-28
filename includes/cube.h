/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:17:12 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:48:53 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define WIN_W 800
# define WIN_H 600
# define MOVE_SPEED 0.08
# define ROT_SPEED 0.05
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3

typedef struct s_texinfo
{
	int			id;
	int			x;
	int			y;
	double		step;
	double		pos;
}				t_texinfo;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
}				t_map;

typedef struct s_tex
{
	char		*no_path;
	int			no;
	char		*so_path;
	int			so;
	char		*we_path;
	int			we;
	char		*ea_path;
	int			ea;
	t_color		floor;
	int			floor_set;
	t_color		ceiling;
	int			ceiling_set;
}				t_tex;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			w;
	int			h;
}				t_img;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		screen;
	t_img		tex[4];
}				t_mlx;

typedef struct s_game
{
	t_map		map;
	t_tex		tex;
	t_player	player;
	char		**file_lines;
	t_ray		ray;
	t_mlx		mlx;
}				t_game;

void			parsing(int ac, char **av, t_game *game);
void			print_map(t_game *game);
void			floor_color(char *color_str, t_game *game);
void			ceiling_color(char *color_str, t_game *game);
int				parse_color(char **tokens, t_game *game);
void			parse_no(char **tokens, t_game *game);
void			parse_so(char **tokens, t_game *game);
void			parse_we(char **tokens, t_game *game);
void			parse_ea(char **tokens, t_game *game);
int				parse_file(t_game *game);
void			init_game(int ac, char **av, t_game *game);
void			free_split(char **split);
int				all_text_and_color_set(t_game *game);
int				is_empty_line(char *tmp);
void			is_valid_map(t_game *game);
int				count_tokens(char **tokens);
int				text_cmp(char **tokens);
int				parse_tex(char **tokens, t_game *game);
void			init_mlx(t_game *game);
void			load_all_textures(t_game *game);
int				handle_keypress(int keycode, t_game *game);
int				handle_close(t_game *game);
void			destroy_all(t_game *game, int exit_code);
void			error_exit(t_game *game, char *message);
int				render(t_game *game);
void			draw_background(t_game *game);
void			raycast_column(t_game *game, int x);
void			put_pixel(t_img *img, int x, int y, int color);
int				rgb_to_int(t_color color);
void			init_raycasting(t_game *game, t_ray *r, int x);
void			init_step_and_side_dist(t_game *game, t_ray *r);
void			perform_dda(t_game *game, t_ray *r);
void			calculate_perp_wall_dist(t_game *game, t_ray *r);
void			draw_wall_column(t_game *game, t_ray *r, int x);
void			move_forward(t_game *g);
void			move_backward(t_game *g);
void			strafe_left(t_game *g);
void			strafe_right(t_game *g);
void			rotate_left(t_game *g);
void			rotate_right(t_game *g);
int				is_walkable(t_game *game, double new_x, double new_y);
int				get_tex_id(t_ray *r);
void			init_texinfo(t_game *game, t_ray *r, t_texinfo *t);
#endif