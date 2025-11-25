/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 06:39:41 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/12 12:28:33 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	int			i;
	long int	nb;

	nb = n;
	count = ft_count(nb);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	i = count - 1;
	while (i >= 0)
	{
		str[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	str[count] = '\0';
	return (str);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(-500));
}*/
