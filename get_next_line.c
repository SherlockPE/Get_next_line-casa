/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:55 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/10/24 17:37:14 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*read_archive(char *buffer, int fd)
{
	int	data;
	char *temp;
	char *aux;

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
	return (free(temp), temp = NULL ,buffer);
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
		return (free(str), str = NULL, NULL);
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
	while (--final_size >= 0)
		result[final_size] = str[size--];
	return (free(str), str = NULL, result);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(line), line = NULL, NULL);
	line = read_archive(line, fd);
	if (!line)
		return (line = NULL, NULL);
	else if(!line[0])
		return (free(line), line = NULL, NULL);
	result = create_line(line);
	if (!result)
		return (NULL);
	line = free_and_delete(line);
	//system("leaks -q a.out");
	return (result);
}

// I need:
// 1.- Funcion de lectura: char 		*read_archive(fd, char *str);
// 2.- Funcion de creación de linea: char	*create_line(char *str);
// 3.- Funcion de eliminación de basura restante

// int main() {

//   static char *line;
//   char  *result;

//   line = (char *)malloc(13);
//   strcpy(line, "Hola\nque\ntal");

//   result = create_line(line);
//   line = free_and_delete(line);

//   printf("%s", result);
//   return (0);
// }