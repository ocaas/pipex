/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:34:09 by olopez-s          #+#    #+#             */
/*   Updated: 2024/10/01 23:34:09 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		f;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	f = ft_strlen(s1) - 1;
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
	{
		i++;
	}
	while (ft_strchr(set, s1[f]) && s1[i])
	{
		f--;
	}
	str = ft_substr(s1, i, f + 1 - i);
	return (str);
}
/* 
int main(void)
{
    char s1[] = "   hello world   ";
    char set[] = " ";
    char *trimmed_str;

    trimmed_str = ft_strtrim(s1, set);
    if (trimmed_str)
        printf("Trimmed string: '%s'\n", trimmed_str);
    else
        printf("Error: NULL string\n");

    // Free the allocated memory
    free(trimmed_str);

    return 0;
}
 */