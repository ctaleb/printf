/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memconverter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:32:37 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/19 16:54:16 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nconv(int len, t_parg *parg, va_list args)
{
	int			*n;
	short		*s;
	signed char	*c;

	if (parg->mh == 1)
	{
		s = (short *)va_arg(args, int *);
		*s = len;
	}
	else if (parg->mh >= 2)
	{
		c = (signed char *) va_arg(args, int *);
		*c = len;
	}
	else
	{
		n = (int *)va_arg(args, int *);
		*n = len;
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
