/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:48:11 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/06 17:35:23 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main()
{
	t_list *lst;

	lst = malloc(sizeof(t_list) * 2);
	lst->content = "test";
	lst->next->content = "ahaha";
	while(lst)
	{
		printf("%p", lst->content);
		lst->next;
	}
}*/
