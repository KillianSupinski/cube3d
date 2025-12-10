/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:41:15 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/02 14:53:39 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void  init_mlx(t_game *game)
{
    game->mlx.mlx_ptr = mlx_init();
    if (!game->mlx.mlx_ptr)
        error_exit(game, "Error\nFailed to initialize MLX\n");
    game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, WIN_W, WIN_H, "Cub3D");
    if (!game->mlx.win_ptr)
        error_exit(game, "Error\nFailed to create window\n");
    game->mlx.screen.img_ptr = mlx_new_image(game->mlx.mlx_ptr, WIN_W, WIN_H);
    if (!game->mlx.screen.img_ptr)
        error_exit(game, "Error\nFailed to create image\n");
    game->mlx.screen.addr = mlx_get_data_addr(game->mlx.screen.img_ptr, \
        &game->mlx.screen.bpp, &game->mlx.screen.line_len, &game->mlx.screen.endian);
}

void load_textures(t_game *game, t_img *img, char *path)
{
    img->img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path, &img->w, &img->h);
    if (!img->img_ptr)
        error_exit(game, "Error\nFailed to load texture\n");
    img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian);
}

void load_all_textures(t_game *game)
{
    load_textures(game, &game->mlx.tex[0], game->tex.no_path);
    load_textures(game, &game->mlx.tex[1], game->tex.so_path);
    load_textures(game, &game->mlx.tex[2], game->tex.ea_path);
    load_textures(game, &game->mlx.tex[3], game->tex.we_path);
}