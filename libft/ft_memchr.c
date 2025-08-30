/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 03:16:22 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/26 03:16:22 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	rec;

	rec = 0;
	str = (char *)s;
	while (rec < n)
	{
		if ((unsigned char)str[rec] == (unsigned char)c)
			return ((char *)s + rec);
		rec++;
	}
	return (NULL);
}

/* int main(void)
{
    char str[] = "Hola mundo!";
    char *result;

    result = ft_memchr(str, 'm', 8);

    if (result)
        printf("Character found: '%c' in position : %ld\n", *result,
		 result - str);
    else
        printf("Charecter not found in the first 8 places. \n");

    return 0;
} */