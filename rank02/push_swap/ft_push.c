/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:59:46 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/19 16:42:46 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push(t_list **from, t_list **to)
{
    t_list *tmp;
    
    if (!from || !*from)
        return;
    tmp = *from;
    *from = tmp->next;
    tmp->next = *to;
    *to = tmp; 
}