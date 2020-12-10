/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:04:11 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/10 14:31:44 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	isconv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	conv_extract(const char *str, t_printdb printdb)
{
	int i;

	i = 1;
	if (str[i] == '-' || str[i] == '.' || str[i] == '0')
	{
		printdb.f_type[printdb.nb_conv][0] = str[i];
		i++;
	}
	while (ft_isnum(str[i]))
	{
		if (printdb.f_type[printdb.nb_conv][0])
			printdb.f_type[printdb.nb_conv][0] = '1';
		printdb.f_len[printdb.nb_conv] =
			printdb.f_len[printdb.nb_conv] * 10 + str[i] - 48;
		i++;
	}
	while (!isconv(str[i]))
		i++;
	printdb.c_type[printdb.nb_conv][0] = str[i];
	printdb.nb_conv++;
	return (i);
}

static void	conv_check(const char *toprint, t_printdb printdb)
{
	int i;

	i = 0;
	while (toprint[i])
	{
		if (toprint[i] == '%')
			i = conv_extract(&toprint[i], printdb);
		i++;
	}

}

int			parser(const char *toprint, t_printdb printdb)
{
	conv_check(toprint, printdb);
	return (printdb.nb_conv);
}
