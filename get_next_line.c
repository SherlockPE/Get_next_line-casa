/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:16 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/14 15:05:20 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int data;
	int start;
	int len;
	char *result;
	static char buffer[BUFFER_SIZE];

	//------INICIO------//
	printf("El programa está ejecutando get_next_line\n");
	
	//------MEMORIA para el BUFFER------//
	// char *buffer = (char *)malloc(BUFFER_SIZE);
	// if (!buffer)
	// {
	// 	printf("No se pudo crear memoria en el buffer\n");
	// 	return (0);
	// }
	// printf("El buffer tiene memoria\n");

	//------LEER EL ARCHIVO------//
	data = read(fd, buffer, BUFFER_SIZE);
	if (data == -1)
	{
		printf("Error al leer el archivo (read)");
		return (0);
	}
	printf("Archivo leido bien (read)\n");

	//------VALOR DE LA LECTURA------//
	printf("Valor del buffer: %s\n", buffer);
	
	//------CREAR SUBSTRING------//
	start = 0;
	len = ft_strchr(buffer, '\n');
	printf("Valor de len: %d\n", len);
	
	result = ft_substr(buffer, start, len);
	printf("Valor final: %s\n", result);
	return (result);
}
