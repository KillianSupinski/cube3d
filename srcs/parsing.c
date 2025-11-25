/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:26:48 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/11/25 16:05:50 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void    parsing_arg(int ac, char *filename)
{
    if (ac < 2)
    {
        printf("Error\nNot enough arguments\n");
        exit(1);
    }
    else if (ac > 2)
    {
        printf("Error\nToo many arguments\n");
        exit(1);
    }
    if (ft_strcmp(&filename[ft_strlen(filename) - 4], ".cub") != 0)
    {
        printf("Error\nInvalid file extension\n");
        exit(1);
    }
}


char **ft_realloc_file(char **file, char *line, int height)
{
    char **new_file;
    int    i;

    new_file = malloc(sizeof(char *) * (height + 2));
    if (!new_file)
    {
        printf("Error\nMemory allocation failed\n");
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

void    init_file(char *filename, t_game *game)
{
    int fd;
    char *line;    
    char **file;
    int  height;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\nCould not open file\n");
        exit(1);
    }
    height = 0;
    file = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        file = ft_realloc_file(file, line, height);
        height++;
        free(line);
    }
    close(fd);
    game->file_lines = file;
}

void print_map(t_game *game)
{
    int i = 0;
    while (game->file_lines[i])
    {
        printf("%s", game->file_lines[i]);
        i++;
    }
}

void    parsing(int ac, char **av, t_game *game)
{
    parsing_arg(ac, av[1]);
    init_file(av[1], game);
    print_map(game);
}