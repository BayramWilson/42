/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:05:40 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/02 10:21:42 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *memmove(void *dest, void *src, int n)
{
    int i;
    i = 0;
    char *cdest = (char *)dest;
    char *csrc = (char *) src;
    while(csrc[i])
    i++;
    while(i > 0)
    {
        cdest[i] = csrc[i];
        i--;
    }
    return dest;
}
