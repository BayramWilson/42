/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:17:37 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/19 16:50:42 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

void    ft_push(t_list **from, t_list **to);
void    ft_swap(t_list **head);
void    ft_rotate(t_list **head);


#endif