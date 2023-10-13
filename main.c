/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:02:20 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/13 22:35:28 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Inicio del programa\n");
	int i;
	int fd;
	
	//Usar Open para obtener un file descriptor
	printf("Abriendo el archivo...\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{		
		printf("Error al abrir el archivo (open)\n");
		return (0);
	}
	printf("Archivo abierto correctamente (open)\n");
	
	//Imprimir las lineas
	i = 6;
	while (i--)
	{
		printf("Llamando a la funcion get_next_line...)\n");
		printf("%s\n", get_next_line(fd));
	}
	return (0);
	
/* 	printf("Inicio del programa\n");
	int			fd;
	// const char	*path;
	char		*line;

	// path = "prueba.txt";
	
	printf("Abriendo el archivo...\n");
	fd = open("./prueba.txt", O_RDONLY);

	if (fd == -1)
		printf("Error al abrir el archivo (open)\n");
		return (0);

	printf("Archivo abierto correctamente (open)\n");
	printf("Llamando a la funcion get_next_line...)\n");
	
	line = get_next_line(fd);
	printf("%s", line);

	close(fd);
	free(line);
	return (0); */

/* 	line = get_next_line(fd);
	printf("%s", line); */
	
/* 	int i = 10;
	while (i--)
	{
		line = get_next_line(fd);
		printf("%s", line);
	} */
}
