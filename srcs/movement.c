/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:14:27 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/10 12:22:09 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int is_walkable(t_game *game, double new_x, double new_y)
{
    int map_x;
    int map_y;
    char cell;
    
    map_x = (int)(new_x);
    map_y = (int)(new_y);
    cell = game->map.grid[map_y][map_x];
    if (cell == '0')
        return (1);
    return (0);
}
void move_forward(t_game *g)
{
    double new_x;
    double new_y;

    new_x = g->player.x + g->player.dir_x * MOVE_SPEED;
    new_y = g->player.y + g->player.dir_y * MOVE_SPEED;
    if (is_walkable(g, new_x, g->player.y))
        g->player.x = new_x;
    if (is_walkable(g, g->player.x, new_y))
        g->player.y = new_y;
}

void move_backward(t_game *g)
{
    double new_x;
    double new_y;

    new_x = g->player.x - g->player.dir_x * MOVE_SPEED;
    new_y = g->player.y - g->player.dir_y * MOVE_SPEED;
    if (is_walkable(g, new_x, g->player.y))
        g->player.x = new_x;
    if (is_walkable(g, g->player.x, new_y))
        g->player.y = new_y;
}

void strafe_left(t_game *g)
{
    double new_x;
    double new_y;

    new_x = g->player.x - g->player.plane_x * MOVE_SPEED;
    new_y = g->player.y - g->player.plane_y * MOVE_SPEED;
    if (is_walkable(g, new_x, g->player.y))
        g->player.x = new_x;
    if (is_walkable(g, g->player.x, new_y))
        g->player.y = new_y;
}

void strafe_right(t_game *g)
{
    double new_x;
    double new_y;

    new_x = g->player.x + g->player.plane_x * MOVE_SPEED;
    new_y = g->player.y + g->player.plane_y * MOVE_SPEED;
    if (is_walkable(g, new_x, g->player.y))
        g->player.x = new_x;
    if (is_walkable(g, g->player.x, new_y))
        g->player.y = new_y;
}