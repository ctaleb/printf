/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:57:16 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/22 14:42:49 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print			*print_init(const char *str)
{
	t_print print;
	t_print	*p_print;

	p_print = &print;
	if (!(p_print = ft_calloc(1, sizeof(t_print))))
		return (NULL);
	p_print->nb_conv = c_count(str);
	p_print->basestr = ft_strdup(str);
	return (p_print);
}

t_parg			**parg_init(int ccount)
{
	int		i;
	t_parg	*parg;
	t_parg	**p_parg;

	p_parg = &parg;
	if (!(p_parg = ft_calloc(ccount, sizeof(t_parg))))
		return (NULL);
	i = 0;
	while (i < ccount)
	{
		if (!(p_parg[i] = ft_calloc(1, sizeof(t_parg))))
			return (NULL);
		p_parg[i]->conv = NULL;
		i++;
	}
	return (p_parg);
}
