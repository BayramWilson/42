/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:29:27 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/06 18:44:45 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int fd;
    int bytes_read;
    char *buf;
    int BUFFER_SIZE = 100;
    int i = 0;
     
    fd = open(argv[1], O_RDONLY);
    buf = malloc(BUFFER_SIZE + 1);
    if(!buf)
        return (0);
    bytes_read = 1;
    while((bytes_read != 0))
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if(bytes_read == 0)
            break ;
        buf[bytes_read] = '\0';
        printf("%s", buf);
        i++;

    }
    fd = close(fd);
    printf("%i\n", i);
    return 0;
}
