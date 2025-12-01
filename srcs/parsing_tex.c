/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:12:25 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/01 13:48:36 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

char *get_texture_path(char *tokens, char *id)
{
    char *trimmed;
    
    if (!tokens)
    {
        printf("Error\n%s Texture path missing\n", id);
        exit(1);
    }
    trimmed = ft_strtrim(tokens, " \t\n\r\f\v");
    if (!trimmed)
    {
        printf("Error\nMemory allocation failed\n");
        exit(1);
    }
    if(trimmed[0] == '\0')
    {
        free(trimmed);
        printf("Error\n%s Texture path missing\n", id);
        exit(1);
    }
    return (trimmed);
}

void    parse_no(char **tokens, t_game *game)
{
    if(game->tex.no)
    {
        printf("Error\nDuplicate NO texture definition\n");
        exit(1);
    }
    else if(!tokens[1])
    {
        printf("Error\nNO texture path missing\n");
        exit(1);
    }
    else
    {
        game->tex.no_path = get_texture_path(tokens[1], "NO");
        game->tex.no = 1;
    }
}
void    parse_so(char **tokens, t_game *game)
{
    if(game->tex.so)
    {
        printf("Error\nDuplicate SO texture definition\n");
        exit(1);
    }
    else if(!tokens[1])
    {
        printf("Error\nSO texture path missing\n");
        exit(1);
    }
    else
    {
        game->tex.so_path = get_texture_path(tokens[1], "SO");
        game->tex.so = 1;
    }
}

void    parse_we(char **tokens, t_game *game)
{
    if(game->tex.we)
    {
        printf("Error\nDuplicate WE texture definition\n");
        exit(1);
    }
    else if(!tokens[1])
    {
        printf("Error\nWE texture path missing\n");
        exit(1);
    }
    else
    {
        game->tex.we_path = get_texture_path(tokens[1], "WE");
        game->tex.we = 1;
    }
}

void    parse_ea(char **tokens, t_game *game)
{
    if(game->tex.ea)
    {
        printf("Error\nDuplicate EA texture definition\n");
        exit(1);
    }
    else if(!tokens[1])
    {
        printf("Error\nEA texture path missing\n");
        exit(1);
    }
    else
    {
        game->tex.ea_path = get_texture_path(tokens[1], "EA");
        game->tex.ea = 1;
    }
}