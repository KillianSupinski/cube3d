/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:31:00 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/12 12:18:57 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst2;
	const unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (!dst2 && !src2)
		return (NULL);
	if (src2 > dst2)
	{
		i = 0;
		while (i < n)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			dst2[n] = src2[n];
	}
	return (dst);
}
/*
int	main(void)
{
	char	dst[] = "test";
	char	src[] = "tyyii";

	printf("%s", ft_memmove(dst, src, 2));
}*/
