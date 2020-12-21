/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_iconverter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:25:14 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 12:43:42 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	idconv(t_print *print, t_parg *parg, va_list args)
{
	long long	nb;

	nb = idextract(parg, args);
	free(parg->conv);
	if (parg->ml)
		parg->conv = ft_ltoa(nb);
	else
		parg->conv = ft_itoa(nb);
	if (parg->fdot)
		adjprec(parg);
	if (nb >= 0)
		adjsign(parg);
	adjwidth(parg);
	printer(parg->conv, ft_strlen(parg->conv));
	print->len += (int)ft_strlen(parg->conv);
}

void	uconv(t_print *print, t_parg *parg, va_list args)
{
	unsigned long long nb;

	nb = uxtract(parg, args);
	free(parg->conv);
	if (parg->ml)
		parg->conv = ft_lutoa(nb);
	else
		parg->conv = ft_utoa(nb);
	if (parg->fdot)
		adjprec(parg);
	adjsign(parg);
	adjwidth(parg);
	printer(parg->conv, ft_strlen(parg->conv));
	print->len += (int)ft_strlen(parg->conv);
}

void	hexconv(t_print *print, t_parg *parg, va_list args)
{
	unsigned long long int	nb;

	nb = uxtract(parg, args);
	free(parg->conv);
	if (parg->ctype == 'x')
		parg->conv = ft_utoa_base(nb, "0123456789abcdef");
	else
		parg->conv = ft_utoa_base(nb, "0123456789ABCDEF");
	if (parg->fdot)
		adjprec(parg);
	if (nb > 0)
		adjsign(parg);
	if (parg->fhtag && nb)
		adjwsize(parg);
	adjwidth(parg);
	if (parg->fhtag && nb)
		adjhtag(parg);
	printer(parg->conv, ft_strlen(parg->conv));
	print->len += (int)ft_strlen(parg->conv);
}
