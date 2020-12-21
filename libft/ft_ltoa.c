/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:43:48 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 13:04:45 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbrlen(long long nb)
{
	unsigned int	size;

	size = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb != 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char				*ft_ltoa(long long n)
{
	unsigned int	size;
	char			*nbr;
	long long		nb;

	size = ft_nbrlen(n);
	if (!(nbr = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	nb = n;
	if (nb < 0)
	{
		nbr[0] = '-';
		nb *= -1;
	}
	size--;
	if (nb == 0)
		nbr[size] = 48;
	while (nb != 0)
	{
		nbr[size] = nb % 10 + 48;
		nb /= 10;
		size--;
	}
	return (nbr);
}
