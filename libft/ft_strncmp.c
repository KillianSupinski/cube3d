/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:36:32 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/06 14:36:56 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < length)
		i++;
	if (i == length)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
int	main()
{
	const char *s1;
	const char *s2;
	s1 = "test";
	s2 = "test";
	printf("%d", ft_strncmp(s1, s2, 4));
}*/
