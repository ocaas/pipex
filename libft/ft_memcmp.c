/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 05:12:09 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/26 05:12:09 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			c;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	c = 0;
	while (c < n)
	{
		if (c1[c] != c2[c])
		{
			return ((c1[c]) - (c2[c]));
		}
		if (!c1 && !c2)
			return (0);
		c++;
	}
	return (0);
}
/* 
int main(void)
{
	char	s1[]="qwertyuioqi";
	char	s2[]="qwertyuioqp";

	printf("I did wierd shit... %d\n", ft_memcmp(s1, s2, 10));
} */
