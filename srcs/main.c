/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:17:24 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:46:36 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	main(int ac, char **av)
{
	t_game game;
	ft_bzero(&game, sizeof(t_game));
	parsing(ac, av, &game);
	init_mlx(&game);
	load_all_textures(&game);
	mlx_hook(game.mlx.win_ptr, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, handle_close, &game);
	mlx_hook(game.mlx.win_ptr, 33, 0, handle_close, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, render, &game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}