/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:35:58 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 17:38:22 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printer(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	perprinter(t_print *print, t_parg *parg, char c, char cw)
{
	char	*width;
	int		adj;

	if ((adj = ft_abs(parg->fwid) - 1) > 0)
	{
		width = ft_calloc(adj + 1, sizeof(char));
		memset(width, cw, adj);
		if (parg->fminus || parg->fwid < 0)
		{
			ft_putchar_fd(c, 1);
			printer(width, adj);
		}
		else if (parg->fwid)
		{
			printer(width, adj);
			ft_putchar_fd(c, 1);
		}
		free(width);
		print->len += adj + 1;
	}
	else
	{
		ft_putchar_fd(c, 1);
		print->len += 1;
	}
}

void	cprinter(t_print *print, t_parg *parg, char c, char fc)
{
	char	*width;
	int		adj;

	if ((adj = ft_abs(parg->fwid) - 1) > 0)
	{
		width = ft_calloc(adj + 1, sizeof(char));
		memset(width, fc, adj);
		if (parg->fminus || parg->fwid < 0)
		{
			ft_putchar_fd(c, 1);
			printer(width, adj);
		}
		else if (parg->fwid)
		{
			printer(width, adj);
			ft_putchar_fd(c, 1);
		}
		free(width);
		print->len += adj + 1;
	}
	else
	{
		ft_putchar_fd(c, 1);
		print->len += 1;
	}
}

void	sprinter(t_print *print, t_parg *parg)
{
	char	*width;
	int		adj;

	if ((adj = ft_abs(parg->fwid) - ft_strlen(parg->conv)) > 0)
	{
		width = ft_calloc(adj + 1, sizeof(char));
		memset(width, ' ', adj);
		if (parg->fminus || parg->fwid < 0)
		{
			ft_putstr_fd(parg->conv, 1);
			printer(width, adj);
		}
		else if (parg->fwid)
		{
			printer(width, adj);
			ft_putstr_fd(parg->conv, 1);
		}
		free(width);
		print->len += adj + ft_strlen(parg->conv);
	}
	else
	{
		ft_putstr_fd(parg->conv, 1);
		print->len += ft_strlen(parg->conv);
	}
}
