/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:24:23 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/21 16:24:23 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	c;

	len = ft_strlen(src);
	c = 0;
	if (src != NULL && dst != NULL && size > 0)
	{
		while (c < len && c < (size - 1))
		{
			dst[c] = src[c];
			c++;
		}
		dst[c] = '\0';
	}
	return (len);
}
/* 
int	main(void)
{
	char dst[] = "asdfjasjdflkjasdkfjkasjdf";
	ft_strlcpy(dst, "bbb", 3);
	printf("%s\n", dst);
	return(0);
} */
