/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:04:27 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 16:53:34 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_extract(const char *str, t_parg *parg, va_list args)
{
	int	i;

	i = 1;
	while (isflag(str[i]))
		fassign(str[i++], parg);
	parg->fwid = iassign(&str[i], args);
	while (isnum(str[i]))
		i++;
	if (str[i] == '.')
	{
		parg->fdot = 1;
		i++;
		parg->fprec = iassign(&str[i], args);
		while (isnum(str[i]))
			i++;
	}
	while (ismod(str[i]))
		massign(str[i++], parg);
	if (str[i] && isconv(str[i]))
		parg->ctype = str[i];
	return (i);
}

static void	conv_varg(t_print *print, t_parg *parg, va_list args)
{
	if (parg->ctype == 'c')
		cconv(print, parg, args);
	else if (parg->ctype == 's')
		sconv(print, parg, args);
	else if (parg->ctype == 'p')
		pconv(print, parg, args);
	else if (parg->ctype == 'd' || parg->ctype == 'i')
		idconv(print, parg, args);
	else if (parg->ctype == 'u')
		uconv(print, parg, args);
	else if (parg->ctype == 'x' || parg->ctype == 'X')
		hexconv(print, parg, args);
	else if (parg->ctype == 'n')
		nconv(print->len, parg, args);
	else if (parg->ctype == '%')
		perconv(print, parg);
	else
		return ;
}

int			parser(t_print *print, t_parg **parg, va_list args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (print->basestr[i])
	{
		if (print->basestr[i] == '%')
		{
			i += conv_extract(&print->basestr[i], parg[j], args);
			conv_varg(print, parg[j], args);
			j++;
		}
		else
		{
			ft_putchar_fd(print->basestr[i], 1);
			print->len += 1;
		}
		i++;
	}
	return (0);
}
