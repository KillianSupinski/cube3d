/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:04:25 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:46:29 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	parse_line(char **tokens, t_game *game)
{
	if (parse_tex(tokens, game))
		return (1);
	if (parse_color(tokens, game))
		return (1);
	return (0);
}

void	print_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		printf("Token %d: %s\n", i, tmp[i]);
		i++;
	}
}

void	set_map_start(t_game *game, int start_line)
{
	int	i;
	int	max_width;
	int	line_length;

	i = 0;
	max_width = 0;
	while (game->file_lines[start_line + i]
		&& !is_empty_line(game->file_lines[start_line + i]))
		i++;
	game->map.height = i;
	i = 0;
	while (i < game->map.height)
	{
		line_length = ft_strlen(game->file_lines[start_line + i]);
		if (line_length > 0 && game->file_lines[start_line + i][line_length
			- 1] == '\n')
			line_length--;
		if (line_length > max_width)
			max_width = line_length;
		i++;
	}
	game->map.width = max_width;
}

void	check_after_map_empty_lines(t_game *game, int line_index)
{
	while (game->file_lines[line_index])
	{
		if (!is_empty_line(game->file_lines[line_index]))
			error_exit(game, "Non-empty line found after map definition\n");
		line_index++;
	}
}

void	build_map(t_game *game, int start_line)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	game->map.grid = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		error_exit(game, "Memory allocation failed\n");
	while (i < game->map.height)
	{
		game->map.grid[i] = (char *)malloc(sizeof(char) * (game->map.width
					+ 1));
		if (!game->map.grid[i])
			error_exit(game, "Memory allocation failed\n");
		len = ft_strlen(game->file_lines[start_line + i]);
		if (len > 0 && game->file_lines[start_line + i][len - 1] == '\n')
			len--;
		j = 0;
		while (j < game->map.width)
		{
			if (j < len)
				game->map.grid[i][j] = game->file_lines[start_line + i][j];
			else
				game->map.grid[i][j] = ' ';
			j++;
		}
		game->map.grid[i][j] = '\0';
		i++;
	}
	game->map.grid[i] = NULL;
	check_after_map_empty_lines(game, start_line + game->map.height);
}

int	parse_file(t_game *game)
{
	int i;
	char **tmp;

	i = 0;
	while (game->file_lines[i])
	{
		if (all_text_and_color_set(game))
			break ;
		if (!is_empty_line(game->file_lines[i]))
		{
			tmp = ft_split(game->file_lines[i], ' ');
			if (!tmp)
				error_exit(game, "Memory allocation failed\n");
			if (parse_line(tmp, game))
				error_exit(game, "Invalid line in configuration\n");
			free_split(tmp);
		}
		i++;
	}
	while (game->file_lines[i] && is_empty_line(game->file_lines[i]))
		i++;
	set_map_start(game, i);
	build_map(game, i);
	return (0);
}