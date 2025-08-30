/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 01:45:20 by olopez-s          #+#    #+#             */
/*   Updated: 2024/10/05 01:45:20 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*strn;

	i = 0;
	if (!s || !f)
		return (NULL);
	strn = malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!strn)
		return (NULL);
	while (s[i] != '\0')
	{
		strn[i] = f(i, s[i]);
		i++;
	}
	strn[i] = '\0';
	return (strn);
}
/* 
static char ft_touppermapi(unsigned int i, char c);

static char ft_touppermapi(unsigned int i, char c) 
{
    (void)i; // Ignoramos el índice en este caso
    if (c >= 'a' && c <= 'z') {
        return c - 32; // Convertir a mayúsculas
    }
    return c; // Devolver el carácter sin cambios si no es minúscula
} */

/* 
int main(void) 
{
    char str[] = "hello world";
    char *result;

    result = ft_strmapi(str, ft_touppermapi);
    if (result) {
        printf("Original: %s\n", str);
        printf("Modificado: %s\n", result);
        free(result); // Libera la memoria asignada
    }
    return 0;
} */