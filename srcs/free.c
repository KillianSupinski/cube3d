/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:36:41 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:46:39 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.grid)
	{
		while (i < game->map.height)
		{
			if (game->map.grid[i])
				free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
		game->map.grid = NULL;
	}
}

void	free_all_game(t_game *game)
{
	int	i;

	free_map(game);
	if (game->tex.no_path)
		free(game->tex.no_path);
	if (game->tex.so_path)
		free(game->tex.so_path);
	if (game->tex.we_path)
		free(game->tex.we_path);
	if (game->tex.ea_path)
		free(game->tex.ea_path);
	if (game->file_lines)
	{
		i = 0;
		while (game->file_lines[i])
		{
			free(game->file_lines[i]);
			i++;
		}
		free(game->file_lines);
		game->file_lines = NULL;
	}
}

void	destroy_all(t_game *game, int exit_code)
{
	int	i;

	// Destroy MLX resources
	if (game->mlx.mlx_ptr)
	{
		if (game->mlx.screen.img_ptr)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.screen.img_ptr);
		i = 0;
		while (i < 4)
		{
			if (game->mlx.tex[i].img_ptr)
				mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.tex[i].img_ptr);
			i++;
		}
		if (game->mlx.win_ptr)
			mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
	}
	free_all_game(game);
	exit(exit_code);
}

void	error_exit(t_game *game, char *message)
{
	if (message)
		printf("Error\n%s\n", message);
	destroy_all(game, 1);
}
