/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:02:20 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/09 12:45:59 by flopez-r         ###   ########.fr       */
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
		return (0);

	line = get_next_line(fd);
	printf("%s", line);
	
	free(line);
	close(fd);
	return (0);
}
