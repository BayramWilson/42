/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:49:19 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/15 19:14:43 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int count_words(char const *s, char c)
{
    size_t  i;
    size_t  words;
    int     is_word;

    is_word = 0;
    i = 0;
    words = 0;
    while(s[i])
    {
        if(s[i] != c && is_word == 0)
        {
            is_word = 1;
            words++;
        }
        else if(s[i] == c)
            is_word = 0;
        i++;
    }
    return words;
}

char **extract_word(char const *s, char c)
{
    size_t  i;
    int     j;
    int     is_word;
    int     start;
    char    *temp;

    i = 0;
    is_word = 0;
    j = 0;
    start = 0;
    while(s[i])
    {
        if(s[i] != c && is_word == 0)
        {
            is_word = 1;
            j++;
        }
        else if(s[i] == c)
            is_word = 0;
        i++;
    }
}

char **ft_split(char const *s, char c)
{
    char **result;

    result = malloc(sizeof(char *) * (count_words(s, c) + 1));

    return result;
}