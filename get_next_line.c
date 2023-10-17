/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:16 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/17 16:39:52 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_create_line(char *str)
{
    int i;
    static char *result;

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
	if (str[size] == 0)
	{
		result[0] = 0;
	}
	while (str[size])
	{
		result[i++] = str[size];
		size++;
	}
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	int			data;
	static char	*buffer;
	char		*temporal;
	char		*result;
	
	//------ASIGNAR MEMORIA AL BUFFER------//
	buffer = malloc(BUFFER_SIZE);

	//------LEER EL ARCHIVO------//
	while (!ft_strchr(temporal, '\n'))
	{
		data = read(fd, buffer, BUFFER_SIZE);
		if (data == -1)
			return (0);
		temporal = ft_strjoin(temporal, buffer);
	}
	//------CREAR SUBSTRING------//
	result = ft_create_line(temporal);
	temporal = ft_delete_garbage(temporal);
	return (result);
}
