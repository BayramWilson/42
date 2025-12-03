/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 09:24:39 by bwilson           #+#    #+#             */
/*   Updated: 2025/11/30 09:52:07 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_bzero(char *str, int amt)
{
    int i;
    i = 0;
    while(amt > 0)
    {
        str[i] = '\0';
        i++;
        amt--;
    }
}

// #include <stdio.h>
// int main(void)
// {
//     char str[50] = "Work Hard Play Hard";
//     int startbyte = 11;
//     int amt = 4;

//     printf("Before bzero: %s\n", str);
//     ft_bzero(str + 5, amt);
//     printf("After bzero: %s\n", str);
// }

