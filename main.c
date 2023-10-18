/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:40:59 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/10/18 23:30:41 by fabriciolop      ###   ########.fr       */
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
	fd = open(argv[1]);
	if (fd == -1)
		return (0);
	
	//Llamar a la funcion N veces
	i = (int)argv[2];
	while (i > 0)
	{
		line = get_next_line(fd);
		i--;
	}	
	return 0;
}
