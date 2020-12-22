/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memconverter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:32:37 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/22 11:26:40 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nconv(int len, t_parg *parg, va_list args)
{
	int			*n;

	if (parg->mh || parg->ml)
	{
		nmodconv(len, parg, args);
	}
	else
	{
		n = (int *)va_arg(args, int *);
		(n == NULL) ? (len += 0) : (*n = len);
	}
}

void	nmodconv(int len, t_parg *parg, va_list args)
{
	short		*s;
	signed char	*c;
	long		*l;
	long long	*ll;

	if (parg->mh == 1)
	{
		s = (short *)va_arg(args, int *);
		(s == NULL) ? (len += 0) : (*s = len);
	}
	else if (parg->mh >= 2)
	{
		c = (signed char *)va_arg(args, int *);
		(c == NULL) ? (len += 0) : (*c = len);
	}
	else if (parg->ml == 1)
	{
		l = (long *)va_arg(args, int *);
		(l == NULL) ? (len += 0) : (*l = len);
	}
	else if (parg->ml >= 2)
	{
		ll = (long long *)va_arg(args, int *);
		(ll == NULL) ? (len += 0) : (*ll = len);
	}
}

void	pconv(t_print *print, t_parg *parg, va_list args)
{
	unsigned long long int nb;

	nb = (unsigned long long int)va_arg(args, void *);
	free(parg->conv);
	parg->conv = ft_utoa_base(nb, "0123456789abcdef");
	adjprec(parg);
	adjhtag(parg);
	adjwidth(parg);
	printer(parg->conv, ft_strlen(parg->conv));
	print->len += (int)ft_strlen(parg->conv);
}
