/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:56:12 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:46:00 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	rgb_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;
	int	floor_color;
	int	ceiling_color;

	floor_color = rgb_to_int(game->tex.floor);
	ceiling_color = rgb_to_int(game->tex.ceiling);
	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
			put_pixel(&game->mlx.screen, x++, y, ceiling_color);
		y++;
	}
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
			put_pixel(&game->mlx.screen, x++, y, floor_color);
		y++;
	}
}

void	init_texinfo(t_game *game, t_ray *r, t_texinfo *t)
{
	double	wall_x;
	t_img	*tex;

	tex = NULL;
	t->id = get_tex_id(r);
	tex = &game->mlx.tex[t->id];
	if (r->side == 0)
		wall_x = game->player.y + r->perp_wall_dist * r->ray_dir_y;
	else
		wall_x = game->player.x + r->perp_wall_dist * r->ray_dir_x;
	wall_x -= floor(wall_x);
	t->x = (int)(wall_x * (double)(tex->w));
	if (r->side == 0 && r->ray_dir_x > 0)
		t->x = tex->w - t->x - 1;
	if (r->side == 1 && r->ray_dir_y < 0)
		t->x = tex->w - t->x - 1;
	t->step = 1.0 * tex->h / r->line_height;
	t->pos = (r->draw_start - WIN_H / 2 + r->line_height / 2) * t->step;
}

// WE: 2 SO: 1 NO: 0 EA: 3
int	get_tex_id(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			return (tex_ea);
		else
			return (tex_we);
	}
	else
	{
		if (r->ray_dir_y > 0)
			return (tex_so);
		return (tex_no);
	}
}