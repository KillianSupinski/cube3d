/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:26:48 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:46:15 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	parsing_arg(int ac, char *filename)
{
	if (ac < 2)
	{
		printf("Not enough arguments\n");
		exit(1);
	}
	else if (ac > 2)
	{
		printf("Too many arguments\n");
		exit(1);
	}
	if (ft_strcmp(&filename[ft_strlen(filename) - 4], ".cub") != 0)
	{
		printf("Invalid file extension. Expected .cub file.\n");
		exit(1);
	}
}

char	**ft_realloc_file(char **file, char *line, int height)
{
	char	**new_file;
	int		i;

	new_file = malloc(sizeof(char *) * (height + 2));
	if (!new_file)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	i = 0;
	while (i < height)
	{
		new_file[i] = file[i];
		i++;
	}
	new_file[i] = ft_strdup(line);
	new_file[i + 1] = NULL;
	free(file);
	return (new_file);
}

void	init_file(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	**file;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Could not open file\n");
		exit(1);
	}
	height = 0;
	file = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		file = ft_realloc_file(file, line, height);
		height++;
		free(line);
	}
	close(fd);
	game->file_lines = file;
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->file_lines[i])
	{
		printf("%s", game->file_lines[i]);
		i++;
	}
	printf("\n");
}

void	print_config(t_game *game)
{
	printf("NO Texture: %s\n", game->tex.no_path);
	printf("SO Texture: %s\n", game->tex.so_path);
	printf("WE Texture: %s\n", game->tex.we_path);
	printf("EA Texture: %s\n", game->tex.ea_path);
	printf("Floor Color: R=%d, G=%d, B=%d\n", game->tex.floor.r,
		game->tex.floor.g, game->tex.floor.b);
	printf("Ceiling Color: R=%d, G=%d, B=%d\n", game->tex.ceiling.r,
		game->tex.ceiling.g, game->tex.ceiling.b);
}

void	print_map_info(t_map *map)
{
	int	i;

	printf("Map Height: %d\n", map->height);
	printf("Map Width: %d\n", map->width);
	printf("Map Grid:\n");
	i = 0;
	while (i < map->height)
	{
		printf("%s\n", map->grid[i]);
		i++;
	}
}

// void print_textures(t_game *game)
// {
//     printf("NO int:%d, NO Texture: %s\n", game->tex.no, game->tex.no_path);
//     printf("SO int:%d, SO Texture: %s\n", game->tex.so, game->tex.so_path);
//     printf("WE int:%d, WE Texture: %s\n", game->tex.we, game->tex.we_path);
//     printf("EA int:%d, EA Texture: %s\n", game->tex.ea, game->tex.ea_path);
//     printf("Floor Color: R=%d, G=%d, B=%d\n", game->tex.floor.r,
// game->tex.floor.g, game->tex.floor.b);
//     printf("Ceiling Color: R=%d, G=%d, B=%d\n", game->tex.ceiling.r,
// game->tex.ceiling.g, game->tex.ceiling.b);
// }

void	parsing(int ac, char **av, t_game *game)
{
	parsing_arg(ac, av[1]);
	init_file(av[1], game);
	parse_file(game);
	// print_textures(game);
	if (!game->tex.no || !game->tex.so || !game->tex.we || !game->tex.ea
		|| !game->tex.floor_set || !game->tex.ceiling_set)
	{
		printf("Missing texture definitions\n");
		exit(1);
	}
	is_valid_map(game);
	print_map(game);
	print_config(game);
	print_map_info(&game->map);
}