/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:55 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/10/20 18:12:35 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_archive(char *buffer,int fd)
{
	ssize_t 	data;
	char	*result;

	data = 1;
	result = "";
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(buffer, '\n'))
	{
		data = read(fd, buffer, BUFFER_SIZE);
		if (data <= 0)
		{
			free(buffer);
			return (result);
		}
		buffer[data] = 0;
		result = ft_strjoin(result, buffer);
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	line = read_archive(buffer, fd);
	if (!line[0])
		return (0);
	return (line);
}

// I need:
//     1.- Funcion de lectura char *read_archive(fd, char *str);
//     2.- Funcion de creación de linea 
//     3.- Funcion de 