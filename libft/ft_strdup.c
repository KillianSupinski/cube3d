/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:35:22 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/06 14:35:24 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	i = 0;
	while (s[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * i + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/*#include <stdio.h>
int	main()
{
	const char *str;
	char *f;

	str = "xd";
	f = ft_strdup(str);
	printf("%s", f);
}*/
