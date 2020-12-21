/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cconverter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:31:25 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 12:06:55 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	perconv(t_print *print, t_parg *parg)
{
	char	c;
	char	cwidth;

	c = '%';
	cwidth = ' ';
	if (parg->fzero && !parg->fminus && parg->fwid >= 0)
		cwidth = '0';
	perprinter(print, parg, c, cwidth);
}

void	cconv(t_print *print, t_parg *parg, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	cprinter(print, parg, c);
}

void	sconv(t_print *print, t_parg *parg, va_list args)
{
	char	*str;
	int		len;

	str = (char *)va_arg(args, char *);
	free(parg->conv);
	if (str == NULL)
	{
		if (parg->fdot && parg->fprec >= 0)
			len = parg->fprec + 1;
		else
			len = 7;
		parg->conv = ft_calloc(len, sizeof(char));
		ft_strlcpy(parg->conv, "(null)", len);
	}
	else
	{
		if (parg->fdot && parg->fprec < (int)ft_strlen(str) && parg->fprec >= 0)
			len = parg->fprec + 1;
		else
			len = ft_strlen(str) + 1;
		parg->conv = ft_calloc(len, sizeof(char));
		ft_strlcpy(parg->conv, str, len);
	}
	sprinter(print, parg);
}
