/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:00:23 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/20 21:00:23 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*help;
	size_t			c;

	c = 0;
	help = s;
	while (c < n)
	{
		help[c] = '\0';
		c++;
	}
}
/* int main()
{
    char buffer[10] = "kysdie";
    printf("blablabla: %s\n", buffer);

    bzero(buffer, 5);

    printf("aaaaaaaa: %s\n", buffer);
    return 0;
} */
