/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:14:25 by olopez-s          #+#    #+#             */
/*   Updated: 2024/09/26 00:14:25 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	c;
	int		sign;
	int		res;

	c = 0;
	sign = 1;
	res = 0;
	while (nptr[c] == ' ' || (nptr[c] >= 9 && nptr[c] <= 13))
		c++;
	if (nptr[c] == '+' || nptr[c] == '-')
	{
		if (nptr[c] == '-')
			sign = -1;
		c++;
	}
	while (nptr[c] >= 48 && nptr[c] <= 57)
	{
		res = res * 10 + (nptr[c] - 48);
		c++;
	}
	return (res * sign);
}
/* 
int	main(void)
{
	printf("%d\n", ft_atoi(" 983478438+548+3"));
	return(0);
}
 */
