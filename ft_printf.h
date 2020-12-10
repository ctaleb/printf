/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:22:07 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/10 13:58:01 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_printdb
{
		int		len;
		char	*str;

		int		nb_conv;
		char	**c_type;
		int		*f_len;
		char	**f_type;
}				t_printdb;

int				ft_printf(const char *toprint, ...);

int				parser(const char *toprint, t_printdb printdb);

int				printer(char *str);

#endif
