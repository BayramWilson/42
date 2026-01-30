/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:17:55 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/28 17:16:11 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (!new_node || !lst)
		return ;
	if (*lst != NULL)
	{
		last = ft_lstlast(*lst);
		last->next = new_node;
	}
	else
	{
		new_node->next = *lst;
		*lst = new_node;
	}
}
