/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:38:49 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/10 12:20:01 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == 65307 || keycode == 53)
        destroy_all(game, 0);
    else if (keycode == KEY_W)
        move_forward(game);
    else if (keycode == KEY_S)
        move_backward(game);
    else if (keycode == KEY_A)
        strafe_left(game);
    else if (keycode == KEY_D)
        strafe_right(game);
    else if (keycode == KEY_LEFT)
        rotate_left(game);
    else if (keycode == KEY_RIGHT)
        rotate_right(game);
    return (0);
}

int handle_close(t_game *game)
{
    destroy_all(game, 0);
    return (0);
}