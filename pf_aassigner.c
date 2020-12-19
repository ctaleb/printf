/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_aassigner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:20:50 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/19 11:20:58 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		iassign(const char *str, va_list args)
{
	int i;
	int nb;

	i = 0;
	if (isnum(str[i]) == 2)
		return (va_arg(args, int));
	else
	{
		nb = 0;
		while (isnum(str[i]) == 1)
		{
			nb = nb * 10 + str[i] - 48;
			i++;
		}
		return (nb);
	}
	return (0);
}

void	fassign(char c, t_parg *parg)
{
	if (c == '0')
		parg->fzero = 1;
	else if (c == '-')
		parg->fminus = 1;
	else if (c == '+')
		parg->fplus = 1;
	else if (c == ' ')
		parg->fspace = 1;
	else if (c == '#')
		parg->fhtag = 1;
	else if (c == '\'')
		parg->fquote = 1;
}

void	massign(char c, t_parg *parg)
{
	if (c == 'l')
		parg->ml += 1;
	else if (c == 'h')
		parg->mh += 1;
}
