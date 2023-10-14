/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:02:20 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/14 14:35:24 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	printf("Inicio del programa\n");
	int i;
	int fd;
	
	//------Usar Open para obtener un file descriptor------//
	printf("Abriendo el archivo...\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{		
		printf("Error al abrir el archivo (open)\n");
		return (0);
	}
	printf("Archivo abierto correctamente (open)\n");
	
	//------Imprimir las lineas------//
	
	printf("%s\n", get_next_line(fd));
	
	// i = 6;
	// while (i--)
	// {
	// 	printf("Llamando a la funcion get_next_line...)\n");
	// 	printf("%s\n", get_next_line(fd));
	// }
	// return (0);
}
