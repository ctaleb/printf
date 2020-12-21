/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:19:37 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 11:18:56 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *toprint, ...)
{
	int				len;
	va_list			args;
	t_print			*print;
	t_parg			**parg;

	print = print_init(toprint);
	parg = parg_init(print->nb_conv);
	va_start(args, toprint);
	parser(print, parg, args);
	len = print->len;
	pf_free_all(print, parg);
	va_end(args);
	return (len);
}
