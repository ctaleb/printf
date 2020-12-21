/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_extractor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:48:43 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 15:12:06 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			idextract(t_parg *parg, va_list args)
{
	long long	nb;

	nb = 0;
	if (parg->mh == 1)
		nb = (short)va_arg(args, int);
	else if (parg->mh >= 2)
		nb = (signed char)va_arg(args, int);
	else if (parg->ml == 1)
		nb = (long)va_arg(args, int);
	else if (parg->ml >= 2)
		nb = (long long)va_arg(args, int);
	else
		nb = (int)va_arg(args, int);
	return (nb);
}

unsigned long long	uxtract(t_parg *parg, va_list args)
{
	unsigned long long	nb;

	nb = 0;
	if (parg->mh == 1)
		nb = (unsigned short)va_arg(args, int);
	else if (parg->mh >= 2)
		nb = (unsigned char)va_arg(args, int);
	else if (parg->ml == 1)
		nb = (unsigned long)va_arg(args, int);
	else if (parg->ml >= 2)
		nb = (unsigned long long)va_arg(args, int);
	else
		nb = (unsigned int)va_arg(args, int);
	return (nb);
}
