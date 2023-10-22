/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:59 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/10/22 20:31:31 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char const *argv[])
{
	int		i;
	int		fd;
	char	*line;

	//Obtener un file descriptor
	if (argc < 3)
		return printf("invalid arguments\n"), 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror(argv[1]), 1);
	
	//Llamar a la funcion N veces
	i = atoi(argv[2]);
	// while (i > 0)
	// {
	// 	line = get_next_line(fd);
	// 	printf("%s\n%p\n", line, line);
	// 	free(line);
	// 	i--;
	// }
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	system("leaks -q a.out");
	return 0;
}
