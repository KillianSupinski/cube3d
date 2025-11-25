/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:17:24 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/11/25 14:26:24 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"


void   init_game(int ac, char **av, t_game *game)
{
    ft_bzero(game, sizeof(t_game));
    parsing(ac, av, game);
}

int main(int ac, char **av)
{
    t_game game;
    init_game(ac, av, &game);
}