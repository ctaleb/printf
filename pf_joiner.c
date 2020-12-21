/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_joiner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:02:05 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 11:24:30 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sjoiner(char **s1, char *s2, int m)
{
	char	*temp;

	temp = NULL;
	if (m == 1)
		temp = ft_strjoin(*s1, s2);
	else if (m == 2)
		temp = ft_strjoin(s2, *s1);
	if (*s1)
		free(*s1);
	*s1 = temp;
}

void	cjoiner(char **s1, char c, int m)
{
	char	*temp;

	temp = NULL;
	if (m == 1)
		temp = ft_chrjoin(*s1, c);
	else if (m == 2)
		temp = ft_chrrjoin(*s1, c);
	if (*s1)
		free(*s1);
	*s1 = temp;
}

void	njoiner(char **s1, char *s2)
{
	char	*tempa;
	char	*tempb;
	int		i;

	i = 0;
	while ((*s1)[i] == ' ' || (*s1)[i] == '+' || (*s1)[i] == '-')
		i++;
	tempa = ft_substr(*s1, i, ft_strlen(*s1) - i);
	tempb = ft_strjoin(s2, tempa);
	free(tempa);
	tempa = NULL;
	tempa = ft_substr(*s1, 0, i);
	if (*s1)
		free(*s1);
	*s1 = ft_strjoin(tempa, tempb);
	free(tempa);
	free(tempb);
}
