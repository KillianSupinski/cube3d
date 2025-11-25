/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:13:37 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/06/04 14:01:34 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*newlst;
	t_list	*data;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		data = ft_lstnew(f(lst->content));
		if (!data)
		{
			ft_lstclear(&newlst);
			return (NULL);
		}
		ft_lstadd_back(&newlst, data);
		lst = lst->next;
	}
	return (newlst);
}
