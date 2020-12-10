/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:45:37 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/10 14:36:45 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	struct_init(t_printdb printdb)
{
	printdb.len = 0;
	printdb.str = NULL;
	printdb.nb_conv = 0;
	printdb.c_type = NULL;
	printdb.f_len = 0;
	printdb.f_type = NULL;
}

int			ft_printf(const char *toprint, ...)
{
	int					i;
	va_list				args;
	static	t_printdb	printdb;

	struct_init(printdb);
	va_start(args, toprint);
	parser(toprint, printdb);
	//printer(printdb.str);
	printf("convs = %i\n", printdb.nb_conv);
	return (0);
}
