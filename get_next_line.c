/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:55 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/10/20 21:07:55 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_archive(char *buffer,int fd)
{
	ssize_t 	data;
	char	*result;

	data = 1;
	result = "";
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(buffer, '\n'))
	{
		data = read(fd, buffer, BUFFER_SIZE);
		if (data <= 0)
		{
			free(buffer);
			return (result);
		}
		buffer[data] = 0;
		result = ft_strjoin(result, buffer);
	}
	free(buffer);
	return (result);
}

char    *create_line(char *str)
{
    char    *result;
    int        i;
    
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
    //str = free_and_delete(str);
    return (result);
}
char    *free_and_delete(char *str)
{
    int   i;
    int   size;
    char  *result;
    int   final_size;
    
    i = 0;
    while (str[i] != '\n' && str[i])
      i++;
    size = ft_strlen(str);
    final_size = size - i;
    result = malloc(final_size);
    //j = 0;
    while (--final_size >= 0)
    {
      result[final_size] = str[size--];
      //size--;
    }
    free(str);
    return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	
	line = read_archive(buffer, fd);
	if (!line[0])
		return (0);
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
//   return 0;
// }