/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 07:19:59 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/30 07:19:59 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (len--)
	{
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
/* 
int main(void)
{
    char *sub = ft_substr("Hello World im Olivia, student of 42", 15, 21); 
	 // Extract "world" from "Hello, world!"

    if (sub != NULL)
    {
        printf("Substring: %s\n", sub);
        free(sub);
    }
    else
    {
        printf("Invalid substring operation.\n");
    }
    return 0;
} */
