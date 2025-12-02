/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:12:43 by bwilson           #+#    #+#             */
/*   Updated: 2025/11/29 02:31:12 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_memset(char *str, char repl, int amt)
{
        int i;
        i = 0;
        while(amt > 0)
        {
            str[i] = repl;
            i++;
            amt--;
        }
}

#include <stdio.h>
int main(void)
{
    char str[50] = "Welcome to Tutorialspoint";
    char repl = '#';
    int amt = 8;

    printf("Before memset: %s\n", str);
    ft_memset(str, repl, amt);
    printf("After memset: %s\n", str);
}