/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:36:09 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/07 09:13:59 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;
	unsigned char	k;

	i = ft_strlen(s);
	k = (unsigned char)c;
	str = (unsigned char *)s;
	if (k == '\0')
		return ((char *)(&str[i]));
	i--;
	while (i >= 0)
	{
		if (str[i] == k)
			return ((char *)(&str[i]));
		i--;
	}
	return (NULL);
}
/*
int	main()
{
	char str[] = "test";
	printf("%s", ft_strrchr(str, 't'));
}*/
