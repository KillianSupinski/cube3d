/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:41:15 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/01 15:41:34 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void  init_mlx(t_game *game)
{
    game->mlx.mlx_ptr = mlx_init();
    if (!game->mlx.mlx_ptr)
    {
        printf("Error\nFailed to initialize MLX\n");
        exit(1);
    }
    game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, WIN_W, WIN_H, "Cub3D");
    if (!game->mlx.win_ptr)
    {
        printf("Error\nFailed to create window\n");
        exit(1);
    }
    game->mlx.screen.img_ptr = mlx_new_image(game->mlx.mlx_ptr, WIN_W, WIN_H);
    if (!game->mlx.screen.img_ptr)
    {
        printf("Error\nFailed to create image\n");
        exit(1);
    }
    game->mlx.screen.addr = mlx_get_data_addr(game->mlx.screen.img_ptr, \
        &game->mlx.screen.bpp, &game->mlx.screen.line_len, &game->mlx.screen.endian);
}

