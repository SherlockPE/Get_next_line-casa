/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:02:20 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/09 09:36:49 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int		file_descriptor;
	char	*archive;
	char	*path = "prueba.txt";

	file_descriptor = open(path, O_RDONLY);
	archive = get_next_line(file_descriptor);
	
	if (archive == -1)
		return (0);
	


	printf("%s\n", archive);
	return 0;
}
