/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   50cent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:42:37 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/03 17:40:53 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cent(char *d, int *a)
{
	char	*pres;
	char	*widt;
	char	*res;
	int		okjs[4];

	res = "%";
	okjs[0] = check_precision(d);
	okjs[2] = check_width(d);
	pres = ft_strnew(okjs[0] + 1);
	widt = ft_strnew(okjs[2] + 1);
	next2(okjs, pres, widt, d);
	if (is_star(d))
	{
		starix(okjs, a);
		pres = ft_itoa(okjs[0]);
		widt = ft_itoa(okjs[2]);
	}
	okjs[2] = ft_atoi(widt);
	okjs[0] = ft_atoi(pres);
	res = cent_1(res, okjs, widt, d);
	ft_putstr(res);
	a[2] = (int)ft_strlen(res);
	return (a[2]);
}

char	*cent_1(char *res, int *okjs, char *widt, char *d)
{
	if (okjs[0] < okjs[2])
	{
		if (!(is_minus(d)))
			res = width1(res, widt);
		else
			res = width(res, widt);
	}
	if (is_null(d))
		null(res);
	return (res);
}
