/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:59 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/10/19 16:27:00 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char const *argv[])
{
	int		i;
	int		fd;
	char	*line;
	
	(void)argc;
	//Obtener un file descriptor
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	
	//Llamar a la funcion N veces
	i = atoi(argv[2]);
	while (i > 0)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		// free(line);
		i--;
	}	
	return 0;
}
