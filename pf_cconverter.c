/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cconverter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:31:25 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/19 16:49:06 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	perconv(t_print *print)
{
	char c;

	c = '%';
	ft_putchar_fd(c, 1);
	print->len += 1;
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
		if ((parg->fdot && parg->fprec >= 6) || !parg->fdot)
			len = 7;
		else
			len = 1;
		parg->conv = ft_calloc(len, sizeof(char));
		if (parg->fprec >= 6 || !parg->fdot)
			ft_strlcpy(parg->conv, "(null)", len);		
	}
	else
	{
		if (parg->fdot && parg->fprec < (int)ft_strlen(str))
			len = parg->fprec + 1;
		else
			len = ft_strlen(str) + 1;
		parg->conv = ft_calloc(len, sizeof(char));
		ft_strlcpy(parg->conv, str, len);
	}
	sprinter(print, parg);
}
