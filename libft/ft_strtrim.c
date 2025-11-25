/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:11:22 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/12 15:38:58 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = ft_strlen(s1);
	count = 0;
	while (ft_check(s1[i], set) == 1)
		i++;
	j--;
	while (ft_check(s1[j], set) == 1)
		j--;
	while (i <= j)
	{
		count++;
		i++;
	}
	return (count);
}

static char	*ft_fill(const char *s1, const char *set, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = ft_strlen(s1);
	while (ft_check(s1[i], set) == 1)
		i++;
	j--;
	while (ft_check(s1[j], set))
		j--;
	while (i <= j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		count;
	char	*str;

	count = ft_count(s1, set);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str = ft_fill(s1, set, str);
	return (str);
}
/*
int	main(void)
{
	printf("%s", ft_strtrim(" lorem \n ipsum \t dolor \n sit \t amet", " "));
}*/
