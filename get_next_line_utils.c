/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:37 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/13 21:13:41 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   ft_strchr(const char *s, int c)
{
    int    i;

    i = 0;
    while (s[i])
    {
        if (s[i] == (unsigned char)c)
            return (i);
        i++;
    }
    if (s[i] != (unsigned char)c)
        return (0);
    return (i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b2;

	b2 = (unsigned char *)b;
	i = 0;
	while (i < len)
		b2[i++] = c;
	return (b2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_string;
	size_t		i;

	if (s == 0)
		return (0);
	i = ft_strlen(s);
	if (start >= i)
	{
		new_string = ft_calloc(1, 1);
		return (new_string);
	}
	else if (i - start < len)
		new_string = ft_calloc((i - start) + 1, 1);
	else
		new_string = ft_calloc(len + 1, 1);
	if (new_string == 0)
		return (0);
	i = 0;
	while (i < len && s[start])
		new_string[i++] = s[start++];
	return (new_string);
}
