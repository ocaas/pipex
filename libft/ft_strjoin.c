/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:11:32 by olopez-s          #+#    #+#             */
/*   Updated: 2024/10/01 08:11:32 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	c1;
	size_t	c2;
	char	*f;

	f = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!f)
		return (NULL);
	c1 = 0;
	c2 = 0;
	while (s1[c1] != '\0')
	{
		f[c1] = s1[c1];
		c1++;
	}
	while (s2[c2] != '\0')
	{
		f[c1 + c2] = s2[c2];
		c2++;
	}
	f[c1 + c2] = '\0';
	return (f);
}
/* 
int	main(void)
{
	char *s = "hola,";
	char *h = "mundo";
	char *d = ft_strjoin(s, h);
	printf("%s\n", d);
}
 */