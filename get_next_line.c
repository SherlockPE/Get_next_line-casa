/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:55 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/10/22 17:11:53 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_archive(char *buffer, int fd)
{
	ssize_t	data;
	char	*result;

	data = 1;
	result = "";
	if (!buffer)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (0);
	}
	else
		result = ft_strjoin(result, buffer);
	while (!ft_strchr(buffer, '\n'))
	{
		data = read(fd, buffer, BUFFER_SIZE);
		if (data <= 0)
			return (free(buffer), result);
		result = ft_strjoin(result, buffer);
	}
	return (free(buffer), result);
}

char	*create_line(char *str)
{
	char	*result;
	int		i;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
		result = malloc(i + 1);
	else
	{
		result = malloc(i + 2);
		result[i + 1] = 0;
	}
	while (i >= 0)
	{
		result[i] = str[i];
		i--;
	}
	// str = free_and_delete(str);
	return (result);
}
char	*free_and_delete(char *str)
{
	int		i;
	int		size;
	char	*result;
	int		final_size;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	size = ft_strlen(str);
	final_size = size - i;
	result = malloc(final_size);
	// j = 0;
	while (--final_size >= 0)
	{
		result[final_size] = str[size--];
		// size--;
	}
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result;

	line = read_archive(line, fd);
	// if (!line[0])
	// 	return (0);
	result = create_line(line);
	line = free_and_delete(line);
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