/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:03:56 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/12 11:30:53 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = ft_strlen(dst);
	k = ft_strlen(src);
	if (i >= size)
		return (size + k);
	while (i + j < size - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + k);
}

/*int	main()
{
	char dst[5];
	const char *src;

	dst[0] = 'a';
	src = "world";
	printf("%ld", ft_strlcat(dst, src, 5));
	printf("%s", dst);
}*/
