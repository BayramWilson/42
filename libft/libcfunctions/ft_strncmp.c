/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:02:07 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/02 13:35:26 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strncmp(char *s1, char *s2, int n)
{
    int i;
    i = 0;
    while(n > 0 && s1[i] && s2[i])
    {
        if(s1[i] != s2[i])
        return(s1[i] - s2[i]);
        i++;
        n--;
    }
    if(n > 0)
    return(s1[i] - s2[i]);

    return 0;

}

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[12] = "hallo";
    char s2[12] = "hallobayram";

    int result = strncmp(s1, s2, 11);
    int my_result = ft_strncmp(s1, s2, 11);

    printf("Library-Result: %d\nMy Result: %d\n", result, my_result);
}
