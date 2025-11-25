/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:10:47 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/06 17:34:33 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tlast;

	tlast = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tlast = ft_lstlast(tlast);
		tlast->next = new;
	}
}
