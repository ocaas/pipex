/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:43:18 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/25 00:43:18 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *c1, const char *c2, size_t n)
{
	unsigned int	c;

	c = 0;
	while (n && (*c1 || *c2))
	{
		if (*c1 != *c2)
		{
			c = ((unsigned char)c1[c] - (unsigned char)c2[c]);
			return (c);
		}
		c1++;
		c2++;
		n--;
	}
	return (0);
}

/* int main(void)
{
    printf("Comparando 'Hola' y 'Hola' (n = 4): %d\n",
	 ft_strncmp("Hola", "Hola", 4));  // Esperado: 0
    printf("Comparando 'Hola' y 'Holb' (n = 4): %d\n",
	 ft_strncmp("Hola", "Holb", 4));  // Esperado: Diferente
	  (positivo o negativo)
    printf("Comparando 'Hola' y 'Hol' (n = 4): %d\n",
	 ft_strncmp("Hola", "Hol", 4));   // Esperado: Diferente (positivo)
    printf("Comparando 'Hola' y 'Hol' (n = 3): %d\n",
	 ft_strncmp("Hola", "Hol", 3));   // Esperado: 0

    return 0;
} */
