/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:17:04 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/13 15:41:27 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlower(unsigned int nb)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (nb > 15)
	{
		count += ft_hexlower(nb / 16);
		count += ft_hexlower(nb % 16);
	}
	else
		count += ft_putchar(hex[nb]);
	return (count);
}
