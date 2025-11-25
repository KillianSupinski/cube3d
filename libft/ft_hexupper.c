/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:20:55 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/13 15:41:21 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexupper(unsigned int nb)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (nb > 15)
	{
		count += ft_hexupper(nb / 16);
		count += ft_hexupper(nb % 16);
	}
	else
		count += ft_putchar(hex[nb]);
	return (count);
}
