/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:08:14 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:45:59 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	init_raycasting(t_game *game, t_ray *r, int x)
{
	r->camera_x = 2 * x / (double)(WIN_W)-1;
	r->ray_dir_x = game->player.dir_x + game->player.plane_x * r->camera_x;
	r->ray_dir_y = game->player.dir_y + game->player.plane_y * r->camera_x;
	r->map_x = (int)(game->player.x);
	r->map_y = (int)(game->player.y);
	if (r->ray_dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1 / r->ray_dir_y);
	r->hit = 0;
}

void	init_step_and_side_dist(t_game *game, t_ray *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (game->player.x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - game->player.x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (game->player.y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - game->player.y) * r->delta_dist_y;
	}
}

void	perform_dda(t_game *game, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (game->map.grid[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

void	calculate_perp_wall_dist(t_game *game, t_ray *r)
{
	if (r->side == 0)
		r->perp_wall_dist = (r->map_x - game->player.x + (1 - r->step_x) / 2)
			/ r->ray_dir_x;
	else
		r->perp_wall_dist = (r->map_y - game->player.y + (1 - r->step_y) / 2)
			/ r->ray_dir_y;
	r->line_height = (int)(WIN_H / r->perp_wall_dist);
	r->draw_start = -r->line_height / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + WIN_H / 2;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H - 1;
}
void	draw_wall_column(t_game *game, t_ray *r, int x)
{
	t_texinfo	t;
	t_img		*tex;
	int			y;
	int			color;
	char		*src;

	init_texinfo(game, r, &t);
	tex = &game->mlx.tex[t.id];
	y = r->draw_start;
	while (y <= r->draw_end)
	{
		t.y = (int)t.pos;
		if (t.y < 0)
			t.y = 0;
		if (t.y >= tex->h)
			t.y = tex->h - 1;
		src = tex->addr + (t.y * tex->line_len + t.x * (tex->bpp / 8));
		color = *(unsigned int *)src;
		put_pixel(&game->mlx.screen, x, y, color);
		t.pos += t.step;
		y++;
	}
}
