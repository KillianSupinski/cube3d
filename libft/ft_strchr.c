/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:35:10 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/12 11:31:09 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	k;
	unsigned char	*str;

	i = 0;
	k = (unsigned char)c;
	str = (unsigned char *)s;
	while (str[i] && str[i] != k)
		i++;
	if (str[i] != k)
		return (NULL);
	else
		return ((char *)&str[i]);
}
/*
int	main()
{
	char str[] = "aaaest";
	printf("%s", ft_strchr(str, 't'));
}*/
