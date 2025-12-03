/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:21:22 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/02 13:50:24 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlcpy(char *src, char *dest, int size)
{
    int i;
    i = 0;
    while(size > 1)
    {
        dest[i] = src[i];
        i++;
        size--;
    }
    return i;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[12] = "Hello World";
    char src1[12] = "Hello World";
    char dest[50];
    char dest1[50];

    strlcpy(dest, src, 4);
    ft_strlcpy(src1, dest1, 4);
    printf("Library Function: %s\nMy Function: %s\n", dest, dest1);

}
