/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:56:09 by bwilson           #+#    #+#             */
/*   Updated: 2025/11/28 14:23:13 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isdigit(char x)
{
    if(x >= '0' && x <= '9') 
    return 1;
    else
    return 0;
}

// #include <stdio.h>
// int main(void)
// {
//     char x = '0';
//     char y = '9';
//     char z = 'a';
//     printf("%d", ft_isdigit(x));
//     printf("%d", ft_isdigit(y));
//     printf("%d", ft_isdigit(z));
// }