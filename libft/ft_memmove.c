/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 03:42:00 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/23 03:42:00 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	len;

	len = 0;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
			len ++;
		}
	}
	return (dst);
}
/* 

void ft_memmove(void *s1, const void *s2, size_t n);

int main(void)
{
    char src[50] = "Hello, this is a memmove test!";
    char dest[50];

    printf("Antes de ft_memmove:\n");
    printf("Source: %s\n", src);
    printf("Dest: %s\n\n", dest);

    ft_memmove(dest, src, 20);

    printf("Después de ft_memmove:\n");
    printf("Source: %s\n", src);
    printf("Dest: %s\n", dest);

    printf("\n--- Ejemplo con solapamiento ---\n");

    ft_memmove(src + 7, src, 10);
    printf("Source después de solapamiento: %s\n", src);

    return 0;
} */
