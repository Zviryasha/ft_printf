/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:46:28 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 11:10:15 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sasio(char *d, char *res, int *a)
{
	char	*pres;
	char	*widt;
	int		okjs[4];

	okjs[0] = check_precision(d);
	okjs[2] = check_width(d);
	pres = ft_strnew(okjs[0] + 1);
	widt = ft_strnew(okjs[2] + 1);
	next2(okjs, pres, widt, d);
	if (res == NULL && (ft_atoi(pres) == 0 && ft_atoi(widt) == 0))
	{
		ft_putstr("(null)");
		return (6);
	}
	if (is_star(d) && res == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	okjs[1] = (int)ft_strlen(res);
	if (ft_atoi(pres) || (is_star(d) && ft_atoi(pres) == 0))
		res = precision_for_string(pres, res);
	okjs[0] = ft_atoi(pres);
	return (sashio(d, okjs, res, widt));
}

int		sashio(char *d, int *okjs, char *res, char *widt)
{
	int		a;
	char	*p;

	okjs[2] = ft_atoi(widt);
	if ((is_dot(d) && no_pres(d)) || (okjs[5] == 1))
	{
		res = ft_strnew(1);
		p = "";
		res = ft_strcpy(res, p);
	}
	if (check_width(d) && okjs[2] > ft_strlen(res))
	{
		if (!(is_minus(d)))
			res = width1(res, widt);
		else
			res = width(res, widt);
	}
	if (is_null(d))
		null(res);
	ft_putstr(res);
	a = (int)ft_strlen(res);
	return (a);
}

char	*precision_for_string(char *s, char *t)
{
	char	*p;
	int		i;
	int		k;
	int		o;

	k = ft_atoi(s);
	o = 0;
	if (k == 0)
		o = 1;
	i = 0;
	p = ft_strnew(k + 1);
	p[k] = '\0';
	while (i < k)
	{
		p[i] = '0';
		i++;
	}
	while (k >= 0)
	{
		p[k - 1] = t[i - 1];
		i--;
		k--;
	}
	return (p);
}
