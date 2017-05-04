/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 13:55:17 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 11:51:40 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manta(int *okjs, char *d, char *res, char *widt)
{
	if (okjs[0] < okjs[2])
	{
		if (!(is_minus(d)) || okjs[4] == -1)
			res = width1(res, widt);
		else
			res = width(res, widt);
	}
	free(widt);
	return (res);
}

int		onion(char *d, unsigned long long int i, int *a, char c)
{
	char	*pres;
	char	*widt;
	char	*res;
	int		okjs[4];

	check_type_ocu(d, c, &i);
	res = ft_itoa_base(i, 8, d);
	olo(d, okjs, res);
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
		res = precision_olo(pres, res);
	okjs[3] = (int)ft_strlen(res);
	okjs[2] = ft_atoi(widt);
	okjs[0] = ft_atoi(pres);
	free(pres);
	a[2] = print_o(okjs, d, res, widt);
	return (a[2]);
}

void	next_u(char *d, int *okjs, uintmax_t i)
{
	okjs[0] = check_precision(d);
	okjs[2] = check_width(d);
	okjs[1] = ft_strlen(ft_itoa_f(i));
}

int		uio(char *d, unsigned long long int i, char c, int *a)
{
	char	*pres;
	char	*widt;
	char	*res;
	int		okjs[4];

	res = NULL;
	check_type_ocu(d, c, &i);
	next_u(d, okjs, i);
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
	res = arcaine(okjs, d, res, i);
	okjs[2] = ft_atoi(widt);
	okjs[0] = ft_atoi(pres);
	free(pres);
	a[2] = print_u(okjs, d, res, widt);
	return (a[2]);
}

int		what_type2(va_list arg, char c, char *d, int *a)
{
	char		*s;
	uintmax_t	i;

	if (c == 's')
	{
		s = va_arg(arg, char *);
		a[2] = sasio(d, s, a);
	}
	else if (c == 'u' || c == 'U')
	{
		i = va_arg(arg, uintmax_t);
		a[2] = uio(d, i, c, a);
	}
	else
		a[2] = what_type3(arg, c, a, d);
	return (a[2]);
}
