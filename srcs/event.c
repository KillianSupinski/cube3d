/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:38:49 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/02 14:54:30 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == 65307 || keycode == 53)
        destroy_all(game, 0);
    return (0);
}

int handle_close(t_game *game)
{
    destroy_all(game, 0);
    return (0);
}