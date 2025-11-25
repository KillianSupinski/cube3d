/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:52:24 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/06/02 14:44:32 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(const char *str, va_list args)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*str == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*str == 'i' || *str == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (*str == 'p')
		return (ft_printadr(va_arg(args, void *)));
	if (*str == 'u')
		return (ft_putunsnbr(va_arg(args, unsigned int)));
	if (*str == 'x')
		return (ft_hexlower(va_arg(args, unsigned int)));
	if (*str == 'X')
		return (ft_hexupper(va_arg(args, unsigned int)));
	return (ft_putchar('%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	va_start(args, str);
	len = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_convert(&str[i], args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
//
// int	main(void)
// {
// 	ft_printf("%%%");
// 	ft_printf("\n");
// 	printf("%d", printf("%%%"));
// }
