/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:16 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/16 15:28:11 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_create_line(char *str)
{
	int		i;
	char	*result;

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

char	*ft_delete_garbage(char *str)
{
	int		i;
	int		size;
	char	result[BUFFER_SIZE];

	size = 0;
	while (str[size] != '\n')
		size++;
	size++;
	i = 0;
	while (str[size])
	{
		printf("%c", str[size]);
		result[i++] = str[size];
		size++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	int			data;
	char		temp[BUFFER_SIZE + 1];
	static char	*buffer;
	char		*result;

	//------LEER EL ARCHIVO------//
	while (!ft_strchr(buffer, '\n'))
	{
		data = read(fd, temp, BUFFER_SIZE);
		if (data == -1)
			return (0);
		buffer = ft_strjoin(buffer, temp);
	}
	//------CREAR SUBSTRING------//
	result = ft_create_line(buffer);
	buffer = ft_delete_garbage(buffer);
	return (result);
}
