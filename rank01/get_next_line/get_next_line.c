/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:09:38 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/06 18:07:06 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



// char *get_next_line(int fd)
// {
//     // int fd;
//     // int sz;
//     // char *c;

//     // c = (char*)calloc(100, sizeof(char));
//     // fd = open("test.txt", O_RDONLY);
//     // sz = read(fd, c, 10);
//     // fclose(fd);
//     // return 0;
//     // int fd, sz;
// 	// char* c = (char*)calloc(100, sizeof(char));

// 	// fd = open("foo.txt", O_RDONLY);
// 	// if (fd < 0) {
// 	// 	perror("r1");
// 	// 	exit(1);
// 	// }

// 	// sz = read(fd, c, 10);
// 	// printf("called read(% d, c, 10). returned that"
// 	//        " %d bytes were read.\n",
// 	//        fd, sz);
// 	// c[sz] = '\0';
// 	// printf("Those bytes are as follows: % s\n", c);

// 	// return 0;
// }

// FILE *fptr;
int main(void)
{
//     // Open a file in read mode
//     fptr = fopen("test.txt", "r");

//     // Store the content of the file
//     char myString[100];

//  while(fgets(myString, 100, fptr)) {
//   printf("%s", myString);
// }

//     // Close the file
//     fclose(fptr);
    //get_next_line;

        /* FUNCTIONAL */ 
    // int fd, sz;
	// char* c = (char*)malloc(100);
    // char buffer[1024];
    // char dummy;
	// fd = open("test.txt", O_RDONLY);
	// if (fd < 0) {
	// 	perror("r1");
	// 	exit(1);
	// }
    // sz = read(fd, &dummy, 10);
    // sz = read(fd, buffer, sizeof(buffer));
    
    // printf("%s\n", buffer);
    // free(c);
	// return 0;

    int fd;
    int stash;
    static char buffer[256];
    int i = 0;
    char line[256];
    int j = 0;
    fd = open("test.txt", O_RDONLY);
    stash = 1;
    while((stash != 0))
    {
        stash = read(fd, buffer, 5);
        if(stash == 0)
        {
            break;
        }
        //buffer = line[i];
        while(buffer[j])
        {
            //printf("%d\n", j);
            if(buffer[j] == '\n')
            {
                i++;
            }
            j++;
        }
        j = 0;
        printf("%s\n", buffer);
    }
    //printf("buffer contains: %s\n", line);
    printf("i = %i", i);

    // int fd;
    // int stash;
    // char buffer[42];

    // while(stash = read(fd, buffer, BUFFER_SIZE))
}
