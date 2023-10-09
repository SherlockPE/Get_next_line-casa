/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:16 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/09 14:04:07 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

static int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	int		read_value;
	char	*lines;
	char	*buffer[sizeof(BUFFER_SIZE)];
	int		size;
	char	*heap_lines;
	int		i;

	// Leer archivo BUFFER_SIZE cantidad de veces
	read_value = (int)read(fd, buffer, BUFFER_SIZE);
	if (read_value == 0)
		return (0);
	// Guardar el contenido del buffer en un char*
	lines = buffer;
	// Memoria
	size = ft_strlen(lines);
	heap_lines = malloc(size);
	// Copiar datos
	i = 0;
	while (size--)
		heap_lines[size] = lines[size];
	return (heap_lines);
}
