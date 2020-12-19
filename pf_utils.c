/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:36:40 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/19 11:52:42 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_count(const char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			while (str[i] && !isconv(str[i]))
				i++;
			i++;
			c++;
		}
		i++;
	}
	return (c);
}

static void	free_print(t_print *print)
{
	if (print->basestr)
		free(print->basestr);
	free(print);
}

static void	free_parg(int ccount, t_parg **parg)
{
	int i;

	i = 0;
	while (i < ccount)
	{
		if (parg[i]->conv)
			free(parg[i]->conv);
		free(parg[i]);
		i++;
	}
	free(parg);
}

void	pf_free_all(t_print *print, t_parg **parg)
{
	free_parg(print->nb_conv, parg);
	free_print(print);
}
