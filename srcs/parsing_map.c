/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:54:39 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/01 15:35:30 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int is_player_char(char c)
{
    return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void set_player_dir(t_game *game, char c)
{
    if (c == 'N')
    {
        game->player.dir_x = 0.0;
        game->player.dir_y = -1.0;
        game->player.plane_x = 0.66;
        game->player.plane_y = 0.0;
    }
    else if (c == 'S')
    {
        game->player.dir_x = 0.0;
        game->player.dir_y = 1.0;
        game->player.plane_x = -0.66;
        game->player.plane_y = 0.0;
    }
    else if (c == 'E')
    {
        game->player.dir_x = 1.0;
        game->player.dir_y = 0.0;
        game->player.plane_x = 0.0;
        game->player.plane_y = 0.66;
    }
    else if (c == 'W')
    {
        game->player.dir_x = -1.0;
        game->player.dir_y = 0.0;
        game->player.plane_x = 0.0;
        game->player.plane_y = -0.66;
    }
}

void check_map_chars_and_players(t_game *game)
{
    int x;
    int y;
    int player_count;
    char c;

    player_count = 0;
    x = 0;
    while (x < game->map.height)
    {
        y = 0;
        while(y < game->map.width)
        {
            c = game->map.grid[x][y];
            if (c != '0' && c != '1' && c != ' ' && !is_player_char(c))
            {
                printf("Error\nInvalid character '%c' in map\n", c);
                exit(1);
            }
            else if(is_player_char(c))
            {
                player_count++;
                game->player.x = y + 0.5;
                game->player.y = x + 0.5;
                set_player_dir(game, c);
                game->map.grid[x][y] = '0';
            }
            y++;
        }
        x++;
    }
    if (player_count != 1)
    {
        printf("Error\nInvalid number of player start positions: %d\n", player_count);
        exit(1);
    }
}


void check_map_closed(t_game *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->map.height)
    {
        y = 0;
        while (y < game->map.width)
        {
            if (game->map.grid[x][y] == '0' || is_player_char(game->map.grid[x][y]))
            {
                if (x == 0 || y == 0 || x == game->map.height - 1 || y == game->map.width - 1)
                {
                    printf("Error\nMap is not closed at edge (%d, %d)\n", x, y);
                    exit(1);
                }
                if (game->map.grid[x - 1][y] == ' ' || game->map.grid[x + 1][y] == ' ' ||
                    game->map.grid[x][y - 1] == ' ' || game->map.grid[x][y + 1] == ' ')
                {
                    printf("Error\nMap is not closed around (%d, %d)\n", x, y);
                    exit(1);
                }
            }
            y++;
        }
        x++;
    }
}

void is_valid_map(t_game *game)
{
       check_map_chars_and_players(game);
       check_map_closed(game);
}