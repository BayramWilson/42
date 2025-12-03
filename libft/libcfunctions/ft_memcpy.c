/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 09:52:43 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/01 11:09:22 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *dest, void *src, int n)
{
    int i;

    i = 0;
    char *cdest = (char *)dest;
    char *csrc = (char *) src;
    while(n > 0)
    {
        cdest[i] = csrc[i];
        i++;
        n--;
    }
    return dest;
}

#include <stdio.h>
int main(void)
{
    int a = 4;
    int b = 5;
    
    printf("Value of b before calling memcpy: %d\n", b);

    ft_memcpy(&b, &a, 3);

    printf("Value of b after calling memcpy: %d\n", b);
}
