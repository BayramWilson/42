/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:28:21 by bwilson           #+#    #+#             */
/*   Updated: 2025/11/29 02:31:48 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(char x)
{
    if((x >= 'a' && x <= 'z') 
    || (x >= 'A' && x <= 'Z'))
    return 1;
    else
    return 0;
}
// #include <stdio.h>
// int main(void)
// {
//     char x = ' ';

//     printf("%i", ft_isalpha(x));
// }
