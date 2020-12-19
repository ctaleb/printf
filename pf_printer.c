/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:35:58 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/19 16:26:33 by ctaleb           ###   ########lyon.fr   */
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

void	cprinter(t_print *print, t_parg *parg, char c)
{
	char	*width;
	int		adj;

	if ((adj = ft_abs(parg->fwidth) - 1) > 0)
	{
		width = ft_calloc(adj + 1, sizeof(char));
		memset(width, ' ', adj);
		if (parg->fminus || parg->fwidth < 0)
		{
			ft_putchar_fd(c, 1);
			printer(width, adj);
		}
		else if (parg->fwidth)
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

	if ((adj = ft_abs(parg->fwidth) - ft_strlen(parg->conv)) > 0)
	{
		width = ft_calloc(adj + 1, sizeof(char));
		memset(width, ' ', adj);
		if (parg->fminus || parg->fwidth < 0)
		{
			ft_putstr_fd(parg->conv, 1);
			printer(width, adj);
		}
		else if (parg->fwidth)
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
