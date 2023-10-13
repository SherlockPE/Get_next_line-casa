/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:16 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/13 22:01:05 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*get_next_line(int fd)
{
	int data;
	int start;
	int len;
	char buffer[BUFFER_SIZE];
	char *result;

	
	data = read(fd, &buffer, BUFFER_SIZE);
	if (data == -1)
		printf("Error al leer el archivo (read)");
		return (0);

	printf("%s", buffer);
	start = 0;
	len = ft_strchr(buffer, '\n');
	result = ft_substr(buffer, start, len);
	return (result);
}
