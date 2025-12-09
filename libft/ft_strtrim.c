/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:28:09 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/09 13:41:36 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char *ft_strtrim(char const *s1, char const *set)
{
    size_t  i;
    size_t  j;
    char    *result;
    
    i = 0;
    j = 0;
    while(s1[i])
    {
        if (s1[i] != set[j])
        {    
            s1[i] == result[i];
            j++;
        }
        else if (s1[i] == set[j])
            j++;
    }
}
