/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:37 by flopez-r          #+#    #+#             */
/*   Updated: 2023/10/14 17:58:49 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if(!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] != (unsigned char)c)
		return (0);
	return ((char *)&s[i]);
}

/* int   ft_strchr(const char *s, int c)
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
} */

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		size_s1;
// 	int		size_s2;
// 	char	*str;
// 	int		i;
// 	int		j;


// 	while (s1 && s1[size_s1] != '\0')
// 		size_s1++;
// 	while (s2 && s2[size_s2] != '\0')
// 		size_s2++;
// 	size_s2 = ft_strlen(s2);
// 	str = malloc(size_s1 + size_s2 + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (i < size_s1)
// 		str[i++] = s1[j++];
// 	j = 0;
// 	while (j < size_s2)
// 		str[i++] = s2[j++];
// 	str[i] = '\0';
// 	return (str);
// }

size_t	ft_strlen(const char *s)
{
	int	i;

	if(!s)
		return (0);
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
