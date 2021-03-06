/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_adjuster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:21:38 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 11:35:41 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	adjsign(t_parg *parg)
{
	if (parg->fplus)
		cjoiner(&parg->conv, '+', 2);
	else if (parg->fspace)
		cjoiner(&parg->conv, ' ', 2);
}

void	adjwidth(t_parg *parg)
{
	char	*width;
	int		adj;
	int		m;

	if (parg->fprec < 0)
	{
		parg->fprec = 0;
		parg->fdot = 0;
	}
	if ((adj = ft_abs(parg->fwid) - (int)ft_strlen(parg->conv)) > 0)
	{
		width = ft_calloc(adj + 1, sizeof(char));
		memset(width, ' ', adj);
		m = (parg->fwid >= 0) ? (2) : (1);
		if (parg->fminus)
			sjoiner(&parg->conv, width, 1);
		else if (parg->fzero && parg->fwid >= 0 && !parg->fprec && !parg->fdot)
		{
			memset(width, '0', adj);
			njoiner(&parg->conv, width);
		}
		else if (parg->fwid)
			sjoiner(&parg->conv, width, m);
		free(width);
	}
}

void	adjprec(t_parg *parg)
{
	char	*prec;
	int		adj;

	if (parg->fprec == 0)
	{
		if (ft_strlen(parg->conv) == 1 && parg->conv[0] == '0'
				&& parg->ctype != 'p')
		{
			free(parg->conv);
			parg->conv = ft_calloc(1, sizeof(char));
		}
		return ;
	}
	else if ((adj = parg->fprec - (int)ft_numlen(parg->conv)) > 0)
	{
		prec = ft_calloc(adj + 1, sizeof(char));
		memset(prec, '0', adj);
		njoiner(&parg->conv, prec);
		free(prec);
	}
}

void	adjhtag(t_parg *parg)
{
	char	*htag;
	int		adj;

	if (parg->ctype == 'x')
		njoiner(&parg->conv, "0x");
	else if (parg->ctype == 'X')
		njoiner(&parg->conv, "0X");
	else
	{
		adj = (int)ft_strlen(parg->conv) + 3;
		htag = ft_calloc(adj, sizeof(char));
		htag[0] += '0';
		htag[1] += 'x';
		ft_strlcat(htag, parg->conv, adj);
		if (parg->ctype == 'X')
			htag[1] -= ' ';
		free(parg->conv);
		parg->conv = htag;
	}
}

void	adjwsize(t_parg *parg)
{
	if (parg->fwid >= 2)
		parg->fwid -= 2;
	else if (parg->fwid <= -2)
		parg->fwid += 2;
	if (parg->fwid < 2 && parg->fwid > -2)
		parg->fwid = 0;
}
