/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:09:38 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/13 15:40:52 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_print(const unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n > 15)
	{
		count += ft_print(n / 16);
		count += ft_print(n % 16);
	}
	else
		count += ft_putchar(hex[n]);
	return (count);
}

int	ft_printadr(void *s)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_print((unsigned long)s);
	return (count);
}
