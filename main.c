/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:02:20 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/13 21:42:13 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int			fd;
	const char	*path;
	char		*line;

	path = "prueba.txt";
	fd = open(path, O_RDONLY);

	if (fd == -1)
		printf("Error al abrir el archivo (open)");
		return (0);

	line = get_next_line(fd);
	printf("%s", line);

	close(fd);
	free(line);
	return (0);

/* 	line = get_next_line(fd);
	printf("%s", line); */
	
/* 	int i = 10;
	while (i--)
	{
		line = get_next_line(fd);
		printf("%s", line);
	} */
}
