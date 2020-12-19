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
	free(parg->conv);
	parg->conv = ft_calloc(1, sizeof(char));
	if (c != 0)
		cjoiner(&parg->conv, c, 1);
	adjwidth(parg);
	printer(parg->conv, 1);
	print->len += (int)ft_strlen(parg->conv);
}

void	sconv(t_print *print, t_parg *parg, va_list args)
{
	char	*str;

	str = (char *)va_arg(args, char *);
	free(parg->conv);
	parg->conv  = ft_calloc(1, sizeof(char));
	if (ft_strlen(str) != 0)
		sjoiner(&parg->conv, str, 1);
	adjwidth(parg);
	printer(parg->conv, 1);
	print->len += (int)ft_strlen(parg->conv);
}
