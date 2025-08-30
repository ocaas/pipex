/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 03:54:07 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/27 03:54:07 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	c;
	size_t	l;
	char	*xx;

	xx = (char *)big;
	c = 0;
	if (small[0] == '\0')
		return (xx);
	while (xx[c] != '\0' && c < len)
	{
		l = 0;
		while (xx[c + l] == small[l] && (c + l) < len && small[l] != '\0')
		{
			l++;
		}
		if (small[l] == '\0')
			return (&xx[c]);
		c++;
	}
	return (NULL);
}

/* int main(int ac, char **av)
{
    if (ac != 4)
    {
        printf("Usage: %s <big string> <small string> <length>\n", av[0]);
        return 1;
    }

    char *res = ft_strnstr(av[1], av[2], atoi(av[3]));
    if (res)
        printf("Result: %s\n", res);
    else
        printf("Substring not found within the first %d characters.\n",
		 atoi(av[3]));

    return 0;
} */
/* 
int main(void)
{
    char *big = "Hello, this is a test";
    char *small = "test";
    size_t len = 4;

    // Uso de la función
    char *result = ft_strnstr(big, small, len);

    // Mostrar el resultado
    if (result)
        printf("Encontrado: %s\n", result);
    else
        printf("No encontrado\n");

    return 0;
} */