/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:56:12 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/08 14:58:50 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int rgb_to_int(t_color color)
{
    return ((color.r << 16) | (color.g << 8) | color.b);
}

void put_pixel(t_img *img, int x, int y, int color)
{
    char    *dst;
    
    if(x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
        return ;
    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

void  draw_background(t_game *game)
{
    int x;
    int y;
    int floor_color;
    int ceiling_color;

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