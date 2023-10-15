/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:16 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/15 16:40:31 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_create_line(char *str)
{
	int i;
	char *result;

	i = 0;
	while (str[i] != '\n')
		i++;
	result = (char *)malloc(i + 2);
	result[i + 1] = 0;
	while (i >= 0)
	{
		result[i] = str[i];
		i--;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	int data;
	char temp[BUFFER_SIZE + 1];
	static char *buffer;
	char *result;

	//------LEER EL ARCHIVO------//
	while (!ft_strchr(buffer, '\n'))
	{
		data = read(fd, temp, BUFFER_SIZE);
		if (data == -1)
			return (0);
		buffer = ft_strjoin(buffer, temp);
	}

	//------VALOR DE LA LECTURA------//
	// printf("Valor del buffer: %s\n", buffer);

	//------CREAR SUBSTRING------//
	result = ft_create_line(buffer);
	

/* 	start = 0;
	len = ft_strchr(buffer, '\n');
	printf("Valor de len: %d\n", len);
	
	result = ft_substr(buffer, start, len + 1);
	printf("Valor final: %s\n\n", result);
	return (result); */
	return (result);
}

	//------MEMORIA para el BUFFER------//
	// char *buffer = (char *)malloc(BUFFER_SIZE);
	// if (!buffer)
	// {
	// 	printf("No se pudo crear memoria en el buffer\n");
	// 	return (0);
	// }
	// printf("El buffer tiene memoria\n");