/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:12:25 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/02 15:05:41 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

char *get_texture_path(t_game *game, char *tokens)
{
    char *trimmed;
    
    if (!tokens)
        error_exit(game, "Error\n Texture path missing\n");
    trimmed = ft_strtrim(tokens, " \t\n\r\f\v");
    if (!trimmed)
        error_exit(game, "Error\nMemory allocation failed\n");
    if(trimmed[0] == '\0')
    {
        free(trimmed);
        error_exit(game, "Error\nTexture path missing\n");
    }
    return (trimmed);
}

void    parse_no(char **tokens, t_game *game)
{
    if(game->tex.no)
        error_exit(game, "Error\nDuplicate NO texture definition\n");
    else if(!tokens[1])
        error_exit(game, "Error\nNO texture path missing\n");
    else
    {
        game->tex.no_path = get_texture_path(game, tokens[1]);
        game->tex.no = 1;
    }
}
void    parse_so(char **tokens, t_game *game)
{
    if(game->tex.so)
        error_exit(game, "Error\nDuplicate SO texture definition\n");
    else if(!tokens[1])
        error_exit(game, "Error\nSO texture path missing\n");
    else
    {
        game->tex.so_path = get_texture_path(game, tokens[1]);
        game->tex.so = 1;
    }
}

void    parse_we(char **tokens, t_game *game)
{
    if(game->tex.we)
        error_exit(game, "Error\nDuplicate WE texture definition\n");
    else if(!tokens[1])
        error_exit(game, "Error\nWE texture path missing\n");
    else
    {
        game->tex.we_path = get_texture_path(game, tokens[1]);
        game->tex.we = 1;
    }
}

void    parse_ea(char **tokens, t_game *game)
{
    if(game->tex.ea)
        error_exit(game, "Error\nDuplicate EA texture definition\n");
    else if(!tokens[1])
        error_exit(game, "Error\nEA texture path missing\n");
    else
    {
        game->tex.ea_path = get_texture_path(game, tokens[1]);
        game->tex.ea = 1;
    }
}