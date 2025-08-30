/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 04:12:14 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/29 04:12:14 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	b;
	void	*p;

	b = count * size;
	p = malloc(b);
	if (p == NULL)
	{
		return (NULL);
	}
	else
	{
		ft_bzero(p, b);
	}
	return (p);
}

/* 
int main(void)
{
    int *arr = (int *)ft_calloc(5, sizeof(int));

    if (arr == NULL)
    {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Mostrar los valores iniciales (deberían ser 0)
    for (int i = 0; i < 5; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    free(arr); // Liberar la memoria asignada
    return 0;
}
 */