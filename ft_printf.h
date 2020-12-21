/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:38:38 by ctaleb            #+#    #+#             */
/*   Updated: 2020/12/21 17:47:45 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_print
{
	int				len;
	char			*basestr;
	int				nb_conv;
}					t_print;

typedef struct		s_parg
{
	char			ctype;
	char			*conv;
	int				fhtag;
	int				fzero;
	int				fminus;
	int				fplus;
	int				fspace;
	int				fquote;
	int				fwid;
	int				fdot;
	int				fprec;
	int				mh;
	int				ml;
}					t_parg;

int					ft_printf(const char *toprint,
					...) __attribute__((format(printf,1,2)));
t_print				*print_init(const char *str);
t_parg				**parg_init(int ccount);

int					parser(t_print *print, t_parg **parg, va_list args);
int					c_count(const char *str);

int					isflag(char c);
int					isconv(char c);
int					ismod(char c);
int					isnum(char c);

int					iassign(const char *str, va_list args);
void				fassign(char c, t_parg *parg);
void				massign(char c, t_parg *parg);

long long			idextract(t_parg *parg, va_list args);
unsigned long long	uxtract(t_parg *parg, va_list args);

void				perconv(t_print *print, t_parg *parg);
void				cconv(t_print *print, t_parg *parg, va_list args);
void				nconv(int len, t_parg *parg, va_list args);
void				nmodconv(int len, t_parg *parg, va_list args);
void				idconv(t_print *print, t_parg *parg, va_list args);
void				uconv(t_print *print, t_parg *parg, va_list args);
void				hexconv(t_print *print, t_parg *parg, va_list args);
void				pconv(t_print *print, t_parg *parg, va_list args);
void				sconv(t_print *print, t_parg *parg, va_list args);

void				adjsign(t_parg *parg);
void				adjwidth(t_parg *parg);
void				adjprec(t_parg *parg);
void				adjhtag(t_parg *parg);
void				adjwsize(t_parg *parg);

void				sjoiner(char **s1, char *s2, int m);
void				cjoiner(char **s1, char c, int m);
void				njoiner(char **s1, char *s2);

void				printer(char *str, int len);
void				perprinter(t_print *print, t_parg *parg, char c, char cw);
void				cprinter(t_print *print, t_parg *parg, char c, char fc);
void				sprinter(t_print *print, t_parg *parg);

void				pf_free_all(t_print *print, t_parg **parg);
char				chrfiller(t_parg *parg);

#endif
