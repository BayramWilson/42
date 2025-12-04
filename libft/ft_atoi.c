/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:58:17 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/04 12:18:04 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isspace(char x)
{
    if((x >= '\t' && x <= '\r') || x == ' ')
        return 1;
    return 0;
}

int ft_atoi(char *str)
{
    int i;
    i = 0;

    int result = 0;
    while(str[i])
    {
        while (ft_isspace(str[i]))
            i++;
        
        if(str[i] >= '0' && str[i] <= '9')
        {
            result = str[i] - 48;
            break;
        }
    }
    return result;
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char str[] = "3";
  int amount = ft_atoi(str);
  printf("%d\n", amount);
}