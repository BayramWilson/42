/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:18:15 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/11 19:21:58 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr_fd(int n, int fd)
{
    char converted_number;

    converted_number = (char) n;
    write(fd, &converted_number, 1);
    write(fd, "\n", 1);
}