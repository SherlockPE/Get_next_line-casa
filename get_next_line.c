/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:16 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/17 17:33:15 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_line(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
		result = (char *)malloc(i + 1);
	else
	{
		result = (char *)malloc(i + 2);
		result[i + 1] = 0;
	}
	while (i >= 0)
	{
		result[i] = str[i];
		i--;
	}
	return (result);
}

char	*ft_delete_garbage(char *str)
{
	int		i;
	int		size;
	char	*result;

	result = malloc(BUFFER_SIZE);
	size = 0;
	while (str[size] != '\n')
		size++;
	size++;
	i = 0;
	if (!str[size])
	{
		free(str);
		return (0);
	}
	while (str[size])
		result[i++] = str[size++];
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	ssize_t		data;
	char		*buffer;
	static char	*result;
	char		*temporal;

	data = 7;
	//------ASIGNAR MEMORIA AL BUFFER------//
	buffer = malloc(BUFFER_SIZE + 1);
	//------LEER EL ARCHIVO------//
	while (!ft_strchr(result, '\n') && data)
	{
		data = read(fd, buffer, BUFFER_SIZE);
		if (data == -1)
			return (0);
		result = ft_strjoin(result, buffer);
	}
	//------CREAR SUBSTRING------//
	temporal = ft_create_line(result);
	result = ft_delete_garbage(result);
	free(buffer);
	return (temporal);
}
