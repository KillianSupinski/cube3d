/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:52:13 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:46:31 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	is_valid_color_value(t_game *game, char *s)
{
	int		value;
	char	*trimmed;
	int		i;

	i = 0;
	trimmed = ft_strtrim(s, " \t\n\r\f\v");
	if (!trimmed)
		error_exit(game, "Memory allocation failed\n");
	while (trimmed[i])
	{
		if (trimmed[i] < '0' || trimmed[i] > '9')
		{
			free(trimmed);
			return (0);
		}
		i++;
	}
	value = ft_atoi(trimmed);
	free(trimmed);
	return (value >= 0 && value <= 255);
}

void	floor_color(char *color_str, t_game *game)
{
	char	**rgb;

	if (game->tex.floor_set)
		error_exit(game, "Duplicate floor color definition\n");
	rgb = ft_split(color_str, ',');
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		error_exit(game, "Invalid floor color format\n");
	if (!is_valid_color_value(game, rgb[0]) || !is_valid_color_value(game,
			rgb[1]) || !is_valid_color_value(game, rgb[2]))
		error_exit(game, "Floor color values must be between 0 and 255\n");
	game->tex.floor.r = ft_atoi(rgb[0]);
	game->tex.floor.g = ft_atoi(rgb[1]);
	game->tex.floor.b = ft_atoi(rgb[2]);
	game->tex.floor_set = 1;
	free_split(rgb);
}

void	ceiling_color(char *color_str, t_game *game)
{
	char	**rgb;

	if (game->tex.ceiling_set)
		error_exit(game, "Duplicate ceiling color definition\n");
	rgb = ft_split(color_str, ',');
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		error_exit(game, "Invalid ceiling color format\n");
	if (!is_valid_color_value(game, rgb[0]) || !is_valid_color_value(game,
			rgb[1]) || !is_valid_color_value(game, rgb[2]))
		error_exit(game, "Ceiling color values must be between 0 and 255\n");
	game->tex.ceiling.r = ft_atoi(rgb[0]);
	game->tex.ceiling.g = ft_atoi(rgb[1]);
	game->tex.ceiling.b = ft_atoi(rgb[2]);
	game->tex.ceiling_set = 1;
	free_split(rgb);
}

int	color_cmp(char **tokens)
{
	if (ft_strcmp(tokens[0], "F") == 0 || ft_strcmp(tokens[0], "C") == 0)
		return (1);
	return (0);
}

int	parse_color(char **tokens, t_game *game)
{
	int n;

	if (!color_cmp(tokens))
		return (0);
	n = count_tokens(tokens);
	if (n > 2)
		error_exit(game, "Too many arguments for color definition\n");
	if (ft_strcmp(tokens[0], "F") == 0 && tokens[1])
	{
		floor_color(tokens[1], game);
		return (1);
	}
	else if (ft_strcmp(tokens[0], "C") == 0 && tokens[1])
	{
		ceiling_color(tokens[1], game);
		return (1);
	}
	return (0);
}