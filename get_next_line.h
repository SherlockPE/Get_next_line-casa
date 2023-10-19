/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:41:29 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/10/19 16:13:08 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H

 #ifndef BUFFER_SIZE
  #define BUFFER_SIZE 1
 #endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
// # include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif