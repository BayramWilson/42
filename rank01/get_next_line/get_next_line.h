/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:10:05 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/05 16:47:56 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../rank00/libft/libft.h"
char *get_next_line(int fd);
#endif