/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:22:57 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/19 11:23:50 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '*')
		return (2);
	return (0);
}

int	ismod(char c)
{
	int		i;
	char	*m_list;

	i = 0;
	m_list = "hl";
	while (m_list[i])
	{
		if (c == m_list[i])
			return (1);
		i++;
	}
	return (0);
}

int	isconv(char c)
{
	int		i;
	char	*c_list;

	i = 0;
	c_list = "pcsudixXn%";
	while (c_list[i])
	{
		if (c == c_list[i])
			return (1);
		i++;
	}
	return (0);
}

int	isflag(char c)
{
	int		i;
	char	*f_list;

	i = 0;
	f_list = "0-+ #'";
	while (f_list[i])
	{
		if (c == f_list[i])
			return (1);
		i++;
	}
	return (0);
}
