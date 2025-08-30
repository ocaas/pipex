/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:32:26 by olopez-s          #+#    #+#             */
/*   Updated: 2024/10/09 08:32:26 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = 11;
		return (i);
	}
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*minnum(int nb, char *p, int aux)
{
	nb *= -1;
	nb = nb - 1;
	if (nb == 2147483647)
	{
		p[aux--] = (nb % 10) + 49;
		nb = nb / 10;
	}
	while (nb > 0)
	{
		p[aux--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		aux;
	int		nb;

	nb = n;
	aux = len(n);
	p = malloc((aux + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p[aux--] = '\0';
	if (!nb)
		p[0] = '0';
	if (nb == -2147483648)
		minnum(nb, p, aux);
	if (nb < 0)
	{
		nb *= -1;
		p[0] = '-';
	}
	while (nb > 0)
	{
		p[aux--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (p);
}

/*
static	unsigned int	ft_sizeofnum(int n)
{
	int	a;

	a = 0;
	if (n < 0)
	{
		n = -n;
		n++;
	}
	if (n == -2147483648)
	{
		a = 11;
		return (a);
	}
	if (n == 0)
		a++;
	while (n > 0)
	{
		n = n / 10;
		a++;
	}
	return (a);
}

char	*minmun(int nb, char *str, int res)
{
	nb *= -1;
	nb = nb - 1;
	if (nb == 2147483647)
	{
		nbr[res--] = (nb % 10) + 49;
		nb = nb / 10;
	}
	while (nb > 0)
	{
		str[res--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		res;
	int		nb;

	nb = n;
	res = ft_sizeofnum(n);
	str = malloc((res + 1) * sizeof(char));
	if (!p)
		return (NULL);
	str[res--] = '\0';
	if (!nb)
		str[0] = '0';
	if (nb == -2147483648)
		minmun(nb, str, res);
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[res--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
*/