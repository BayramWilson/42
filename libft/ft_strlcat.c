/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:35:12 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/05 11:22:28 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *x)
{
    int i;

    i = 0;
    while(x[i])
        i++;
    return (i);
}

char ft_strlcat(char *dest, char *src, int n)
{
    int i;
    int j;

    j = 0;
    i = ft_strlen(dest);
    while(n > 0)
    {
        dest[i] = src[j];
        i++;
        j++;
        n--;
    }
    return (*dest);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
    char dest[20] = "hallo";
    char src[6] = " Welt";
    int result;

    result = ft_strlcat(dest, src, 3);
    printf("%s\n%d", dest, result);

}
