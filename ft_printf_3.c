/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:16:29 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:41:43 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*arcaine(int *okjs, char *d, char *res, uintmax_t i)
{
	if (!res || (check_precision(d) == 0) || !(okjs[0]))
		res = ft_itoa_for_printf(i);
	if (i == 0 && is_dot(d) && no_pres(d))
	{
		res = ft_strnew(1);
		res[0] = '\0';
	}
	return (res);
}

int		what_type3(va_list arg, char c, int *a, char *d)
{
	void		*s;
	wchar_t		h;
	wchar_t		*hs;

	if (c == '%')
		a[2] = cent(d, a);
	else if (c == 'p')
	{
		s = va_arg(arg, void *);
		a[2] = pipi(s, d, a);
	}
	else if (c == 'S')
	{
		hs = va_arg(arg, wchar_t *);
		a[2] = big_s(hs, d, a);
	}
	return (a[2]);
}

void	next1(char *d, int *okjs, long long int i)
{
	if ((int)i < 0)
	{
		i = -(unsigned int)i;
		okjs[3] = -1;
	}
	okjs[0] = check_precision(d);
	okjs[2] = check_width(d);
	okjs[1] = ft_strlen(ft_itoa(i));
}

void	next2(int *okjs, char *pres, char *widt, char *d)
{
	check_precision1(d, okjs[0], pres);
	check_width1(d, okjs[2], widt);
}

int		next(char *d, long long int i, char c, int *a)
{
	char	*pres;
	char	*widt;
	char	*res;
	int		okjs[6];

	res = NULL;
	check_type_idd(d, c, &i);
	next1(d, okjs, i);
	pres = ft_strnew(okjs[0] + 1);
	widt = ft_strnew(okjs[2] + 1);
	next2(okjs, pres, widt, d);
	if (is_star(d))
	{
		starix(okjs, a);
		pres = ft_itoa(okjs[0]);
		widt = ft_itoa(okjs[2]);
	}
	if (okjs[1] < ft_atoi(pres))
		res = precision(pres, i, res);
	res = major_1(res, okjs, i, d);
	okjs[2] = ft_atoi(widt);
	okjs[0] = ft_atoi(pres);
	free(pres);
	a[2] = din(okjs, res, d, widt);
	return (a[2]);
}
