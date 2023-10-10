/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:16 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/10 16:11:03 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*get_next_line(int fd)
{
	// char 	buffer;
	static char 	line[BUFFER_SIZE];
	int		nbr;
	int		i;

	i = 0;
	while ((nbr = read(fd, &line[i], 1) > 0) && line[i] != '\n')
	{
		// printf("Valor del Buffer: %c\n", buffer);
		// printf("Valor del Buffer: %c\n", line[i]);
		// line[i] = buffer;
		i++;
	}
	return (ft_strdup(line));
	// int		read_value;
	// char	*lines;
	// char	*buffer[sizeof(BUFFER_SIZE)];
	// int		size;
	// char	*heap_lines;
	// int		i;

	// //


	// // Leer archivo BUFFER_SIZE cantidad de veces
	// read_value = (int)read(fd, buffer, BUFFER_SIZE);
	// if (read_value == 0)
	// 	return (0);
	// // Guardar el contenido del buffer en un char*
	// lines = buffer;
	// // Memoria
	// size = ft_strlen(lines);
	// heap_lines = malloc(size);
	// // Copiar datos
	// i = 0;
	// while (size--)
	// 	heap_lines[size] = lines[size];
	// return (heap_lines);
}
