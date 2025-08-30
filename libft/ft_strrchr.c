/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 03:07:37 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/24 03:07:37 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = ft_strlen(s);
	if (c >= 256)
		c = c % 256;
	while (a >= 0)
	{
		if (s[a] == c)
			return ((char *)&s[a]);
		a--;
	}
	return (NULL);
}

/* int	main(void)
{
	char *str = "Hello, World!";
    char *res;

    res = ft_strrchr(str, 'l');
    printf("%s\n", res);

    return (0);
} */