/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:55 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/10/25 18:48:04 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <string.h>

char	*read_archive(char *buffer, int fd)
{
	int		data;
	char	*temp;
	char	*aux;

	data = 1;
	temp = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	while (!ft_strchr(buffer, '\n') && data)
	{
		data = read(fd, temp, BUFFER_SIZE);
		if (data < 0)
			return (free(temp), free(buffer), NULL);
		if (data == 0)
			return (free(temp), buffer);
		temp[data] = 0;
		aux = buffer;
		buffer = ft_strjoin(buffer, temp);
		free(aux);
	}
	return (free(temp), temp = NULL, buffer);
}

char	*create_line(char *str)
{
	char	*result;
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
		result = (char *)ft_calloc(i + 1, 1);
	else
		result = (char *)ft_calloc(i + 2, 1);
	if (!result)
		return (NULL);
	while (i >= 0)
	{
		result[i] = str[i];
		i--;
	}
	return (result);
}

char	*free_and_delete(char *str)
{
	int		i;
	int		size;
	char	*result;
	int		final_size;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	size = ft_strlen(str);
	final_size = size - i;
	if (!final_size)
		return (free(str), NULL);
	result = (char *)ft_calloc(final_size, 1);
	if (!result)
		return (free(str), str = NULL, NULL);
	while (--final_size >= 0)
		result[final_size] = str[size--];
	return (free(str), str = NULL, result);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = read_archive(line[fd], fd);
	if (!line[fd])
		return (line[fd] = NULL, NULL);
	else if (!line[fd][0])
		return (free(line[fd]), line[fd] = NULL, NULL);
	result = create_line(line[fd]);
	if (!result)
		return (free(line[fd]), line[fd] = NULL, NULL);
	line[fd] = free_and_delete(line[fd]);
	return (result);
}
/* 
I need:
1.- Funcion de lectura: char 		*read_archive(fd, char *str);
2.- Funcion de creación de linea: char	*create_line(char *str);
3.- Funcion de eliminación de basura restante
 */

// int main(int argc, char const *argv[])
// {
// 	int		i;
// 	int		fd;
// 	char	*line;
// 	int temp = argc;

// 	i = 50;
// 	fd = open (argv[--argc], O_RDONLY);
	
// 	// while (i-- && --argc)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	printf("%s", line);
// 	// 	if (line)
// 	// 		free(line);
// 	// 	fd = open (argv[argc], O_RDONLY);
// 	// 	if (argc == 1)
// 	// 		argc = temp;
// 	// }
// 	return 0;
// }
