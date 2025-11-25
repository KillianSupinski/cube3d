/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:32:07 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/07/27 17:47:54 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		n;

	i = 0;
	nb = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * n);
}

int	ft_preci(const char *str)
{
	int	i;
	int	preci;
	int	nb;

	nb = 0;
	i = 0;
	preci = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] != '.')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] != '.')
			nb++;
		i++;
	}
	while (nb--)
		preci *= 10;
	return (preci);
}

double	ft_atod(const char *str)
{
	int		i;
	double	nb;
	int		n;
	int		precision;

	i = 0;
	nb = 0;
	n = 1;
	precision = ft_preci(str);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] != '.')
			nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (((double)nb * n) / precision);
}
