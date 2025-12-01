/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:23:54 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/01 15:14:39 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int all_text_and_color_set(t_game *game)
{
    if (game->tex.no && game->tex.so && game->tex.we && game->tex.ea \
        && game->tex.floor_set && game->tex.ceiling_set)
        return (1);
    return (0);
}

int is_empty_line(char *line)
{
    int i = 0;

    if (!line)
        return (1);
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    return (line[i] == '\0' || line[i] == '\n');
}

void free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int count_tokens(char **tokens)
{
    int count = 0;

    while (tokens[count])
        count++;
    return (count);
}

int text_cmp(char **tokens)
{
    if (ft_strcmp(tokens[0], "NO") == 0 || ft_strcmp(tokens[0], "SO") == 0 || \
        ft_strcmp(tokens[0], "WE") == 0 || ft_strcmp(tokens[0], "EA") == 0)
        return (1);
    return (0);
}