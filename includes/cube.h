/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:17:12 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/11/25 15:58:00 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_color {
	int r;
	int g;
	int b;
}	t_color;

typedef struct s_map {
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_tex {
	char *no;
	char *so;
	char *we;
	char *ea;
	t_color floor;
	t_color ceiling;
}	t_tex;

typedef struct s_player {
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
}	t_player;

typedef struct s_game {
	t_map		map;
	t_tex		tex;
	t_player	player;
    char        **file_lines;
}	t_game;

void    parsing(int ac, char **av, t_game *game);

#endif