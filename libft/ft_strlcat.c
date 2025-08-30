/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:48:31 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/23 00:48:31 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;

	d = 0;
	s = 0;
	while (dst[d] && d < size)
		d++;
	while (src[s] && (d + s + 1) < size)
	{
		dst[d + s] = src[s];
		s++;
	}
	if (d < size)
		dst[d + s] = '\0';
	return (d + ft_strlen(src));
}
/* 
int	main(void)
{
	char    dst[100] = "Hello, ";
    ft_strlcat(dst, "World!", 100);
    printf("%s\n", dst);
    return (0);
} */