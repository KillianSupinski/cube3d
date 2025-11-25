/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 07:42:20 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/06/04 10:37:00 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_strndup(const char *str, char c)
{
	int		i;
	int		size;
	char	*cpy;

	i = 0;
	size = 0;
	while (str[size] != c && str[size])
		size++;
	cpy = malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	while (str[i] != c && str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static int	ft_countword(const char *str, char c)
{
	int	i;
	int	nb;
	int	count;

	i = 0;
	nb = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (count == 1)
			{
				count = 0;
				nb++;
			}
		}
		else
			count = 1;
		i++;
	}
	if (count == 1)
		nb++;
	return (nb);
}

static char	**ft_fill(char *str, char **tab, char c)
{
	int		count;
	int		i;

	count = 1;
	i = -1;
	while (*str != '\0')
	{
		if (*str == c)
			count = 1;
		else if (*str != '\0')
		{
			if (count == 1)
			{
				tab[++i] = ft_strndup(str, c);
				if (!tab[i])
					return (ft_free(tab), NULL);
				count = 0;
			}
		}
		str++;
	}
	return ((tab[++i] = NULL), tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	char	*str;
	int		nb;

	str = (char *)s;
	nb = ft_countword(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!tab)
		return (NULL);
	if (nb == 0)
		tab[0] = NULL;
	else
		tab = ft_fill(str, tab, c);
	return (tab);
}
/*
int	main(void)
{
	char	**tab;
	int		i;
	char	c;

	c = ' ';
	tab = ft_split(" le de of", ' ');
	i = 0;
	printf("tab1:\n");
	while (tab[i])
	{
		printf("%s", tab[i]);
		printf("\n");
		i++;
	}
}*/
