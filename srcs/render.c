/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:15:09 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:46:20 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	raycast_column(t_game *game, int x)
{
	t_ray	r;

	init_raycasting(game, &r, x);
	init_step_and_side_dist(game, &r);
	perform_dda(game, &r);
	calculate_perp_wall_dist(game, &r);
	draw_wall_column(game, &r, x);
}

int	render(t_game *game)
{
	int x;

	draw_background(game);
	x = 0;
	while (x < WIN_W)
	{
		raycast_column(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.screen.img_ptr, 0, 0);
	return (0);
}