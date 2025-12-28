/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:17:16 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/12/28 22:46:27 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	parse_tex(char **tokens, t_game *game)
{
	int n;

	if (!text_cmp(tokens))
		return (0);
	n = count_tokens(tokens);
	if (n > 2)
		error_exit(game, "Too many arguments for texture definition\n");
	if (ft_strcmp(tokens[0], "NO") == 0)
		return (parse_no(tokens, game), 1);
	else if (ft_strcmp(tokens[0], "SO") == 0)
		return (parse_so(tokens, game), 1);
	else if (ft_strcmp(tokens[0], "WE") == 0)
		return (parse_we(tokens, game), 1);
	else if (ft_strcmp(tokens[0], "EA") == 0)
		return (parse_ea(tokens, game), 1);
	return (0);
}