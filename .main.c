/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:02:20 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/18 21:51:30 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	int i;
	char * line;
	//system("leaks a.out");
	//------Obtener un file descriptor------//
	int fd;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{		
		printf("Error al abrir el archivo (open)\n");
		return (0);
	}
	
	//------Imprimir las lineas------//
	i = 4;
	while (i--)
	{
		printf("Llamando a la funcion get_next_line...)\n");
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}
