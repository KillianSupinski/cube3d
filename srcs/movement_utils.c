/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:22:59 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:50:49 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	rotate_left(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cs;
	double	sn;

	cs = cos(-ROT_SPEED);
	sn = sin(-ROT_SPEED);
	old_dir_x = g->player.dir_x;
	old_plane_x = g->player.plane_x;
	g->player.dir_x = g->player.dir_x * cs - g->player.dir_y * sn;
	g->player.dir_y = old_dir_x * sn + g->player.dir_y * cs;
	g->player.plane_x = g->player.plane_x * cs - g->player.plane_y * sn;
	g->player.plane_y = old_plane_x * sn + g->player.plane_y * cs;
}

void	rotate_right(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cs;
	double	sn;

	cs = cos(ROT_SPEED);
	sn = sin(ROT_SPEED);
	old_dir_x = g->player.dir_x;
	old_plane_x = g->player.plane_x;
	g->player.dir_x = g->player.dir_x * cs - g->player.dir_y * sn;
	g->player.dir_y = old_dir_x * sn + g->player.dir_y * cs;
	g->player.plane_x = g->player.plane_x * cs - g->player.plane_y * sn;
	g->player.plane_y = old_plane_x * sn + g->player.plane_y * cs;
}