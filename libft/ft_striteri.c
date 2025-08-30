/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 06:03:02 by olopez-s          #+#    #+#             */
/*   Updated: 2024/10/09 06:03:02 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* 
void ft_touppermapi(unsigned int i, char *c)
{
    (void)i;  // No necesitamos usar 'i' en este caso
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;  // Convertir a mayúscula
}

int main(void)
{
    char str[] = "hello world!";
    
    ft_striteri(str, ft_touppermapi);

    // Imprimimos el resultado
    printf("Resultado: %s\n", str);

    return 0;
} */